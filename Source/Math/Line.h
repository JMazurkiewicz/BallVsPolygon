#pragma once

#include <SFML/Graphics.hpp>

class Line {

public:

	Line();
	Line(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);

	void assignLinePassingThroughTwoPoints(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);

	bool isParallelTo(const Line& other) const;

	sf::Vector2f getCommonPoint(const Line& other) const;
	float getDistanceFromPoint(const sf::Vector2f& point) const;

	Line getParallelLinePassingThroughPoint(const sf::Vector2f& point) const;
	Line getPerpendicularLinePassingThroughPoint(const sf::Vector2f& point) const;

private:

	float a, b, c;

	void throwIfUnableToMakeALine(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const;
	void throwIfHasNoCommonPoint(const Line& other) const;

};