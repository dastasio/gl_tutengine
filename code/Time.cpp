#include "Time.h"
#include <SDL.h>

double Time::delta;

long Time::getTime() {
	return SDL_GetTicks();
}

double Time::getDelta() {
	return delta;
}

void Time::setDelta(double d) {
	delta = d;
}