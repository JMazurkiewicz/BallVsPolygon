#pragma once

#include <SFML/Graphics.hpp>

class StraightLine {

public:

	StraightLine();
	StraightLine(const sf::Vector2f& pointA, const sf::Vector2f& pointB);

	bool isParallel(const StraightLine& other) const;

	float distanceFromPoint(const sf::Vector2f& point) const;
	sf::Vector2f getCommonPoint(const StraightLine& other) const;
	StraightLine getPerpendicularLineGoingThrough(const sf::Vector2f& point) const;

	float a, b, c;

};