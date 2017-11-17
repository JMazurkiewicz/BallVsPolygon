#include <cstddef>
#include "Physics/Collisions/CollisionChecker.h"
#include <utility>

CollisionChecker::CollisionChecker(const Ball& ball, const Polygon& polygon) : ball(ball), polygon(polygon) { }

bool CollisionChecker::didCollisionHappen() {

	for(std::size_t i = 0; i < polygon.getPointCount(); ++i) {

		const sf::Vector2f begining = getBeginingOfLine(i);
		const sf::Vector2f ending = getEndingOfLine(i);

		if(didCollisionHappenWithSide(begining, ending)) {

			collisionSide.assignLinePassingThroughTwoPoints(begining, ending);
			return true;
			
		}

	}

	return false;

}

Line CollisionChecker::getCollidedSide() const {

	return collisionSide;

}

sf::Vector2f CollisionChecker::getBeginingOfLine(std::size_t sideIndex) const {

	const std::size_t pointIndex = (sideIndex == 0) ? (polygon.getPointCount() - 1) : (sideIndex - 1);
	return polygon.getPoint(pointIndex);

}

sf::Vector2f CollisionChecker::getEndingOfLine(std::size_t sideIndex) const {
	return polygon.getPoint(sideIndex);
}

bool CollisionChecker::didCollisionHappenWithSide(const sf::Vector2f& begining, const sf::Vector2f& ending) const {

	const Line side(begining, ending);
	const sf::Vector2f ballPosition = ball.getPosition();

	return
		side.getDistanceFromPoint(ballPosition) <= ball.getRadius() &&
		((ballPosition.x > begining.x && ballPosition.x < ending.x) ||
		 (ballPosition.x > ending.x && ballPosition.x < begining.x));

}
