#include "Game.h"
#include "Input.h"
#include <iostream>
#include "vec3.h"
#include "ResourceLoader.h"
#include "Time.h"
#include <cmath>

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
	shader->CompileShader();
	shader->bind();

	shader->AddUniform("transform");
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
	static float tmp = 0.f;
	tmp += Time::getDelta();

	tran.setPosition(std::sinf(tmp), 0, 0);
}

void Game::render() {
	shader->SetUniform("transform", tran.getTransform());
	shader->bind();
	mesh->Draw();
}