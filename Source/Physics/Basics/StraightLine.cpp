#include <cmath>
#include "Physics/Basics/StraightLine.h"
#include <stdexcept>

StraightLine::StraightLine() : a(0), b(1), c(0) { }

StraightLine::StraightLine(const sf::Vector2f& pointA, const sf::Vector2f& pointB) :
	a{-(pointB.y - pointA.y)},
	b{pointB.x - pointA.x},
	c{pointA.x * (pointB.y-pointA.y) - pointA.y * (pointB.x-pointA.x)} { }

bool StraightLine::isParallel(const StraightLine& other) const {
	return a*other.b - other.a*b == 0;
}

float StraightLine::distanceFromPoint(const sf::Vector2f& point) const {

	return abs(a*point.x + b*point.y + c) / sqrt(a*a + b*b);

}

sf::Vector2f StraightLine::getCommonPoint(const StraightLine& other) const {
	
	if(isParallel(other)) {
		throw std::logic_error("lines doesn't intersect");
	}

	// Punkt przeciêcia prostych obliczny zgodnie ze wzorem:
	// https://pl.wikipedia.org/wiki/Prosta#Wzajemne_po.C5.82o.C5.BCenie_na_p.C5.82aszczy.C5.BAnie

	const float wab = a*other.b - other.a*b;
	const float wbc = b*other.c - other.b*c;
	const float wca = c*other.a - other.c*a;

	return sf::Vector2f(wbc/wab, wca/wab);
	
}

StraightLine StraightLine::getPerpendicularLineGoingThrough(const sf::Vector2f& point) const {

	StraightLine perpendicularLine;

	perpendicularLine.a = b;
	perpendicularLine.b = -a;
	perpendicularLine.c = a*point.y - b*point.x;

	return perpendicularLine;

}
