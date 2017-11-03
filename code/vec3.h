#pragma once
#include "oglin.h"
#include "vec2.h"
struct vec3 {
	GLfloat x, y, z;

	vec3() :
		x(0.f), y(0.f), z(0.f) {}
	vec3(GLfloat val) :
		x(val), y(val), z(val) {}
	vec3(GLfloat x_, GLfloat y_, GLfloat z_) :
		x(x_), y(y_), z(z_) {}
	vec3(vec3 &v) :
		x(v.x), y(v.y), z(v.z) {}
	vec3(vec2 v, GLfloat z_) :
		x(v.x), y(v.y), z(z_) {}

	GLfloat length();
	GLfloat dot(vec3 v);
	vec3	cross(vec3 v);
	vec3	normalize();
	vec3	rotate(double angle);

	vec3    operator+  (vec3 v);
	vec3    operator+  (GLfloat val);
	vec3    operator-  (vec3 v);
	vec3    operator-  (GLfloat val);
	GLfloat operator*  (vec3 v);
	vec3    operator*  (GLfloat val);
	vec3    operator/  (GLfloat val);
	void	operator+= (vec3 v);
	void    operator+= (GLfloat val);
	void    operator-= (vec3 v);
	void    operator-= (GLfloat val);
	void    operator*= (GLfloat val);
	void    operator/= (GLfloat val);
	GLfloat&operator[] (int i);
};