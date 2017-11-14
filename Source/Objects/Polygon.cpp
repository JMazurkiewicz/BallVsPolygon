#include <fstream>
#include "IO/ConvexShapeImporter.h"
#include "Objects/Polygon.h"

Polygon::Polygon() {

	loadPointsFromFile();

	setFillColor(sf::Color::Black);

	setOutlineColor(sf::Color::White);
	setOutlineThickness(1);

}

void Polygon::loadPointsFromFile() {
	std::ifstream file("points.txt");
	file >> *this;
}
