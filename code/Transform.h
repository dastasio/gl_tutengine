#pragma once
#include "vectors.h"
#include "mat4.h"

class Transform {
public:
	Transform();

	static void setProjection(float fov_,
							  float w_,  float h_, 
							  float zn_, float zf_);

	void setPosition(vec3 p_);
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	void setRotation(vec3 r_);
	void setRotation(GLfloat x, GLfloat y, GLfloat z);
	void setScale(vec3 s_);
	void setScale(GLfloat x, GLfloat y, GLfloat z);
	void translate(vec3 t_);
	void translate(GLfloat x, GLfloat y, GLfloat z);
	void rotate(vec3 r_);
	void rotate(GLfloat x, GLfloat y, GLfloat z);
	void resize(vec3 s_);
	void resize(GLfloat x, GLfloat y, GLfloat z);

	mat4 getTransform();
	mat4 getProjectedTransform();
private:
	vec3 translation;
	vec3 rotation;
	vec3 scale;
	static mat4 projection;
};