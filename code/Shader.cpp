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
	CompileShader();
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
