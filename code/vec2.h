#pragma once
#include "oglin.h"
#include <string>
#define M_PI 3.14159265358979323846

struct vec2 {
	GLfloat x, y;

	vec2() :
		x(0.f), y(0.f) {}
	vec2(GLfloat val) :
		x(val), y(val) {}
	vec2(GLfloat x_, GLfloat y_) :
		x(x_), y(y_) {}
	vec2(vec2 &v) :
		x(v.x), y(v.y) {}

	std::string toString();
	
	GLfloat length();
	GLfloat dot(vec2 v);
	vec2 normalize();
	vec2 rotate(double angle);

	vec2    operator+  (vec2 v);
	vec2    operator+  (GLfloat val);
	vec2    operator-  (vec2 v);
	vec2    operator-  (GLfloat val);
	GLfloat operator*  (vec2 v);
	vec2    operator*  (GLfloat val);
	vec2    operator/  (GLfloat val);
	void	operator+= (vec2 v);
	void    operator+= (GLfloat val);
	void    operator-= (vec2 v);
	void    operator-= (GLfloat val);
	void    operator*= (GLfloat val);
	void    operator/= (GLfloat val);
	GLfloat&operator[] (int i);
};