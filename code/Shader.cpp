#include "Shader.h"
#include <iostream>

Shader::Shader() {
	program = glCreateProgram();

	if (program == 0) {
		std::cerr << "[ERROR] Could not create shader!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Shader::AddVertexShader(std::string src) {
	AddShader(src, GL_VERTEX_SHADER);
}

void Shader::AddGeometryShader(std::string src) {
	AddShader(src, GL_GEOMETRY_SHADER);
}

void Shader::AddFragmentShader(std::string src) {
	AddShader(src, GL_FRAGMENT_SHADER);
}

void Shader::AddUniform(std::string unif) {
	GLint unifLocation = glGetUniformLocation(program, unif.c_str());

	if (unifLocation == -1) {
		std::cerr << "[ERROR] Could not find uniform variable '" << unif << "'" << std::endl;
	}

	uniforms[unif] = unifLocation;
}

void Shader::SetUniformi(std::string uName, GLint val) {
	glUniform1i(uniforms[uName], val);
}

void Shader::SetUniformf(std::string uName, GLfloat val) {
	glUniform1f(uniforms[uName], val);
}

void Shader::SetUniform(std::string uName, vec3 &val) {
	glUniform1fv(uniforms[uName], 1, &val[0]);
}

void Shader::SetUniform(std::string uName, mat4 &val) {
	glUniformMatrix4fv(uniforms[uName], 1, GL_FALSE, &val[0][0]);
}

void Shader::AddShader(std::string src, GLenum type) {
	GLint shader = glCreateShader(type);

	if (shader == 0) {
		std::cerr << "[ERROR] Could not create shader of type " << type << std::endl;
		exit(EXIT_FAILURE);
	}

	const GLchar* source = src.c_str();
	glShaderSource(shader, 1, &source, 0);
	glCompileShader(shader);

	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		std::cerr << "[ERROR] Could not compile shader of type " << type << std::endl;
		int len;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
		GLchar* log = new GLchar[len];
		glGetShaderInfoLog(shader, len, 0, log);
		std::cerr << log << std::endl;
		exit(EXIT_FAILURE);
	}

	glAttachShader(program, shader);
}

void Shader::CompileShader() {
	glLinkProgram(program);

	int success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		std::cerr << "[ERROR] Could not link program" << std::endl;
		int len;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
		GLchar* log = new GLchar[len];
		glGetProgramInfoLog(program, len, 0, log);
		std::cerr << log << std::endl;
		exit(EXIT_FAILURE);
	}
}
