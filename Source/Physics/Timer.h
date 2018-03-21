#pragma once

#include <chrono>

class Timer {

public:

	using Clock = std::chrono::high_resolution_clock;
	using TimePoint = Clock::time_point;

	Timer();

	void restart();

	void enable();
	void disable();
	void switchMode();

	float getEllapsedTime();

private:

	TimePoint lastStop;
	bool isEnabled;

};