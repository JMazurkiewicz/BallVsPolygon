#include "Ball.h"

Ball::Ball(float radius) : CircleShape(radius, 30) {
	initBallStyle();
}

void Ball::update(float time) {
	move(getVelocity().calculateDistanceVector(time));
}

void Ball::initBallStyle() {
	setFillColor(sf::Color{0, 128, 128});
	setOrigin(getRadius(), getRadius());
}