#pragma once

#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Line.h"

class CollisionChecker {

public:

	bool didCollisionHappen(const Polygon& polygon, const Ball& ball);
	Line getCollisionSide() const;

private:

	Line getSideOfPolygon(std::size_t i, const Polygon& polygon) const;
	bool didCollisionHappenWithSide(const Line& side, const Ball& ball) const;

	Line collsionSide;

};