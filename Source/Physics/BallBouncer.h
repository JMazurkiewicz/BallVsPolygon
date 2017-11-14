#pragma once

#include "Objects/Ball.h"
#include "Physics/Basics/Line.h"

class BallBouncer {

public:

	BallBouncer(const Line& line, Ball& ball);

	void bounceOnCollisionFrom();

private:

	bool didCollisionHappen() const;

	const Line& line;
	Ball& ball;

};