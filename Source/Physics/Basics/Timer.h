#pragma once

#include <chrono>

class Timer {

public:
	
	using Clock = std::chrono::high_resolution_clock;

	Timer();

	void restart();
	float getEllapsedTime();

private:

	Clock::time_point lastStop;

};