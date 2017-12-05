#pragma once

#include "Physics/Basics/ClosedInterval.h"
#include "Physics/Basics/Line.h"
#include <SFML/Graphics.hpp>

class LineSegment {

public:

	LineSegment(const sf::Vector2f& first, const sf::Vector2f& second);

	const Line& getLine() const;
	const ClosedInterval& getDomain() const;

	operator Line() const;

private:

	Line line;
	ClosedInterval domain;

};