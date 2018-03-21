#include "RandomVelocityMaker.h"

#include <cmath>
#include "Math/Pi.h"
#include <random>

namespace {

	std::mt19937 generator(std::random_device{}());

}

RandomVelocityMaker::RandomVelocityMaker(float velocityValue)
	: velocityValue(velocityValue) { }

Velocity RandomVelocityMaker::makeVelocity() {
	
	std::uniform_real_distribution<float> angleDistribtion(0, 2*PI);
	const float angle = angleDistribtion(generator);

	const float x = velocityValue * std::cos(angle);
	const float y = velocityValue * std::sin(angle);

	return Velocity(x, y);

}
