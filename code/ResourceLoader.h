#pragma once
#include <string>
#include "Mesh.h"

class ResourceLoader {
public:
	static std::string loadShader(std::string path);

	static Mesh * loadMesh(std::string filename);
};