#pragma once

#include <SFML/Graphics.hpp>
#include "Physics/Basics/Velocity.h"

class Ball : public sf::CircleShape {

public:

	Ball();

	const Velocity& getVelocity() const;
	void setVelocity(const Velocity& velocity);

	void update();

private:

	Velocity velocity;

};