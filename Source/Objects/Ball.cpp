#include "Ball.h"

Ball::Ball(float radius) : CircleShape(radius, 30) {
	initBallStyle();
}

void Ball::update(float time) {
	move(getVelocity().calculateDistanceVector(time));
}

void Ball::initBallStyle() {
	setFillColor(sf::Color{175, 96, 140});
	setOrigin(getRadius(), getRadius());
}