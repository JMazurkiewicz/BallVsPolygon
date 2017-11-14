#include "Physics/AxialSymmetry.h"

AxialSymmetry::AxialSymmetry(const StraightLine& axis)
	: axis(axis) { }

sf::Vector2f AxialSymmetry::getSymmetricalVector(const sf::Vector2f& vector) {
	return sf::Vector2f();
}
