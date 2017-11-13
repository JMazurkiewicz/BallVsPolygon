#pragma once

#include <SFML/Graphics.hpp>

class StraightLine {

public:

	StraightLine(const sf::Vector2f& pointA, const sf::Vector2f& pointB);

	float distanceFromPoint(const sf::Vector2f point) const;

private:

	float a, b, c;

};