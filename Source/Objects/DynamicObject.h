#pragma once

#include "Physics/Velocity.h"

class DynamicObject {

public:

	const Velocity& getVelocity() const;
	void setVelocity(const Velocity& newVelocity);

private:

	Velocity velocity;

};