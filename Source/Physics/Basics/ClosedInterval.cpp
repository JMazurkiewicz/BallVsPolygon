#include <algorithm>
#include "Physics/Basics/ClosedInterval.h"

ClosedInterval::ClosedInterval(float begin, float end) {

	auto orderedInterval = std::minmax(begin, end);
	this->begin = orderedInterval.first;
	this->end = orderedInterval.second;

}

bool ClosedInterval::contains(float value) const {
	return value > begin && value < end;
}
