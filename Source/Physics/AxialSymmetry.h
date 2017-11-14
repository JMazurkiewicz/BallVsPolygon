#pragma once

#include "Physics/Basics/StraightLine.h"
#include <SFML/Graphics.hpp>

class AxialSymmetry {

public:

	AxialSymmetry(const StraightLine& axis);

	sf::Vector2f getSymmetricalVector(const sf::Vector2f& vector);

private:

	void prepareAxis();

	StraightLine axis;

};