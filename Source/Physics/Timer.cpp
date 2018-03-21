#include "Timer.h"

Timer::Timer() {
	enable();
}

void Timer::restart() {
	lastStop = Clock::now();
}

void Timer::enable() {
	isEnabled = true;
	restart();
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

float Timer::getEllapsedTime() {

	if(!isEnabled) {
		return 0.0F;
	}

	TimePoint nextStop = Clock::now();

	auto ellapsedTime = std::chrono::duration_cast<std::chrono::duration<float>>(
		nextStop - lastStop
	);

	lastStop = nextStop;
	return ellapsedTime.count();

}
