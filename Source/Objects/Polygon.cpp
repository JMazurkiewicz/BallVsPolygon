#include "Polygon.h"

#include <fstream>
#include "Serialization/ConvexShapeSerializer.h"
#include <stdexcept>

Polygon::Polygon() {

	loadPointsFromFile();
	initPolygonStyle();

}

LineSegment Polygon::getSide(std::size_t index) const {

	if(index >= getPointCount()) {
		throwBecauseIndexIsInvalid();
	}

	const std::size_t firstPointIndex = index;
	const std::size_t secondPointIndex = (index + 1 == getPointCount()) ? (0) : (index + 1);

	return LineSegment(getPoint(firstPointIndex), getPoint(secondPointIndex));

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

void Polygon::throwBecauseIndexIsInvalid() const {
	throw std::out_of_range("Polygon::getSide(): invalid index");
}
