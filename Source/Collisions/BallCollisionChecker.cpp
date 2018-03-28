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

	const sf::FloatRect sideRectangle = side.makeRectangle();
	const sf::FloatRect ballRectangle = ball.makeRectangle();

	return (side.getLine().getDistanceFromPoint(ballPosition) <= ball.getRadius()) && sideRectangle.intersects(ballRectangle);


}
