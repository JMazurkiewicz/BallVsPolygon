#include "Timer.h"

Timer::Timer() {
	enable();
}

void Timer::restart() {
	lastStop = Clock::now();
}

void Timer::switchMode() {

	if(isEnabled) {
		disable();
	} else {
		enable();
	}

}

void Timer::enable() {
	
	if(!isEnabled) {
		isEnabled = true;
		restart();
	}

}

void Timer::disable() {
	isEnabled = false;
}

Timer::Seconds Timer::getEllapsedTime() {

	if(!isEnabled) {
		return Seconds{};
	}

	const TimePoint nextStop = Clock::now();
	const Seconds ellapsedTime = std::chrono::duration_cast<Seconds>(nextStop - lastStop);

	lastStop = nextStop;
	return ellapsedTime;

}
