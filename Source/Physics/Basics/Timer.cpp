#include "Physics/Basics/Timer.h"

Timer::Timer() {

	restart();

}

void Timer::restart() {

	lastStop = Clock::now();

}

float Timer::getEllapsedTime() {

	Clock::time_point nextStop = Clock::now();

	using namespace std::chrono;
	duration<float> ellapsedTime = duration_cast<duration<float>>(nextStop-lastStop);

	lastStop = nextStop;
	return ellapsedTime.count();

}
