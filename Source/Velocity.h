#pragma once

#include <SFML/Graphics.hpp>
#include "Stopwatch.h"

class Velocity : public sf::Vector2f {

public:

	using sf::Vector2f::Vector2f;
	
	void restart();
	void moveObject(sf::Transformable& object);

private:

	sf::Vector2f computateDistanceVector();

	Stopwatch stopwatch;

};