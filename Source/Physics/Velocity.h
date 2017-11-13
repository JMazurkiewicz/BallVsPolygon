#pragma once

#include <SFML/Graphics.hpp>
#include "Physics/Stopwatch.h"

class Velocity : public sf::Vector2f {

public:

	using sf::Vector2f::Vector2f;

	void restart();
	sf::Vector2f getDistanceVector();

private:

	Stopwatch stopwatch;

};