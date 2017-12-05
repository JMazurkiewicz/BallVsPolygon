#include "Physics/AxialSymmetry.h"

AxialSymmetry::AxialSymmetry(const Line& axis)
	: axis(axis.getParallelLinePassingThroughPoint(sf::Vector2f(0, 0))) { }

sf::Vector2f AxialSymmetry::getSymmetricalVector(const sf::Vector2f& vector) {

	const Line perpendicularLine = axis.getPerpendicularLinePassingThroughPoint(vector);
	const sf::Vector2f commonPoint = axis.getCommonPoint(perpendicularLine);

	return 2.0f*commonPoint - vector;

}