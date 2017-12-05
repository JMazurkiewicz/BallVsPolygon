#pragma once

#include <SFML/Graphics.hpp>

class Line {

public:

	Line();
	Line(const sf::Vector2f& first, const sf::Vector2f& second);

	void assignLinePassingThroughTwoPoints(const sf::Vector2f& first, const sf::Vector2f& second);

	bool isParallelTo(const Line& other) const;

	sf::Vector2f getCommonPoint(const Line& other) const;
	float getDistanceFromPoint(const sf::Vector2f& point) const;
	Line getPerpendicularLinePassingThroughPoint(const sf::Vector2f& point) const;

	float a, b, c;

private:

	void throwIfUnableToMakeALine(const sf::Vector2f& first, const sf::Vector2f& second) const;
	void throwIfHasNoCommonPoint(const Line& other) const;

};