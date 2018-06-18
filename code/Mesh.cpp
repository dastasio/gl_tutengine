#include "Mesh.h"

void Mesh::AddVertices(GLfloat * verts, size_t n_v, GLuint * indices, size_t n_i) {
	size = n_i;

	glBindBuffer(GL_ARRAY_BUFFER, bo[MESH_VBO]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * n_v, verts, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo[MESH_IBO]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLint) * n_i, indices, GL_STATIC_DRAW);
}

void Mesh::AddVertices(std::vector<GLfloat> verts, std::vector<GLuint> indices) {
	AddVertices(verts.data(), verts.size(), indices.data(), indices.size());
}

void Mesh::Draw() {
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, bo[MESH_VBO]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bo[MESH_IBO]);
	glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
}