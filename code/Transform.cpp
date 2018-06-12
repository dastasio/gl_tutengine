#include "Transform.h"

Transform::Transform() {
	translation = vec3(0.f);
	rotation = vec3(0.f);
	scale = vec3(1.f);
}

void Transform::setPosition(vec3 p_) {
	translation = p_;
}

void Transform::setPosition(GLfloat x, GLfloat y, GLfloat z) {
	translation = vec3(x, y, z);
}

void Transform::setRotation(vec3 r_) {
	rotation = r_;
}

void Transform::setRotation(GLfloat x, GLfloat y, GLfloat z) {
	rotation = vec3(x, y, z);
}

void Transform::setScale(vec3 s_) {
	scale = s_;
}

void Transform::setScale(GLfloat x, GLfloat y, GLfloat z) {
	scale = vec3(x, y, z);
}

void Transform::translate(vec3 t_) {
	translation += t_;
}

void Transform::translate(GLfloat x, GLfloat y, GLfloat z) {
	translation += vec3(x, y, z);
}

void Transform::rotate(vec3 r_) {
	rotation += r_;
}

void Transform::rotate(GLfloat x, GLfloat y, GLfloat z) {
	rotation += vec3(x, y, z);
}

void Transform::resize(vec3 s_) {
	scale += s_;
}

void Transform::resize(GLfloat x, GLfloat y, GLfloat z) {
	scale += vec3(x, y, z);
}

mat4 Transform::getTransform() {
	mat4 t, r, s;
	t.initTranslation(translation);
	r.initRotation(rotation);
	s.initScale(scale);

	return t * r * s;// s * r * t;
}
