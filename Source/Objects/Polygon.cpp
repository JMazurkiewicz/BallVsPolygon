#include <exception>
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

	try {

		std::ifstream file("points.txt");
		file >> *this;

	} catch(std::exception& e) {

		sf::err() << "An error occurred during importing polygon from file:";
		sf::err() << '\t\"' << e.what() << "\"\n";
		throw;

	}

}
