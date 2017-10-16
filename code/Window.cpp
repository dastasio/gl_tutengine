#include "Window.h"
#include <SDL_image.h>
#include <iostream>

SDL_Window *Window::window_ptr;
SDL_GLContext Window::context;

Window& Window::NewWindow(int width, int height, const char* title) {
	static Window *instance = new Window(width, height, title);
	return *instance;
}

Window::Window(int w, int h, const char* t) {
	// starting up SDL
	InitSDL();
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// opening window
	window_ptr = SDL_CreateWindow(t, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (window_ptr == nullptr) {
		std::cerr << "[ERROR] Could not create Window:\n" << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	// setting OpenGL context
	context = SDL_GL_CreateContext(window_ptr);
	if (context == NULL) {
		std::cerr << "[ERROR] Could not create OpenGL Context:\n" << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}
	else {
		SDL_GL_MakeCurrent(window_ptr, context);

		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
			std::cerr << "[ERROR] Could not initialize glad!" << std::endl;
			exit(EXIT_FAILURE);
		}

		glViewport(0, 0, w, h);
	}
}

/* Func: InitSDL
* --------------------------------------
* initializes SDL2 and SDL_image and reports eventual errors
*/
void Window::InitSDL() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "[ERROR] Could not initialize SDL:\n" << SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	int flags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (!(IMG_Init(flags)) & flags) {
		std::cerr << "[ERROR] Could not initialize SDL_image:\n" << IMG_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}
}


/* GETTERS */
bool Window::isCloseRequested() {
	static SDL_Event e;
	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT) return true;
	return false;
}

int Window::getWidth() {
	int *w;
	SDL_GetWindowSize(window_ptr, w, nullptr);
	return *w;
}

int Window::getHeight() {
	int *h;
	SDL_GetWindowSize(window_ptr, nullptr, h);
	return *h;
}