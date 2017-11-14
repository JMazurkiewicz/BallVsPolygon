#include <cmath>
#include "Physics/Basics/Line.h"
#include <stdexcept>

Line::Line() : a(0), b(1), c(0) { }

Line::Line(const sf::Vector2f& pointA, const sf::Vector2f& pointB) {
	assignLinePassingThroughTwoPoints(pointA, pointB);
}

void Line::assignLinePassingThroughTwoPoints(const sf::Vector2f& pointA, const sf::Vector2f& pointB) {
	
	a = -(pointB.y - pointA.y);
	b = pointB.x - pointA.x;
	c = pointA.x * (pointB.y-pointA.y) - pointA.y * (pointB.x-pointA.x);
	 
}

bool Line::isParallelTo(const Line& other) const {

	return a*other.b - other.a*b == 0;

}

float Line::distanceFromPoint(const sf::Vector2f& point) const {

	return abs(a*point.x + b*point.y + c) / sqrt(a*a + b*b);

}

sf::Vector2f Line::getCommonPoint(const Line& other) const {
	
	throwIfHasNoCommonPoint(other);

	const float wab = a*other.b - other.a*b;
	const float wbc = b*other.c - other.b*c;
	const float wca = c*other.a - other.c*a;

	return sf::Vector2f(wbc/wab, wca/wab);
	
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
		throw std::logic_error("lines doesn't intersect");
	}
}
