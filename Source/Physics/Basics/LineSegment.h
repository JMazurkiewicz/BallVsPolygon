#pragma once

#include "Physics/Basics/Line.h"
#include <SFML/Graphics.hpp>

class LineSegment {

public:

	LineSegment(const sf::Vector2f& pointA, const sf::Vector2f& pointB);

	const Line& getLine() const;
	float getBegin() const;
	float getEnd() const;

private:

	Line line;
	float begin, end;

};