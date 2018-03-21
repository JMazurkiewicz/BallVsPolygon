#pragma once

#include "Physics/Velocity.h"

class RandomVelocityMaker {

public:

	explicit RandomVelocityMaker(float velocityValue);

	Velocity makeVelocity();

private:

	const float velocityValue;

};