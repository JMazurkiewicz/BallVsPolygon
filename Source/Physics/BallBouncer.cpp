#include "Physics/BallBouncer.h"

BallBouncer::BallBouncer(const StraightLine& line, Ball& ball) : line(line), ball(ball) { }

void BallBouncer::bounceOnCollisionFrom() {

	if(didCollisionHappen()) {

		

	}

}

bool BallBouncer::didCollisionHappen() const {
	return line.distanceFromPoint(ball.getOrigin()) <= ball.getRadius();
}
