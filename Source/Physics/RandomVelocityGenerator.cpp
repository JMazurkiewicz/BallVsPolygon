#include "RandomVelocityGenerator.h"

#include <cmath>
#include "Math/Constants.h"

std::mt19937 RandomVelocityGenerator::generator(std::random_device{}());

RandomVelocityGenerator::RandomVelocityGenerator(float velocityValue)
	: velocityValue(velocityValue) { }

Velocity RandomVelocityGenerator::generate() {
	
	std::uniform_real_distribution<float> angleDistribtion(0, 2 * Math::PI);
	const float angle = angleDistribtion(generator);

	const float x = velocityValue * std::cos(angle);
	const float y = velocityValue * std::sin(angle);

	return Velocity(x, y);

}
