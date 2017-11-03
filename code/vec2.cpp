#include "vec2.h"
#include <cmath>

const double RADIANS = 180.f / M_PI;

std::string vec2::toString() {
	std::string str = "(";
	str += std::to_string(x) + ", " + std::to_string(y) + ")";
	return str;
}

GLfloat vec2::length() {
	return std::sqrtf(x*x + y*y);
}

GLfloat vec2::dot(vec2 v) {
	return *this * v;
}

vec2 vec2::normalize() {
	GLfloat l = length();

	*this /= l;
	return *this;
}

vec2 vec2::rotate(double angle) {
	double rad = RADIANS * angle;
	double cos = std::cos(rad);
	double sin = std::sin(rad);

	return vec2(x * cos - y * sin, x * sin + y * cos);
}

vec2 vec2::operator+ (vec2 v) {
	return vec2(x + v.x, y + v.y);
}
vec2 vec2::operator+ (GLfloat val) {
	return vec2(x + val, y + val);
}
vec2 vec2::operator- (vec2 v) {
	return vec2(x - v.x, y - v.y);
}
vec2 vec2::operator- (GLfloat val) {
	return vec2(x - val, y - val);
}
GLfloat vec2::operator* (vec2 v) {
	return x * v.x + y * v.y;
}
vec2 vec2::operator* (GLfloat val) {
	return vec2(x * val, y * val);
}
vec2 vec2::operator/ (GLfloat val) {
	return vec2(x / val, y / val);
}

void vec2::operator+= (vec2 v) {
	x += v.x;
	y += v.y;
}
void vec2::operator+= (GLfloat val) {
	x += val;
	y += val;
}
void vec2::operator-= (vec2 v) {
	x -= v.x;
	y -= v.y;
}
void vec2::operator-= (GLfloat val) {
	x -= val;
	y -= val;
}
void vec2::operator*= (GLfloat val) {
	x *= val;
	y *= val;
}
void vec2::operator/= (GLfloat val) {
	x /= val;
	y /= val;
}

GLfloat& vec2::operator[] (int i) {
	return *((GLfloat*)(this) + i);
}