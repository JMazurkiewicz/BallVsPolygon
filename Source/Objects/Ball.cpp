#include "Ball.h"

#include "Math/AxialSymmetry.h"

Ball::Ball(float radius) : CircleShape(radius) {
	initBallStyle();
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	if(isEnabled()) {
		target.draw(CircleShape{*this}, states);
	}

}

void Ball::initBallStyle() {

	setFillColor(sf::Color{0, 128, 128});
	setOrigin(getRadius(), getRadius());

}

void Ball::doUpdate(float time) {

	move(getVelocity().calculateDistanceVector(time));

}