#include "BallBouncer.h"

#include <cmath>
#include "Math/AxialSymmetry.h"

BallBouncer::BallBouncer(Ball& ball)
	: ball(ball) { }

void BallBouncer::bounceFrom(const Line& line) {

	AxialSymmetry symmetry(line);

	const Velocity symmetricalVelocity{symmetry.getSymmetricalVector(ball.getVelocity())};

	ball.move(calculateExitVector(line));
	ball.setVelocity(symmetricalVelocity);

}

sf::Vector2f BallBouncer::calculateExitVector(const Line& line) const {

	const sf::Vector2f normalVector = -line.getNormalVector();
	const float distanceFromBallCircuit = ball.getRadius() - line.getDistanceFromPoint(ball.getPosition());
	const float normalVectorLength = hypot(normalVector.x, normalVector.y);

	return (normalVector * distanceFromBallCircuit) / normalVectorLength;

}