#include "vec3.h"
#include <cmath>

GLfloat vec3::length() {
	return std::sqrtf(x*x + y*y + z*z);
}

GLfloat vec3::dot(vec3 v) {
	return *this * v;
}

vec3 vec3::cross(vec3 v) {
	GLfloat x_ = y * v.z - z * v.y;
	GLfloat y_ = z * v.x - x * v.z;
	GLfloat z_ = x * v.y - y * v.x;

	return vec3(x_, y_, z_);
}

vec3 vec3::normalize() {
	GLfloat l = length();

	*this /= l;
	return *this;
}

vec3 vec3::operator+ (vec3 v) {
	return vec3(x + v.x, y + v.y, z + v.z);
}  
vec3 vec3::operator+ (GLfloat val) {
	return vec3(x + val, y + val, z + val);
}  
vec3 vec3::operator- (vec3 v) {
	return vec3(x - v.x, y - v.y, z - v.z);
}  
vec3 vec3::operator- (GLfloat val) {
	return vec3(x - val, y - val, z - val);
}  
GLfloat vec3::operator* (vec3 v) {
	return x * v.x + y * v.y + z * v.z;
}  
vec3 vec3::operator* (GLfloat val) {
	return vec3(x * val, y * val, z * val);
}  
vec3 vec3::operator/ (GLfloat val) {
	return vec3(x / val, y / val, z / val);
}

void vec3::operator+= (vec3 v) {
	x += v.x;
	y += v.y;
	z += v.z;
}
void vec3::operator+= (GLfloat val) {
	x += val;
	y += val;
	z += val;
}
void vec3::operator-= (vec3 v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}
void vec3::operator-= (GLfloat val) {
	x -= val;
	y -= val;
	z -= val;
}
void vec3::operator*= (GLfloat val) {
	x *= val;
	y *= val;
	z *= val;
}
void vec3::operator/= (GLfloat val) {
	x /= val;
	y /= val;
	z /= val;
}

GLfloat& vec3::operator[] (int i) {
	return *((GLfloat*)(this) + i);
}