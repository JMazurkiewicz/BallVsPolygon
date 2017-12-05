#pragma once

#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Line.h"
#include "Physics/Basics/LineSegment.h"

class CollisionChecker {

public:

	CollisionChecker(const Ball& ball, const Polygon& polygon);

	bool didCollisionHappen();
	Line getCollidedLine() const;

private:

	bool didCollisionHappenWithSide(const LineSegment& side) const;
	
	const Ball& ball;
	const Polygon& polygon;

	Line collisionLine;

};