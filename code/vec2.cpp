#include "vec2.h"

std::string vec2::toString() {
	std::string str = "(";
	str += std::to_string(x) + ", " + std::to_string(y) + ")";
	return str;
}