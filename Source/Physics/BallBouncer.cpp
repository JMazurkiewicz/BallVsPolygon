#include "Physics/AxialSymmetry.h"
#include "Physics/BallBouncer.h"

BallBouncer::BallBouncer(const Line& line, Ball& ball) : line(line), ball(ball) { }

void BallBouncer::bounceOnCollisionFrom() {

	if(didCollisionHappen()) {

		AxialSymmetry symmetry(line);

		const Velocity newVelocity{symmetry.getSymmetricalVector(ball.getVelocity())};
		ball.setVelocity(newVelocity);

	}

}

#include <iostream>

bool BallBouncer::didCollisionHappen() const {
	return line.distanceFromPoint(ball.getPosition()) <= ball.getRadius();
}