#pragma once

#include "Math/Line.h"
#include <SFML/Graphics.hpp>

class AxialSymmetry {

public:

	AxialSymmetry(const Line& axis);
	sf::Vector2f getSymmetricalVector(const sf::Vector2f& vector);

private:

	const Line axis;

};