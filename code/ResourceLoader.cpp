#include "ResourceLoader.h"
#include <fstream>
#include <iostream>

using std::string;

string ResourceLoader::loadShader(string path) {
	string shaderSource;

	path = "./res/shaders/" + path;
	std::ifstream file(path, std::ios::in);
	if (!file.good()) {
		std::cerr << "[ERROR] Could not open " << path << std::endl;
		exit(EXIT_FAILURE);
	}

	file.seekg(0, std::ios::end);
	unsigned int l = file.tellg();
	char* source = new char[1024];

	file.seekg(0, std::ios::beg);
	file.read(source, 1024);
	l = file.gcount();
	shaderSource = source;
	if (shaderSource.size() > l) shaderSource.resize(l);
	return shaderSource;
}