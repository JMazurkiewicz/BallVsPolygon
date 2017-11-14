#pragma once

#include <SFML/Graphics.hpp>

class Line {

public:

	Line();
	Line(const sf::Vector2f& pointA, const sf::Vector2f& pointB);

	void assignLinePassingThroughTwoPoints(const sf::Vector2f& pointA, const sf::Vector2f& pointB);

	bool isParallelTo(const Line& other) const;

	float distanceFromPoint(const sf::Vector2f& point) const;
	sf::Vector2f getCommonPoint(const Line& other) const;
	Line getPerpendicularLinePassingThroughPoint(const sf::Vector2f& point) const;

	float a, b, c;

private:

	void throwIfHasNoCommonPoint(const Line& other) const;

};