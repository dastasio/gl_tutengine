#include "Input.h"
#include "Window.h"
#include <algorithm>

std::vector<int> Input::downKeys;
std::vector<int> Input::downMouse;
std::vector<int> Input::upKeys;
std::vector<int> Input::upMouse;

bool Input::getKey(int keyCode) {
	static const Uint8* keystates = SDL_GetKeyboardState(nullptr);
	return keystates[keyCode];
}

bool Input::getKeyDown(int keyCode) {
	return std::find(downKeys.begin(), downKeys.end(), keyCode) != downKeys.end() ? true : false;
}

bool Input::getKeyUp(int keyCode) {
	return std::find(upKeys.begin(), upKeys.end(), keyCode) != upKeys.end() ? true : false;
}

vec2 Input::getMousePosition() {
	int *x = new int;
	int *y = new int;
	SDL_GetMouseState(x, y);
	return vec2(*x, *y);
}

bool Input::getMouseDown(int button) {
	return std::find(downMouse.begin(), downMouse.end(), button) != downMouse.end() ? true : false;
}

bool Input::getMouseUp(int button) {
	return std::find(upMouse.begin(), upMouse.end(), button) != upMouse.end() ? true : false;
}

void Input::update() {
	upKeys.clear();
	upMouse.clear();
	downKeys.clear();
	downMouse.clear();

	static SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT)
			Window::setCloseRequest();

		if (e.type == SDL_KEYDOWN)
			downKeys.push_back(e.key.keysym.scancode);
		if (e.type == SDL_KEYUP)
			upKeys.push_back(e.key.keysym.scancode);

		if (e.type == SDL_MOUSEBUTTONDOWN)
			downMouse.push_back(e.button.button);
		if (e.type == SDL_MOUSEBUTTONUP)
			upMouse.push_back(e.button.button);
	}
}