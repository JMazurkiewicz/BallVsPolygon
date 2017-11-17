#include <cstddef>
#include "Objects/Ball.h"
#include "Physics/Collisions/BallBouncer.h"
#include "Physics/Collisions/CollisionChecker.h"

namespace {

	constexpr float BALL_RADIUS = 10;

}

Ball::Ball() : velocity(300, 300) {

	setRadius(BALL_RADIUS);
	setFillColor(sf::Color::Red);

	setOrigin(BALL_RADIUS, BALL_RADIUS);

	setPosition(300, 300);

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

	CollisionChecker collisionChecker;
	if(collisionChecker.didCollisionHappen(polygon, *this)) {

		BallBouncer ballBouncer(*this);
		ballBouncer.bounceFrom(collisionChecker.getCollisionSide());

	}

}
