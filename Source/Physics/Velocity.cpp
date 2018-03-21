#include "Velocity.h"

Velocity::Velocity(const sf::Vector2f& vector)
	: sf::Vector2f(vector) { }

sf::Vector2f Velocity::calculateDistanceVector(float time) const {
	return (*this) * time;
}