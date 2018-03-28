#pragma once

#include "Math/Line.h"
#include "Physics/Velocity.h"

class PhysicalObject {

public:

	const Velocity& getVelocity() const;
	void setVelocity(const Velocity& newVelocity);

	void bounceFromLine(const Line& line);

private:

	Velocity velocity;

};