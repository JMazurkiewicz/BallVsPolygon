#include <cmath>
#include "Physics/Basics/Velocity.h"

sf::Vector2f Velocity::getDistanceVector(float time) {

	return (*this) * time;

}