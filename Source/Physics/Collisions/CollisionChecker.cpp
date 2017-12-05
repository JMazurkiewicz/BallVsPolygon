#include <cstddef>
#include "Physics/Basics/LineSegment.h"
#include "Physics/Collisions/CollisionChecker.h"
#include <utility>

CollisionChecker::CollisionChecker(const Ball& ball, const Polygon& polygon) : ball(ball), polygon(polygon) { }

bool CollisionChecker::didCollisionHappen() {

	for(std::size_t i = 0; i < polygon.getPointCount(); ++i) {

		const LineSegment side = polygon.getSide(i);

		if(didCollisionHappenWithSide(side)) {

			collisionLine = side.getLine();
			return true;
			
		}

	}

	return false;

}

Line CollisionChecker::getCollidedLine() const {

	return collisionLine;

}

bool CollisionChecker::didCollisionHappenWithSide(const LineSegment& side) const {

	const sf::Vector2f ballPosition = ball.getPosition();

	return
		side.getLine().getDistanceFromPoint(ballPosition) <= ball.getRadius() &&
		(ballPosition.x > side.getBegin() && ballPosition.x < side.getEnd());

}
