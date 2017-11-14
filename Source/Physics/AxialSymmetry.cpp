#include "Physics/AxialSymmetry.h"

AxialSymmetry::AxialSymmetry(const StraightLine& axis) : axis(axis) {
	prepareAxis();
}

sf::Vector2f AxialSymmetry::getSymmetricalVector(const sf::Vector2f& vector) {

	const StraightLine perpendicularLine = axis.getPerpendicularLineGoingThrough(vector);
	sf::Vector2f commonPoint = axis.getCommonPoint(perpendicularLine);

	return sf::Vector2f(2*commonPoint.x - vector.x, 2*commonPoint.y - vector.y);

}

void AxialSymmetry::prepareAxis() {
	axis.c = 0;
}
