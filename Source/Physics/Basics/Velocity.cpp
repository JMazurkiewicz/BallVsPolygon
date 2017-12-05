#include "Physics/Basics/Velocity.h"

Velocity::Velocity(const sf::Vector2f& vector)
	: sf::Vector2f(vector) { }

sf::Vector2f Velocity::getDistanceVector(float time) {

	return (*this) * time;

}