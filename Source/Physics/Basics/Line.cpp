#include <cmath>
#include "Physics/Basics/Line.h"
#include <stdexcept>

Line::Line() : a(0), b(1), c(0) { }

Line::Line(const sf::Vector2f& pointA, const sf::Vector2f& pointB) {

	assignLinePassingThroughTwoPoints(pointA, pointB);

}

void Line::assignLinePassingThroughTwoPoints(const sf::Vector2f& pointA, const sf::Vector2f& pointB) {

	const float d = (pointB.x - pointA.x);
	const float e = (pointB.y - pointA.y);

	a = -e;
	b = d;
	c = e*pointA.x - d*pointA.y;
	 
}

bool Line::isParallelTo(const Line& other) const {

	return a*other.b - other.a*b == 0;

}

sf::Vector2f Line::getCommonPoint(const Line& other) const {

	throwIfHasNoCommonPoint(other);

	const float ab = a*other.b - other.a*b;
	const float bc = b*other.c - other.b*c;
	const float ca = c*other.a - other.c*a;

	return sf::Vector2f(bc/ab, ca/ab);

}

float Line::getDistanceFromPoint(const sf::Vector2f& point) const {

	return abs(a*point.x + b*point.y + c) / sqrt(a*a + b*b);

}

Line Line::getPerpendicularLinePassingThroughPoint(const sf::Vector2f& point) const {

	Line perpendicularLine;

	perpendicularLine.a = b;
	perpendicularLine.b = -a;
	perpendicularLine.c = a*point.y - b*point.x;

	return perpendicularLine;

}

void Line::throwIfHasNoCommonPoint(const Line& other) const {

	if(isParallelTo(other)) {
		throw std::logic_error("lines don't intersect");
	}

}
