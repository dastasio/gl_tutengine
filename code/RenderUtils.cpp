#include "RenderUtils.h"
#include "oglin.h"

void rutils::clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void rutils::initGraphics() {
	glClearColor(0.f, 0.f, 0.f, 0.f);

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_FRAMEBUFFER_SRGB);
}
