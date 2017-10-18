#pragma once

class Time {
public:
	static const long SECOND = 1000L;

	static long getTime();
	static double getDelta();

	static void setDelta(double);
private:
	static double delta;
};