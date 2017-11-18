#pragma once
#include "vectors.h"

struct Vertex {
	vec3 pos;
	Vertex(vec3 p_) : pos(p_) {}

	GLfloat* getPtr() {
		return &pos.x;
	}

	static const int SIZE = 3;
};