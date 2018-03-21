#pragma once

#include "Math/Line.h"
#include "Objects/Ball.h"

class BallBouncer {

public:

	explicit BallBouncer(Ball& ball);

	void bounceFrom(const Line& line);

private:

	Ball& ball;

};