#include "Input.h"
#include <algorithm>

std::vector<int> Input::currentKeys;
std::vector<int> Input::downKeys;
std::vector<int> Input::upKeys;

bool Input::getKey(int keyCode) {
	static const Uint8* keystates = SDL_GetKeyboardState(nullptr);
	return keystates[keyCode];
}

bool Input::getKeyDown(int keyCode) {
	if (std::find(downKeys.begin(), downKeys.end(), keyCode) != downKeys.end())
		return true;
	return false;
}

bool Input::getKeyUp(int keyCode) {
	if (std::find(upKeys.begin(), upKeys.end(), keyCode) != upKeys.end())
		return true;
	return false;
}

void Input::update() {
	upKeys.clear();
	downKeys.clear();

	for (int i = 0; i < NUM_KEYCODES; i++) {
		if (getKey(i) && 
			std::find(currentKeys.begin(), currentKeys.end(), i) == currentKeys.end())
			downKeys.push_back(i);
		if (!getKey(i) &&
			std::find(currentKeys.begin(), currentKeys.end(), i) != currentKeys.end())
			upKeys.push_back(i);
	}

	currentKeys.clear();

	for (int i = 0; i < NUM_KEYCODES; i++) {
		if (getKey(i)) currentKeys.push_back(i);
	}
}