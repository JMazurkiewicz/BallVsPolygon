#pragma once

#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Line.h"
#include "Physics/Basics/LineSegment.h"

class CollisionChecker {

public:

	CollisionChecker(const Ball& ball);

	bool didCollisionHappenWith(const Polygon& polygon);
	Line getCollidedSide() const;

private:

	bool didCollisionHappenWithSide(const LineSegment& side) const;
	
	const Ball& ball;
	Line collidedSide;

};