#include "ConvexShape/ConvexShapeImporter.h"
#include <fstream>
#include "Objects/Polygon.h"

Polygon::Polygon() {

	loadFromFile();

	setFillColor(sf::Color::Black);

	setOutlineColor(sf::Color::White);
	setOutlineThickness(1);

}

void Polygon::loadFromFile() {
	std::ifstream file("points.txt");
	file >> *this;
}
