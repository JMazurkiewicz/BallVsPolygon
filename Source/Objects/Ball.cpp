#include <cstddef>
#include "Objects/Ball.h"
#include "Physics/Collisions/BallBouncer.h"
#include "Physics/Collisions/CollisionChecker.h"

namespace {

	constexpr float BALL_RADIUS = 15;
	constexpr float BALL_VELOCITY = 150;

}

Ball::Ball() : velocity(BALL_VELOCITY, BALL_VELOCITY) {

	setRadius(BALL_RADIUS);
	setFillColor(sf::Color::Green);

	setOrigin(BALL_RADIUS, BALL_RADIUS);
	setPosition(0, 0);

}

const Velocity& Ball::getVelocity() const {

	return velocity;

}

void Ball::setVelocity(const Velocity& velocity) {

	this->velocity = velocity;

}

void Ball::update(float time) {

	move(velocity.getDistanceVector(time));

}

void Ball::bounceOnCollisionWith(const Polygon& polygon) {

	CollisionChecker collisionChecker(*this);
	if(collisionChecker.didCollisionHappenWith(polygon)) {

		BallBouncer ballBouncer(*this);
		ballBouncer.bounceFrom(collisionChecker.getCollidedSide());

	}

}
