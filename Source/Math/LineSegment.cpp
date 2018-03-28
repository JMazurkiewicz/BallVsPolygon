#include "LineSegment.h"

#include <algorithm>
#include <cmath>

LineSegment::LineSegment(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint)
	: line(firstPoint, secondPoint), firstPoint(firstPoint), secondPoint(secondPoint) { }

const Line& LineSegment::getLine() const {
	return line;
}

const sf::Vector2f& LineSegment::getFirstPoint() const {
	return firstPoint;
}

const sf::Vector2f& LineSegment::getSecondPoint() const {
	return secondPoint;
}
