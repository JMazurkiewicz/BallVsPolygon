#include "Objects/Ball.h"

Ball::Ball() : velocity(50, 50) {

	setRadius(10);
	setFillColor(sf::Color::Red);

}

void Ball::update() {

	move(velocity.getDistanceVector());

}
