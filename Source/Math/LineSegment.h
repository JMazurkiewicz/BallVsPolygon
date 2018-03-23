#pragma once

#include "Math/Line.h"
#include <SFML/Graphics.hpp>

class LineSegment {

public:

	explicit LineSegment(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);

	const Line& getLine() const;

	const sf::Vector2f& getFirstPoint() const;
	const sf::Vector2f& getSecondPoint() const;

	sf::FloatRect makeRectangle() const;

private:

	Line line;

	const sf::Vector2f firstPoint;
	const sf::Vector2f secondPoint;

};