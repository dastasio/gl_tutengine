#include "mat4.h"

mat4::mat4(GLfloat val) {
	m[0] = vec4(val, 0.f, 0.f, 0.f);
	m[1] = vec4(0.f, val, 0.f, 0.f);
	m[2] = vec4(0.f, 0.f, val, 0.f);
	m[3] = vec4(0.f, 0.f, 0.f, val);
}

mat4::mat4(vec4 c0, vec4 c1, vec4 c2, vec4 c3) {
	m[0] = c0;
	m[1] = c1;
	m[2] = c2;
	m[3] = c3;
}

mat4::mat4(
	GLfloat x0, GLfloat x1, GLfloat x2, GLfloat x3,
	GLfloat y0, GLfloat y1, GLfloat y2, GLfloat y3,
	GLfloat z0, GLfloat z1, GLfloat z2, GLfloat z3,
	GLfloat w0, GLfloat w1, GLfloat w2, GLfloat w3) {
	m[0] = vec4(x0, y0, z0, w0);
	m[1] = vec4(x1, y1, z1, w1);
	m[2] = vec4(x2, y2, z2, w2);
	m[3] = vec4(x3, y3, z3, w3);
}

vec4& mat4::operator[] (int i) {
	return m[i];
}

mat4 mat4::transpose() {
	return mat4(
		m[0][0], m[1][0], m[2][0], m[3][0],
		m[0][1], m[1][1], m[2][1], m[3][1],
		m[0][2], m[1][2], m[2][2], m[3][2],
		m[0][3], m[1][3], m[2][3], m[3][3]
	);
}

mat4 mat4::operator* (mat4 &fctr_2) {
	mat4 fctr_1 = this->transpose();
	mat4 product(0.f);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			product[i][j] = fctr_1[j].dot(fctr_2[i]);
		}
	}

	return product;
}