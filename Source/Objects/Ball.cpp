#include "Objects/Ball.h"

namespace {
	constexpr float BALL_RADIUS = 10;
}

Ball::Ball() : velocity(50, 50) {

	setRadius(BALL_RADIUS);
	setFillColor(sf::Color::Red);

	setOrigin(BALL_RADIUS, BALL_RADIUS);

}

void Ball::update() {

	move(velocity.getDistanceVector());

}

void Ball::setVelocity(const Velocity& velocity) {
	this->velocity = velocity;
}
