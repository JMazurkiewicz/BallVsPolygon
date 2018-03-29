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
	return isBallNoticeableBySide(side) && isBallTouchingSide(side);
}

bool CollisionChecker::isBallTouchingSide(const LineSegment& side) const {

	return side.getLine().getDistanceFromPoint(ball.getPosition()) <= ball.getRadius();

}

bool CollisionChecker::isBallNoticeableBySide(const LineSegment& side) const {

	const Line firstStop = side.getLine().getPerpendicularLinePassingThroughPoint(side.getFirstPoint());
	const Line secondStop = side.getLine().getPerpendicularLinePassingThroughPoint(side.getSecondPoint());

	const float distanceBetweenEachStop = firstStop.getDistanceFromPoint(ball.getPosition()) +
		secondStop.getDistanceFromPoint(ball.getPosition());

	return firstStop.getDistanceFromLine(secondStop) >= distanceBetweenEachStop;

}