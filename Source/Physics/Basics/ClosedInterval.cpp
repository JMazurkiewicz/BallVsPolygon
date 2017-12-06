#include <algorithm>
#include "Physics/Basics/ClosedInterval.h"

ClosedInterval::ClosedInterval(float beginValue, float endValue) {

	auto orderedInterval = std::minmax(beginValue, endValue);
	this->beginValue = orderedInterval.first;
	this->endValue = orderedInterval.second;

}

bool ClosedInterval::contains(float value) const {

	return value > beginValue && value < endValue;

}

float ClosedInterval::begin() const {

	return beginValue;

}

float ClosedInterval::end() const {

	return endValue;

}
