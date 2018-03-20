#include "RandomVelocityMaker.h"

#include <cmath>
#include <random>

namespace {

	std::mt19937 generator(std::random_device{}());

}

RandomVelocityMaker::RandomVelocityMaker(float velocityValue)
	: velocityValue(velocityValue) { }

Velocity RandomVelocityMaker::makeVelocity() {
	
	const float x = makeXCoordinate();
	const float y = makeYCoordinate(x);

	return Velocity(x, y);

}

float RandomVelocityMaker::makeXCoordinate() {

	std::uniform_real_distribution<float> distribution(-velocityValue, velocityValue);
	return distribution(generator);

}

float RandomVelocityMaker::makeYCoordinate(float x) {
	
	std::uniform_int_distribution<> distribution(0, 1);
	const int sign = (distribution(generator) ? (1) : (-1));
	
	return sign * std::sqrt(velocityValue*velocityValue - x*x);

}
