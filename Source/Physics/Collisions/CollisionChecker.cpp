#include <cstddef>
#include "Physics/Collisions/CollisionChecker.h"

bool CollisionChecker::didCollisionHappen(const Polygon& polygon, const Ball& ball) {

	const std::size_t pointCount = polygon.getPointCount();

	for(std::size_t i = 0; i < pointCount; ++i) {

		const Line side = getSideOfPolygon(i, polygon);

		if(didCollisionHappenWithSide(side, ball)) {

			collsionSide = side;
			return true;
			
		}

	}

	return false;

}

Line CollisionChecker::getCollisionSide() const {

	return collsionSide;

}

Line CollisionChecker::getSideOfPolygon(std::size_t i, const Polygon& polygon) const {
	
	const std::size_t previousPointIndex = (i == 0) ? (polygon.getPointCount() - 1) : (i - 1);
	const Line side(polygon.getPoint(previousPointIndex), polygon.getPoint(i));

	return side;

}

bool CollisionChecker::didCollisionHappenWithSide(const Line& side, const Ball& ball) const {

	return side.distanceFromPoint(ball.getPosition()) <= ball.getRadius();

}
