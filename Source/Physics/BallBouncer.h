#pragma once

#include "Objects/Ball.h"
#include "Physics/StraightLine.h"

class BallBouncer {

public:

	BallBouncer(const StraightLine& line, Ball& ball);

	void bounceOnCollisionFrom();

private:

	bool didCollisionHappen() const;

	const StraightLine& line;
	Ball& ball;

};