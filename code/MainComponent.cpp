#define SDL_MAIN_HANDLED
#include "Window.h"

namespace MainComponent {
	void cleanUp() {

	}

	void render() {
		Window::render();
	}

	void run() {
		while (!Window::isCloseRequested())
			render();
	}

	void stop() {

	}

	void start() {
		run();
	}
}

int main() {
	SDL_SetMainReady();
	Window::NewWindow(1024, 720, "GL engine");

	MainComponent::start();

	return 0;
}