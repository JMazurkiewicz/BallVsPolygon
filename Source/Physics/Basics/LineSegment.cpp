#include "Physics/Basics/LineSegment.h"

LineSegment::LineSegment(const sf::Vector2f& first, const sf::Vector2f& second)
	: line(first, second), domainX(first.x, second.x), domainY(first.y, second.y) { }

const Line& LineSegment::getLine() const {
	return line;
}

const ClosedInterval& LineSegment::getDomainX() const {
	return domainX;
}

const ClosedInterval& LineSegment::getDomainY() const {
	return domainY;
}

LineSegment::operator Line() const {
	return getLine();
}
