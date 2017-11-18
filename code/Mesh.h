#pragma once
#include "oglin.h"
#include "Vertex.h"

class Mesh {
public:
	Mesh() {
		GLuint tmp;
		glGenBuffers(1, &tmp);
		vbo = tmp;
	}

	void AddVertices(Vertex *verts, int num);
	void Draw();

private:
	GLuint vbo;
	GLint size;
};