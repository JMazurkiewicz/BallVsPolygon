#include "Polygon.h"

#include <fstream>
#include "IO/ConvexShapeSerializer.h"
#include <stdexcept>

Polygon::Polygon() {
	loadPointsFromFile();
	initPolygonStyle();
}

LineSegment Polygon::getSide(std::size_t index) const {

	const std::size_t beginIndex = index;
	const std::size_t endIndex = (index + 1 == getPointCount()) ? (0) : (index + 1);

	return LineSegment(getPoint(beginIndex), getPoint(endIndex));

}

void Polygon::loadPointsFromFile() {

	std::ifstream file("points.txt");
	file.exceptions(std::ios_base::failbit);

	ConvexShapeSerializer shapeSerializer(file);
	shapeSerializer.serialize(*this);

}

void Polygon::initPolygonStyle() {

	setFillColor(sf::Color{0, 0, 0, 0});

	setOutlineColor(sf::Color::White);
	setOutlineThickness(1.0F);

}
