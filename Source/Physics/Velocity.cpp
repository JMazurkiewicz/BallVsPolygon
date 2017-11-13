#include <cmath>
#include "Physics/Velocity.h"

void Velocity::restart() {
	stopwatch.restart();
}

sf::Vector2f Velocity::getDistanceVector() {
	return (*this) * stopwatch.getEllapsedTime(); // s=v*Δt
}