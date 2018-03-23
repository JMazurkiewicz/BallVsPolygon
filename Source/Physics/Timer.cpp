#include "Timer.h"

Timer::Timer() {
	enable();
}

bool Timer::isEnabled() const {
	return enabled;
}

void Timer::restart() {
	stop = Clock::now();
}

void Timer::switchMode() {

	if(isEnabled()) {
		disable();
	} else {
		enable();
	}

}

void Timer::enable() {
	
	if(!isEnabled()) {
		enabled = true;
		restart();
	}

}

void Timer::disable() {
	enabled = false;
}

Timer::Seconds Timer::getEllapsedTime() {

	if(!isEnabled()) {
		return Seconds{};
	}

	const TimePoint nextStop = Clock::now();
	const Seconds ellapsedTime = std::chrono::duration_cast<Seconds>(nextStop - stop);

	stop = nextStop;
	return ellapsedTime;

}
