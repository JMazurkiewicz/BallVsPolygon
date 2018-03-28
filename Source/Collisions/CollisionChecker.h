#pragma once

#include "Math/Line.h"
#include "Math/LineSegment.h"
#include "Objects/Ball.h"
#include "Objects/Polygon.h"

class CollisionChecker {

public:

	explicit CollisionChecker(const Ball& ball);

	bool didCollisionHappenWith(const Polygon& polygon);
	Line getCollidedSide() const;

private:

	bool didCollisionHappenWithSide(const LineSegment& side) const;
	
	const Ball& ball;
	Line collidedSide;

};