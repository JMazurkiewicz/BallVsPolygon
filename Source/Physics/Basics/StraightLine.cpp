#include <cmath>
#include "Physics/Basics/StraightLine.h"

StraightLine::StraightLine(const sf::Vector2f& pointA, const sf::Vector2f& pointB) :
	a{-(pointB.y - pointA.y)},
	b{pointB.x - pointA.x},
	c{pointA.x * (pointB.y-pointA.y) - pointA.y * (pointB.x-pointA.x)} { }

float StraightLine::distanceFromPoint(const sf::Vector2f point) const {

	return abs(a*point.x + b*point.y + c) / sqrt(a*a + b*b);

}
