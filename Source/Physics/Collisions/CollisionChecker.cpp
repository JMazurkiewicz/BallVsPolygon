#include <cstddef>
#include "Physics/Collisions/CollisionChecker.h"

CollisionChecker::CollisionChecker(const Ball& ball) : ball(ball) { }

bool CollisionChecker::didCollisionHappenWith(const Polygon& polygon) {

	for(std::size_t i = 0; i < polygon.getPointCount(); ++i) {

		const LineSegment side = polygon.getSide(i);

		if(didCollisionHappenWithSide(side)) {

			collidedSide = side;
			return true;
			
		}

	}

	return false;

}

Line CollisionChecker::getCollidedSide() const {

	return collidedSide;

}

bool CollisionChecker::didCollisionHappenWithSide(const LineSegment& side) const {

	const sf::Vector2f ballPosition = ball.getPosition();

	return
		side.getLine().getDistanceFromPoint(ballPosition) <= ball.getRadius() &&
		side.getDomain().contains(ballPosition.x);

}
