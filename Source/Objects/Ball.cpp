#include "Ball.h"

#include "Collisions/CollisionChecker.h"
#include "Math/AxialSymmetry.h"
#include "Physics/RandomVelocityGenerator.h"

namespace {

	constexpr float BALL_RADIUS = 20.0F;
	constexpr float BALL_VELOCITY = 300.0F;

}

Ball::Ball() : enabled(false) {

	setFillColor(sf::Color(150, 120, 100));

	setRadius(BALL_RADIUS);
	setOrigin(BALL_RADIUS, BALL_RADIUS);

}

const Velocity& Ball::getVelocity() const {
	return velocity;
}

void Ball::setVelocity(const Velocity& velocity) {
	this->velocity = velocity;
}

sf::FloatRect Ball::makeRectangle() const {

	const sf::Vector2f cornerVector(BALL_RADIUS, BALL_RADIUS);

	return sf::FloatRect(getPosition() - cornerVector, 2.0F * cornerVector);

}

bool Ball::isEnabled() const {
	return enabled;
}

void Ball::enable() {
	enabled = true;
}

void Ball::randomizeVelocityVector() {

	RandomVelocityGenerator velocityGenerator(BALL_VELOCITY);
	setVelocity(velocityGenerator.generate());

}

void Ball::update(float time) {

	if(isEnabled()) {
		move(velocity.calculateDistanceVector(time));
	}

}

void Ball::bounceOnCollisionWith(const Polygon& polygon) {

	if(!isEnabled()) {
		return;
	}

	CollisionChecker collisionChecker(*this);

	if(collisionChecker.didCollisionHappenWith(polygon)) {

		bounceFromSide(collisionChecker.getCollidedSide());

	}

}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	if(isEnabled()) {
		target.draw(static_cast<sf::CircleShape>(*this), states);
	}

}

void Ball::bounceFromSide(const Line& side) {

	AxialSymmetry symmetry(side);

	const Velocity symmetricalVelocity(
		symmetry.getSymmetricalVector(getVelocity())
	);

	setVelocity(symmetricalVelocity);

}
