#pragma once

#include "Physics/Basics/Line.h"
#include <SFML/Graphics.hpp>

class LineSegment {

public:

	LineSegment(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);

	const Line& getLine() const;
	const sf::Vector2f& getFirstPoint() const;
	const sf::Vector2f& getSecondPoint() const;

	operator Line() const;
	sf::FloatRect makeRectangle() const;

private:

	Line line;

	sf::Vector2f firstPoint;
	sf::Vector2f secondPoint;

};