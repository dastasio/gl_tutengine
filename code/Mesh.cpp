#include "Mesh.h"

void Mesh::AddVertices(Vertex * verts, int num) {
	size = num;

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * size * Vertex::SIZE, verts[0].getPtr(), GL_STATIC_DRAW);
}

void Mesh::Draw() {
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, size);

	glDisableVertexAttribArray(0);
}