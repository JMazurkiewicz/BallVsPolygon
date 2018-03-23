#include "Line.h"

#include <cmath>
#include <stdexcept>

Line::Line() : a(0), b(1), c(0) { }

Line::Line(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) {
	assignLinePassingThroughTwoPoints(firstPoint, secondPoint);
}

void Line::assignLinePassingThroughTwoPoints(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) {

	if(firstPoint == secondPoint) {
		throwBecausePointsAreNotOnOneLine();
	}

	a = secondPoint.y - firstPoint.y;
	b = firstPoint.x - secondPoint.x;
	c = secondPoint.x*firstPoint.y - firstPoint.x*secondPoint.y;
	 
}

bool Line::isParallelTo(const Line& other) const {
	return a*other.b - other.a*b == 0;
}

float Line::getDistanceFromPoint(const sf::Vector2f& point) const {
	return std::abs(a*point.x + b*point.y + c) / std::sqrt(a*a + b*b);
}

sf::Vector2f Line::getCommonPointWith(const Line& other) const {

	if(isParallelTo(other)) {
		throwBecauseLinesHaveNoCommonPoint(other);
	}

	const float ab = a*other.b - other.a*b;
	const float bc = b*other.c - other.b*c;
	const float ca = c*other.a - other.c*a;

	return sf::Vector2f(bc/ab, ca/ab);

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

void Line::throwBecausePointsAreNotOnOneLine() const {
	throw std::logic_error("unable to make a line from given points (they are not on one line)");
}

void Line::throwBecauseLinesHaveNoCommonPoint(const Line& other) const {

	const char* message;

	if(c == other.c) {
		message = "lines are the same";
	} else {
		message = "lines don't intersect";
	}

	throw std::logic_error(message);

}
