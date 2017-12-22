#include <algorithm>
#include <cmath>
#include "Physics/Basics/LineSegment.h"

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

LineSegment::operator Line() const {
	return getLine();
}

sf::FloatRect LineSegment::makeRectangle() const {
	
	const float width = std::abs(getFirstPoint().x - getSecondPoint().x) + 1;
	const float height = std::abs(getFirstPoint().y - getSecondPoint().y) + 1;

	return sf::FloatRect(std::min(getFirstPoint().x, getSecondPoint().x),
						 std::min(getFirstPoint().y, getSecondPoint().y),
						 width, height);

}
