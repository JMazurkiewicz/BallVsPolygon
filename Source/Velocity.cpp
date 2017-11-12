#include "Velocity.h"

void Velocity::restart() {
	stopwatch.restart();
}

void Velocity::moveObject(sf::Transformable& object) {
	object.move(computateDistanceVector());
}

sf::Vector2f Velocity::computateDistanceVector() {
	return (*this) * stopwatch.getEllapsedTime(); // s=vΔt
}