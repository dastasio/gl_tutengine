#pragma once
#include <SDL.h>
#include <vector>

class Input {
public: 
	static bool getKey(int keyCode);
	static bool getKeyDown(int keyCode);
	static bool getKeyUp(int keyCode);

	static void update();

	static const int NUM_KEYCODES = 285;
private:
	static std::vector<int> currentKeys;
	static std::vector<int> downKeys;
	static std::vector<int> upKeys;
};