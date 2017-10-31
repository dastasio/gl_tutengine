#pragma once
#include <SDL.h>
#include <vector>
#include "vec2.h"

class Input {
public: 
	static bool getKey(int keyCode);
	static bool getKeyDown(int keyCode);
	static bool getKeyUp(int keyCode);
	static bool getMouseDown(int button);
	static bool getMouseUp(int button);
	static vec2 getMousePosition();

	static void update();
private:
	static std::vector<int> downKeys;
	static std::vector<int> downMouse;
	static std::vector<int> upKeys;
	static std::vector<int> upMouse;
};