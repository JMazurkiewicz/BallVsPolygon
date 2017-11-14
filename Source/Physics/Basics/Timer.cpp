#include "Physics/Basics/Timer.h"

Timer::Timer() {
	restart();
}

void Timer::restart() {
	lastStop = Clock::now();
}

float Timer::getEllapsedTime() {

	Clock::time_point newStop = Clock::now();

	using namespace std::chrono;
	auto ellapsedTime = duration_cast<duration<float>>(newStop-lastStop);

	lastStop = newStop;
	return ellapsedTime.count();

}
