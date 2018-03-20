#include "BallBouncer.h"

#include "Math/AxialSymmetry.h"

BallBouncer::BallBouncer(Ball& ball) : ball(ball) { }

void BallBouncer::bounceFrom(const Line& line) {

	AxialSymmetry symmetry(line);
	const Velocity newVelocity = symmetry.getSymmetricalVector(ball.getVelocity());

	ball.setVelocity(newVelocity);

}