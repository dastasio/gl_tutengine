#pragma once
#include <glad\glad.h>
#include <SDL.h>

class Window {
public:
	static Window &NewWindow(int width, int height, const char* title);

	static void render() {
		SDL_GL_SwapWindow(window_ptr);
	}

	static bool isCloseRequested();
	static int getWidth();
	static int getHeight();
private:
	Window(int w, int h, const char* t);
	void InitSDL();

	// data
	static SDL_Window *window_ptr;
	static SDL_GLContext context;
};