#pragma once

#include <SFML/Graphics.hpp>
#include "Physics/Velocity.h"

class Ball : public sf::CircleShape {

public:

	Ball();

	void move();

private:

	Velocity velocity;

};