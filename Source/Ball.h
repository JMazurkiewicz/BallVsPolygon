#pragma once

#include <SFML/Graphics.hpp>
#include "Velocity.h"

class Ball : public sf::CircleShape {

public:

	Ball();

	void move();

private:

	Velocity velocity;

};