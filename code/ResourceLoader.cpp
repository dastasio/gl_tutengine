#include "ResourceLoader.h"
#include "CommonUtils.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using std::string;

enum OBJlineID {
	OBJ_LINE_NULL,
	OBJ_LINE_V,
	OBJ_LINE_F
};

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

Mesh * ResourceLoader::loadMesh(string filename) {
	auto ext = getFilenameExtension(filename);

	if (ext != "obj") {
		std::cerr << "[ERROR] File format not supported for mesh data: " << ext << std::endl;
		exit(EXIT_FAILURE);
	}
	
	filename = "./res/models/" + filename;
	std::ifstream file(filename, std::ios::in);
	if (!file.good()) {
		std::cerr << "[ERROR] Could not open " << filename << std::endl;
		exit(EXIT_FAILURE);
	}

	file.seekg(0, std::ios::end);
	unsigned int l = file.tellg();
	char* source = new char[1024];

	file.seekg(0, std::ios::beg);
	file.read(source, 1024);
	l = file.gcount();
	std::istringstream rawData(source);

	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	for (string line; std::getline(rawData, line);) {
		std::istringstream linestream;
		linestream.str(line);

		if (!line.empty()) {
			static OBJlineID line_id = OBJ_LINE_NULL;
			static char token[10];

			while (linestream.getline(token, 10, ' ')) {
				if (token[0] == 'v') {
					line_id = OBJ_LINE_V;
					continue;
				}
				else if (token[0] == 'f') {
					line_id = OBJ_LINE_F;
					continue;
				}
				else if (line_id == OBJ_LINE_NULL){
					// line is ignored
					break;
				}

				switch (line_id) {
				case OBJ_LINE_NULL:
					break;
				case OBJ_LINE_V:
					vertices.push_back(std::stod(token));
					break;
				case OBJ_LINE_F:
					indices.push_back(std::stoi(token) - 1);
					break;
				}
			}
			line_id = OBJ_LINE_NULL;
		}
	}

	Mesh *m = new Mesh();
	m->AddVertices(vertices, indices);
	return m;
}
