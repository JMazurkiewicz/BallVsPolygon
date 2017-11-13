#pragma once

#include <SFML/Graphics.hpp>
#include "Physics/Velocity.h"

class Ball : public sf::CircleShape {

public:

	Ball();

	void update();

private:

	Velocity velocity;

};