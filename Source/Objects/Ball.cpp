#include "Ball.h"

#include "Collisions/BallCollisionChecker.h"
#include "Math/AxialSymmetry.h"

Ball::Ball(float radius, float velocity) {

	setFillColor(sf::Color(0, 128, 128));

	setRadius(radius);
	setOrigin(radius, radius);

}

sf::FloatRect Ball::makeRectangle() const {

	const sf::Vector2f originVector(getRadius(), getRadius());
	return sf::FloatRect(getPosition() - originVector, 2.0F * originVector);

}

void Ball::bounceOnCollisionWith(const Polygon& polygon) {

	if(!isEnabled()) {
		return;
	}

	BallCollisionChecker collisionChecker(*this);

	if(collisionChecker.didCollisionHappenWith(polygon)) {
		bounceFromLine(collisionChecker.getCollidedSide());
	}

}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	if(isEnabled()) {
		target.draw(CircleShape{*this}, states);
	}

}

void Ball::doUpdate(float time) {

	move(getVelocity().calculateDistanceVector(time));

}