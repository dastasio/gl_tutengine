#pragma once
#include "oglin.h"
#include <string>

struct vec2 {
	GLfloat x, y;

	vec2(GLfloat val) :
		x(val), y(val) {}
	vec2(GLfloat x, GLfloat y) :
		x(x), y(y) {}
	vec2(vec2 &v) :
		x(v.x), y(v.y) {}

	std::string toString();
};