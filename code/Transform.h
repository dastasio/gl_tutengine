#pragma once
#include "vectors.h"
#include "mat4.h"

class Transform {
public:
	Transform();

	void setPosition(vec3 p_);
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	void translate(vec3 t_);
	void translate(GLfloat x, GLfloat y, GLfloat z);

	mat4 getTransform();
private:
	vec3 translation;
};