#include "Physics/Basics/Timer.h"

Timer::Timer() {
	enable();
}

void Timer::enable() {
	restart();
	isEnabled = true;
}

void Timer::disable() {
	isEnabled = false;
}

void Timer::switchMode() {

	if(isEnabled) {
		disable();
	} else {
		enable();
	}

}

void Timer::restart() {
	lastStop = Clock::now();
}

float Timer::getEllapsedTime() {

	if(isEnabled) {

		Clock::time_point nextStop = Clock::now();

		using namespace std::chrono;
		duration<float> ellapsedTime = duration_cast<duration<float>>(nextStop-lastStop);

		lastStop = nextStop;
		return ellapsedTime.count();

	}

	return 0.0f;

}
