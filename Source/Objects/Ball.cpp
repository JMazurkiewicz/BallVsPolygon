#include <cstddef>
#include "Objects/Ball.h"
#include "Physics/Collisions/BallBouncer.h"
#include "Physics/Collisions/CollisionChecker.h"
#include "Physics/RandomVelocityMaker.h"

namespace {

	constexpr float BALL_RADIUS = 20;
	constexpr float BALL_VELOCITY = 300;

}

Ball::Ball() : activity(false) {

	setRadius(BALL_RADIUS);
	setFillColor(sf::Color(91, 155, 102));

	setOrigin(BALL_RADIUS, BALL_RADIUS);

}

const Velocity& Ball::getVelocity() const {
	return velocity;
}

void Ball::setVelocity(const Velocity& velocity) {
	this->velocity = velocity;
}

sf::FloatRect Ball::makeRectangle() const {
	
	const sf::Vector2f radiusVector(getRadius(), getRadius());
	return sf::FloatRect(getPosition() - radiusVector, 2.0f * radiusVector);

}

bool Ball::isActive() const {
	return activity;
}

void Ball::activate() {

	RandomVelocityMaker velocityMaker(BALL_VELOCITY);
	setVelocity(velocityMaker.makeVelocity());

	activity = true;

}

void Ball::update(float time) {

	if(isActive()) {
		move(velocity.getDistanceVector(time));
	}

}

void Ball::bounceOnCollisionWith(const Polygon& polygon) {

	if(isActive()) {

		CollisionChecker collisionChecker(*this);
		if(collisionChecker.didCollisionHappenWith(polygon)) {

			BallBouncer ballBouncer(*this);
			ballBouncer.bounceFrom(collisionChecker.getCollidedSide());

		}

	}

}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	if(isActive()) {
		target.draw(static_cast<CircleShape>(*this), states);
	}

}