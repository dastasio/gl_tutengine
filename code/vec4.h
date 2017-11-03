#pragma once
#include "oglin.h"
#include "vec3.h"

struct vec4 {
	GLfloat x, y, z, w;

	vec4() :
		x(0.f), y(0.f), z(0.f), w(0.f) {}
	vec4(GLfloat val) :
		x(val), y(val), z(val), w(val) {}
	vec4(GLfloat x_, GLfloat y_, GLfloat z_, GLfloat w_) :
		x(x_), y(y_), z(z_), w(w_) {}
	vec4(vec4 &v) :
		x(v.x), y(v.y), z(v.z), w(v.w) {}
	vec4(vec3 v, GLfloat w_) :
		x(v.x), y(v.y), z(v.z), w(w_) {}
	vec4(vec2 v0, vec2 v1) :
		x(v0.x), y(v0.y), z(v1.x), w(v1.y) {}
	vec4(vec2 v, GLfloat z_, GLfloat w_) :
		x(v.x), y(v.y), z(z_), w(w_) {}

	GLfloat length();
	GLfloat dot(vec4 v);
	vec4    cross(vec4 v);
	vec4    normalize();
	vec4    conjugate();
	vec4    rotate(double angle);

	vec4    operator+  (vec4 v);
	vec4    operator+  (GLfloat val);
	vec4    operator-  (vec4 v);
	vec4    operator-  (GLfloat val);
	vec4    operator*  (vec4 v);
	vec4    operator*  (vec3 v);
	vec4    operator*  (GLfloat val);
	vec4    operator/  (GLfloat val);
	void    operator+= (vec4 v);
	void    operator+= (GLfloat val);
	void    operator-= (vec4 v);
	void    operator-= (GLfloat val);
	void    operator*= (GLfloat val);
	void    operator/= (GLfloat val);
	GLfloat&operator[] (int i);
};