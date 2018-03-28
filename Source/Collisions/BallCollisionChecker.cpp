#include "BallCollisionChecker.h"

#include <cstddef>

BallCollisionChecker::BallCollisionChecker(const Ball& ball)
	: ball(ball) { }

bool BallCollisionChecker::didCollisionHappenWith(const Polygon& polygon) {

	for(std::size_t i = 0; i < polygon.getPointCount(); ++i) {

		const LineSegment side = polygon.getSide(i);

		if(didCollisionHappenWithSide(side)) {

			collidedSide = side.getLine();
			return true;
			
		}

	}

	return false;

}

Line BallCollisionChecker::getCollidedSide() const {
	return collidedSide;
}

bool BallCollisionChecker::didCollisionHappenWithSide(const LineSegment& side) const {

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
