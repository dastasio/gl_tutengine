#include "vec4.h"
#include <cmath>

GLfloat vec4::length() {
	return std::sqrtf(x*x + y*y + z*z + w*w);
}

GLfloat vec4::dot(vec4 v) {
	return x*v.x + y*v.y + z*v.z + w*v.w;
}

vec4 vec4::cross(vec4 v) {
	GLfloat w_ = w * v.w - x * v.x - y * v.y - z * v.z;
	GLfloat x_ = x * v.w + w * v.x + y * v.z - z * v.y;
	GLfloat y_ = y * v.w + w * v.y + z * v.x - x * v.z;
	GLfloat z_ = z * v.w + w * v.z + x * v.y - y * v.x;

	return vec4(x_, y_, z_, w_);
}

vec4 vec4::normalize() {
	GLfloat l = length();

	*this /= l;
	return *this;
}

vec4 vec4::conjugate() {
	return vec4(-x, -y, -z, w);
}

vec4 vec4::operator+ (vec4 v) {
	return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
}
vec4 vec4::operator+ (GLfloat val) {
	return vec4(x + val, y + val, z + val, w + val);
}
vec4 vec4::operator- (vec4 v) {
	return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
}
vec4 vec4::operator- (GLfloat val) {
	return vec4(x - val, y - val, z - val, w - val);
}
vec4 vec4::operator* (vec4 v) {
	GLfloat w_ = w * v.w - x * v.x - y * v.y - z * v.z;
	GLfloat x_ = x * v.w + w * v.x + y * v.z - z * v.y;
	GLfloat y_ = y * v.w + w * v.y + z * v.x - x * v.z;
	GLfloat z_ = z * v.w + w * v.z + x * v.y - y * v.x;

	return vec4(x_, y_, z_, w_);
}
vec4 vec4::operator* (vec3 v) {
	GLfloat w_ = -x * v.x - y * v.y - z * v.z;
	GLfloat x_ =  w * v.x + y * v.z - z * v.y;
	GLfloat y_ =  w * v.y + z * v.x - x * v.z;
	GLfloat z_ =  w * v.z + x * v.y - y * v.x;

	return vec4(x_, y_, z_, w_);
}
vec4 vec4::operator* (GLfloat val) {
	return vec4(x * val, y * val, z * val, w * val);
}
vec4 vec4::operator/ (GLfloat val) {
	return vec4(x / val, y / val, z / val, w / val);
}

void vec4::operator+= (vec4 v) {
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
}
void vec4::operator+= (GLfloat val) {
	x += val;
	y += val;
	z += val;
	w += val;
}
void vec4::operator-= (vec4 v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
}
void vec4::operator-= (GLfloat val) {
	x -= val;
	y -= val;
	z -= val;
	w -= val;
}
void vec4::operator*= (GLfloat val) {
	x *= val;
	y *= val;
	z *= val;
	w *= val;
}
void vec4::operator/= (GLfloat val) {
	x /= val;
	y /= val;
	z /= val;
	w /= val;
}

GLfloat& vec4::operator[] (int i) {
	return *((GLfloat*)(this) + i);
}