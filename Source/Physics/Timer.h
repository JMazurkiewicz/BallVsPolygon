#pragma once

#include <chrono>

class Timer {

public:

	using Clock = std::chrono::high_resolution_clock;

	Timer();

	void enable();
	void disable();
	void switchMode();

	void restart();
	float getEllapsedTime();

private:

	Clock::time_point lastStop;
	bool isEnabled;

};