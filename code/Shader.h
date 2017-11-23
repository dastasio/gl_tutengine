#pragma once
#include "oglin.h"
#include <string>
#include <map>
#include "vectors.h"
#include "mat4.h"

class Shader {
public:
	Shader();

	void AddVertexShader(std::string src);
	void AddGeometryShader(std::string src);
	void AddFragmentShader(std::string src);
	void CompileShader();
	void AddUniform(std::string unif);
	void bind() {
		glUseProgram(program);
	}

	void SetUniformi(std::string uName, GLint val);
	void SetUniformf(std::string uName, GLfloat val);
	void SetUniform(std::string uName, vec3 &val);
	void SetUniform(std::string uName, mat4 &val);
private:
	GLuint program;
	std::map<std::string, GLint> uniforms;

	void AddShader(std::string src, GLenum type);
};