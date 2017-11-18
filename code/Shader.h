#pragma once
#include "oglin.h"
#include <string>

class Shader {
public:
	Shader();

	void AddVertexShader(std::string src);
	void AddGeometryShader(std::string src);
	void AddFragmentShader(std::string src);
	void bind() {
		glUseProgram(program);
	}
private:
	GLuint program;

	void AddShader(std::string src, GLenum type);
	void CompileShader();
};