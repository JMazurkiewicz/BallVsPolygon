#include "Physics/Basics/LineSegment.h"

LineSegment::LineSegment(const sf::Vector2f& first, const sf::Vector2f& second)
	: line(first, second), domain(first.x, second.x) { }

const Line& LineSegment::getLine() const {
	return line;
}

const ClosedInterval& LineSegment::getDomain() const {
	return domain;
}

LineSegment::operator Line() const {
	return getLine();
}
