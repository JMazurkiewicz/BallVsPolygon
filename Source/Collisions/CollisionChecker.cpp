#include "CollisionChecker.h"

#include <cstddef>

CollisionChecker::CollisionChecker(const Ball& ball)
	: ball(ball) { }

bool CollisionChecker::didCollisionHappenWith(const Polygon& polygon) {

	for(std::size_t pointIndex = 0; pointIndex != polygon.getPointCount(); ++pointIndex) {

		const LineSegment side = polygon.getSide(pointIndex);

		if(didCollisionHappenWithSide(side)) {
			collidedSide = side.getLine();
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
	const float ballRadius = ball.getRadius();

	const Line sideLine = side.getLine();

	const Line firstStop = sideLine.getPerpendicularLinePassingThroughPoint(side.getFirstPoint());
	const Line secondStop = sideLine.getPerpendicularLinePassingThroughPoint(side.getSecondPoint());

	return
		sideLine.getDistanceFromPoint(ballPosition) <= ballRadius &&
		(firstStop.getDistanceFromPoint(ballPosition) <= ballRadius ||
		 secondStop.getDistanceFromPoint(ballPosition) <= ballRadius ||
		 firstStop.getDistanceFromLine(secondStop) >= firstStop.getDistanceFromPoint(ballPosition) +
		 secondStop.getDistanceFromPoint(ballPosition));

}
