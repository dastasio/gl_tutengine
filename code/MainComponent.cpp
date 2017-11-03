#define SDL_MAIN_HANDLED
#include "Window.h"
#include "Time.h"
#include "Game.h"
#include "Input.h"
#include "RenderUtils.h"
#include <iostream>

namespace MainComponent
{
	const double FRAME_CAP = 5000.0;

	bool isRunning = false;
	Game game;

	void start();
	void stop();
	void run();
	void render();
	void cleanUp();
}

void MainComponent::start()
	{
		if (isRunning)
			return;

		rutils::initGraphics();
		run();
	}

void MainComponent::stop() {
		if (!isRunning)
			return;

		isRunning = false;
	}

void MainComponent::run()
	{
		isRunning = true;

		int frames = 0;
		long frameCounter = 0;

		const double frameTime = 1.0 / FRAME_CAP;

		long lastTime = Time::getTime();
		double unprocessedTime = 0.0;

		while (isRunning) {
			bool shouldRender = false;

			long startTime = Time::getTime();
			long passedTime = startTime - lastTime;
			lastTime = startTime;

			unprocessedTime += passedTime / (double)Time::SECOND;
			frameCounter += passedTime;

			while (unprocessedTime > frameTime) {
				shouldRender = true;
				unprocessedTime -= frameTime;

				if (Window::isCloseRequested())
					stop();


				Time::setDelta(frameTime);
				Input::update();

				game.input();
				game.update();

				if (frameCounter >= Time::SECOND) {
					std::cout << frames << std::endl;
					frames = 0;
					frameCounter = 0;
				}
			}

			if (shouldRender) {
				render();
				frames++;
			}
			else {
				SDL_Delay(1000);
			}
		}

		cleanUp();
	}

void MainComponent::render() {
		rutils::clearScreen();
		game.render();
		Window::render();
	}

void MainComponent::cleanUp()
{
	Window::dispose();
}

int main() {
	SDL_SetMainReady();
	Window::NewWindow(1024, 720, "GL engine");

	MainComponent::start();

	return 0;
}