#include "Game.h"
#include "Input.h"
#include <iostream>

void Game::input() {
	if (Input::getKeyDown(SDL_SCANCODE_UP))
		std::cout << "Pressed UP" << std::endl;
	if (Input::getKeyUp(SDL_SCANCODE_UP))
		std::cout << "Released UP" << std::endl;
}

void Game::update() {

}

void Game::render() {
	
}