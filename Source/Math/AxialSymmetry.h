#pragma once

#include "Math/Line.h"
#include <SFML/System/Vector2.hpp>

class AxialSymmetry {

public:

	explicit AxialSymmetry(const Line& axis);

	sf::Vector2f getSymmetricalVector(const sf::Vector2f& vector);

private:

	const Line axis;

};