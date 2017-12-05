#include "Physics/AxialSymmetry.h"

AxialSymmetry::AxialSymmetry(const Line& axis) : axis(axis) {

	prepareAxis();

}

sf::Vector2f AxialSymmetry::getSymmetricalVector(const sf::Vector2f& vector) {

	const Line perpendicularLine = axis.getPerpendicularLinePassingThroughPoint(vector);
	sf::Vector2f commonPoint = axis.getCommonPoint(perpendicularLine);

	return 2.0f * commonPoint - vector;

}

void AxialSymmetry::prepareAxis() {

	axis.c = 0
		;
}
