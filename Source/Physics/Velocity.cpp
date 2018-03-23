#include "Velocity.h"

sf::Vector2f Velocity::calculateDistanceVector(float time) const {
	return (*this) * time;
}