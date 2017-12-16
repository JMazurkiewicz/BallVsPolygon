#pragma once

#include "Physics/Basics/Velocity.h"

class RandomVelocityMaker {

public:

	RandomVelocityMaker(float velocityValue);

	Velocity makeVelocity();

private:

	float makeXCoordinate();
	float makeYCoordinate(float x);

	const float velocityValue;

};