#pragma once

#include "Physics/Velocity.h"
#include <random>

class RandomVelocityGenerator {

public:

	explicit RandomVelocityGenerator(float velocityValue);

	Velocity generate();

private:

	const float velocityValue;

	static std::mt19937 generator;

};