#include <cmath>
#include "Physics/Basics/Line.h"
#include <stdexcept>

Line::Line() : a(0), b(1), c(0) { }

Line::Line(const sf::Vector2f& first, const sf::Vector2f& second) {

	assignLinePassingThroughTwoPoints(first, second);

}

void Line::assignLinePassingThroughTwoPoints(const sf::Vector2f& first, const sf::Vector2f& second) {

	throwIfUnableToMakeALine(first, second);

	const float d = (second.x - first.x);
	const float e = (second.y - first.y);

	a = -e;
	b = d;
	c = e*first.x - d*first.y;
	 
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

	return std::abs(a*point.x + b*point.y + c) / std::sqrt(a*a + b*b);

}

Line Line::getParallelLinePassingThroughPoint(const sf::Vector2f& point) const {
	
	Line parallelLine;

	parallelLine.a = a;
	parallelLine.b = b;
	parallelLine.c = -a*point.x - b*point.y;

	return parallelLine;

}

Line Line::getPerpendicularLinePassingThroughPoint(const sf::Vector2f& point) const {

	Line perpendicularLine;

	perpendicularLine.a = b;
	perpendicularLine.b = -a;
	perpendicularLine.c = a*point.y - b*point.x;

	return perpendicularLine;

}

void Line::throwIfUnableToMakeALine(const sf::Vector2f& first, const sf::Vector2f& second) const {

	if(first == second) {
		throw std::logic_error("unable to make a line from given points");
	}

}

void Line::throwIfHasNoCommonPoint(const Line& other) const {

	if(isParallelTo(other)) {
		if(c == other.c) {
			throw std::logic_error("lines are the same");
		} else {
			throw std::logic_error("lines don't intersect");
		}
	}

}
