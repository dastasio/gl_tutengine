#include "Game.h"
#include "Input.h"
#include <iostream>
#include "vec3.h"
#include "ResourceLoader.h"

Game::Game() {
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	mesh = new Mesh();
	shader = new Shader();

	Vertex data[] = {
		Vertex(vec3(-1.f, -1.f, 0.f)),
		Vertex(vec3( 1.f, -1.f, 0.f)),
		Vertex(vec3( 0.f,  1.f, 0.f))
	};

	mesh->AddVertices(data, 3);
	shader->AddVertexShader(ResourceLoader::loadShader("basic.vs"));
	shader->AddFragmentShader(ResourceLoader::loadShader("basic.fs"));
}

void Game::input() {
	if (Input::getKeyDown(SDL_SCANCODE_UP))
		std::cout << "Pressed UP" << std::endl;
	if (Input::getKeyUp(SDL_SCANCODE_UP))
		std::cout << "Released UP" << std::endl;
	
	if (Input::getMouseDown(SDL_BUTTON_LEFT))
		std::cout << "Pressed LBUTTON at " << Input::getMousePosition().toString() << std::endl;
	if (Input::getMouseUp(SDL_BUTTON_LEFT))
		std::cout << "Released LBUTTON" << std::endl;
}

void Game::update() {

}

void Game::render() {
	shader->bind();
	mesh->Draw();
}