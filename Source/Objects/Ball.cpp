#include <cstddef>
#include "Objects/Ball.h"
#include "Physics/BallBouncer.h"

namespace {
	constexpr float BALL_RADIUS = 10;
}

Ball::Ball() : velocity(50, 50) {

	setRadius(BALL_RADIUS);
	setFillColor(sf::Color::Red);

	setOrigin(BALL_RADIUS, BALL_RADIUS);

	setPosition(200, 200);

}

const Velocity& Ball::getVelocity() const {
	return velocity;
}

void Ball::setVelocity(const Velocity& velocity) {
	this->velocity = velocity;
}

void Ball::update() {
	move(velocity.getDistanceVector());
}

#include <iostream>

void Ball::bounceOnCollisionWith(const Polygon& polygon) {

	const size_t pointCount = polygon.getPointCount();

	StraightLine lastSide(polygon.getPoint(0), polygon.getPoint(pointCount-1));
	BallBouncer(lastSide, *this).bounceOnCollisionFrom();

	for(std::size_t i = 1; i < pointCount; ++i) {

		StraightLine line(polygon.getPoint(i-1), polygon.getPoint(i));
		
		std::cout << "line: " << line.a << "x + (" << line.b << ")y + (" << line.c << ") = 0\n";

		BallBouncer bouncer(line, *this);
		bouncer.bounceOnCollisionFrom();

	}

}
