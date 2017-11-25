#pragma once
#include "oglin.h"
#include "vec4.h"

struct mat4 {
	vec4 m[4];

	mat4(GLfloat val = 0.f);
	mat4(vec4 c0, vec4 c1, vec4 c2, vec4 c3);
	mat4(
		GLfloat x0, GLfloat x1, GLfloat x2, GLfloat x3,
		GLfloat y0, GLfloat y1, GLfloat y2, GLfloat y3,
		GLfloat z0, GLfloat z1, GLfloat z2, GLfloat z3,
		GLfloat w0, GLfloat w1, GLfloat w2, GLfloat w3);
	void initTranslation(vec3 &t_);

	mat4 transpose();

	mat4  operator* (mat4 &fctr_2);
	vec4& operator[] (int i);
 };