#pragma once

#include <istream>
#include "Serialization/Vector2fSerializer.h"
#include <SFML/Graphics.hpp>
#include <vector>

class ConvexShapeSerializer {

public:

	explicit ConvexShapeSerializer(std::istream& stream);

	ConvexShapeSerializer(const ConvexShapeSerializer&) = delete;
	ConvexShapeSerializer& operator=(const ConvexShapeSerializer&) = delete;

	void serialize(sf::ConvexShape& convexShape);

private:

	void loadPoints();
	void loadOnePoint();

	std::istream& stream;
	Vector2fSerializer vectorSerializer;

	std::vector<sf::Vector2f> points;

};