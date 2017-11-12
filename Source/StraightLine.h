#pragma once

#include <SFML/Graphics.hpp>

class StraightLine {

public:

	StraightLine(float xCoefficient, float yCoefficient, float independentVariable);

	float distanceFromPoint(const sf::Vector2f point);

private:



};