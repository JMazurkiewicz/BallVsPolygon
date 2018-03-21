#pragma once

#include <SFML/System.hpp>

class Velocity : public sf::Vector2f {

public:

	using sf::Vector2f::Vector2f;
	
	Velocity() = default;
	Velocity(const sf::Vector2f& vector);

	sf::Vector2f calculateDistanceVector(float time) const;

};