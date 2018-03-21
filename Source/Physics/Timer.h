#pragma once

#include <chrono>

class Timer {

public:

	using Clock = std::chrono::high_resolution_clock;
	using TimePoint = Clock::time_point;
	using Seconds = std::chrono::duration<float>;

	Timer();

	void restart();

	void switchMode();
	void enable();
	void disable();

	Seconds getEllapsedTime();

private:

	TimePoint lastStop;
	bool isEnabled;

};