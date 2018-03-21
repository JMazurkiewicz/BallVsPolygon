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

sf::FloatRect LineSegment::makeRectangle() const {

	const float left = std::min(getFirstPoint().x, getSecondPoint().x);
	const float top = std::min(getFirstPoint().y, getSecondPoint().y);

	const float width = std::abs(getFirstPoint().x - getSecondPoint().x) + 1.0F;
	const float height = std::abs(getFirstPoint().y - getSecondPoint().y) + 1.0F;

	return sf::FloatRect{left, top, width, height};

}
