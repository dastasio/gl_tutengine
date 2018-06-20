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

	mesh = ResourceLoader::loadMesh("cube.obj");
	shader = new Shader();

	
	shader->AddVertexShader(ResourceLoader::loadShader("basic.vs"));
	shader->AddFragmentShader(ResourceLoader::loadShader("basic.fs"));
	shader->CompileShader();
	shader->bind();

	shader->AddUniform("transform");
	Transform::setProjection(45.f, 1280, 720, 0.1f, 100.f);
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

	tran.setPosition(0, 0, 5);
	tran.setRotation(0, 180 * std::sinf(tmp), 0);
	//tran.setScale(std::sinf(tmp));
}

void Game::render() {
	shader->SetUniform("transform", tran.getProjectedTransform());
	shader->bind();
	mesh->Draw();
}