#include "DynamicObject.h"

const Velocity& DynamicObject::getVelocity() const {
	return velocity;
}

void DynamicObject::setVelocity(const Velocity& newVelocity) {
	velocity = newVelocity;
}