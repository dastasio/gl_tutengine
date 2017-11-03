#include "Game.h"
#include "Input.h"
#include <iostream>
#include "vec3.h"

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
}