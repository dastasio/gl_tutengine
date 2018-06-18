#pragma once
#include "oglin.h"
#include "Vertex.h"
#include <vector>

class Mesh {
public:
	Mesh() {
		glGenBuffers(2, bo);
	}

	void AddVertices(GLfloat *verts, size_t n_v, GLuint *indices, size_t n_i);
	void AddVertices(std::vector<GLfloat> verts, std::vector<GLuint> indices);
	void Draw();

private:
	GLuint bo[2];
	GLint size;

	static const int MESH_VBO = 0;
	static const int MESH_IBO = 1;
};