#version 400 core

layout (location = 0) in vec3 position;

void main() {
	gl_Position = vec4(0.25 * position, 1.0);
}