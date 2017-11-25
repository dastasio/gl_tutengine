#include "Transform.h"

Transform::Transform() {
	translation = vec3(0.f);
}

void Transform::setPosition(vec3 p_) {
	translation = p_;
}

void Transform::setPosition(GLfloat x, GLfloat y, GLfloat z) {
	translation = vec3(x, y, z);
}

void Transform::translate(vec3 t_) {
	translation += t_;
}

void Transform::translate(GLfloat x, GLfloat y, GLfloat z) {
	translation += vec3(x, y, z);
}

mat4 Transform::getTransform() {
	mat4 t;
	t.initTranslation(translation);

	return t;
}
