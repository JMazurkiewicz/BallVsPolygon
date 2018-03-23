#pragma once

#include <SFML/System/Vector2.hpp>

class Velocity : public sf::Vector2f {

public:

	using sf::Vector2f::Vector2f;

	sf::Vector2f calculateDistanceVector(float time) const;

};