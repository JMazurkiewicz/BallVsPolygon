#include "PhysicalObject.h"

#include "Math/AxialSymmetry.h"

const Velocity& PhysicalObject::getVelocity() const {
	return velocity;
}

void PhysicalObject::setVelocity(const Velocity& newVelocity) {
	velocity = newVelocity;
}

void PhysicalObject::bounceFromLine(const Line& line) {

	AxialSymmetry symmetry(line);

	const Velocity symmetricalVelocity{symmetry.getSymmetricalVector(getVelocity())};
	setVelocity(symmetricalVelocity);

}
