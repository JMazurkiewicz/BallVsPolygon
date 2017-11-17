#pragma once

#include "Objects/Polygon.h"
#include "Physics/Basics/Velocity.h"
#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {

public:

	Ball();

	const Velocity& getVelocity() const;
	void setVelocity(const Velocity& velocity);

	void update(float time);
	void bounceOnCollisionWith(const Polygon& polygon);

private:

	Velocity velocity;

};