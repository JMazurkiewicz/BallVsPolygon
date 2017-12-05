#include <algorithm>
#include "Physics/Basics/LineSegment.h"

LineSegment::LineSegment(const sf::Vector2f& pointA, const sf::Vector2f& pointB)
	: line(pointA, pointB) {

	auto interval = std::minmax(pointA.x, pointB.x);
	begin = interval.first;
	end = interval.second;

}

const Line & LineSegment::getLine() const {
	return line;
}

float LineSegment::getBegin() const {
	return begin;
}

float LineSegment::getEnd() const {
	return end;
}
