#pragma once

#include "Objects/Ball.h"
#include "Physics/Basics/Line.h"

class BallBouncer {

public:

	BallBouncer(Ball& ball);

	void bounceFrom(const Line& line);

private:

	Ball& ball;

};