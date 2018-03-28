#pragma once

#include <chrono>

class Timer {

public:

	using Clock = std::chrono::high_resolution_clock;
	using TimePoint = Clock::time_point;
	using Seconds = std::chrono::duration<float>;

	Timer();

	bool isEnabled() const;

	void restart();

	void enable();
	void disable();
	void switchMode();

	Seconds getEllapsedTime();

private:

	TimePoint stop;
	bool enabled;

};