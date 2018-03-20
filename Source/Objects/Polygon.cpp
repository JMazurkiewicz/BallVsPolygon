#include "Polygon.h"

#include <fstream>
#include "IO/ConvexShapeImporting.h"
#include <stdexcept>

Polygon::Polygon() {

	loadPointsFromFile();
	makePolygonStyle();

}

LineSegment Polygon::getSide(std::size_t index) const {

	const std::size_t beginIndex = index;
	const std::size_t endIndex = (index + 1 == getPointCount()) ? (0) : (index + 1);

	return LineSegment(getPoint(beginIndex), getPoint(endIndex));

}

void Polygon::loadPointsFromFile() {

	std::ifstream file("points.txt");

	if(!file.is_open()) {
		throw std::ios_base::failure("file \"points.txt\" doesn\'t exist");
	}

	file >> *this;

}

void Polygon::makePolygonStyle() {

	setFillColor(sf::Color{0, 0, 0, 0});

	setOutlineColor(sf::Color::White);
	setOutlineThickness(1.0F);

}
