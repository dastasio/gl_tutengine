#pragma once
#include "Mesh.h"
#include "Shader.h"

class Game {
public:
	Game();

	void input();
	void update();
	void render();

private:
	Mesh *mesh;
	Shader *shader;
};