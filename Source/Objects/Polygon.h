#pragma once

#include <cstddef>
#include "Math/LineSegment.h"
#include <SFML/Graphics.hpp>

class Polygon : public sf::ConvexShape {

public:

	Polygon();

	LineSegment getSide(std::size_t index) const;

private:

	void loadPointsFromFile();
	void initPolygonStyle();

};