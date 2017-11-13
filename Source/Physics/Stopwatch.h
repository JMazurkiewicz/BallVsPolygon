#pragma once

#include <chrono>

class Stopwatch {

public:
	
	using Clock = std::chrono::high_resolution_clock;

	Stopwatch();

	void restart();
	float getEllapsedTime();

private:

	Clock::time_point lastStop;

};