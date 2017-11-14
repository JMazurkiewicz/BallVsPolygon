#include "Physics/Basics/Stopwatch.h"

Stopwatch::Stopwatch() {
	restart();
}

void Stopwatch::restart() {
	lastStop = Clock::now();
}

float Stopwatch::getEllapsedTime() {

	Clock::time_point newStop = Clock::now();

	using namespace std::chrono;
	auto ellapsedTime = duration_cast<duration<float>>(newStop-lastStop);

	lastStop = newStop;
	return ellapsedTime.count();

}
