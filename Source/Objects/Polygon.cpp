#include <exception>
#include <fstream>
#include "IO/ConvexShapeImporter.h"
#include "Objects/Polygon.h"

Polygon::Polygon() {

	loadPointsFromFile();

	setFillColor(sf::Color(0, 0, 0, 0));

	setOutlineColor(sf::Color::White);
	setOutlineThickness(1);

}

LineSegment Polygon::getSide(std::size_t index) const {

	const std::size_t beginIndex = index;
	const std::size_t endIndex = (index + 1 == getPointCount()) ? (0) : (index + 1);

	return LineSegment(getPoint(beginIndex), getPoint(endIndex));

}

void Polygon::loadPointsFromFile() {

	try {

		std::ifstream file("points.txt");
		file >> *this;

	} catch(std::exception& e) {

		sf::err() << "An error occurred during importing polygon from file:";
		sf::err() << '\t\"' << e.what() << "\"\n";
		throw;

	}

}
