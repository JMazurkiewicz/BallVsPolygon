#pragma once

#include <SFML/Graphics.hpp>

class Velocity : public sf::Vector2f {

public:

	using sf::Vector2f::Vector2f;
	Velocity(const sf::Vector2f& vector);

	sf::Vector2f getDistanceVector(float time);

};