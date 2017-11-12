#pragma once

#include <istream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class ConvexShapeImporter {

public:

	ConvexShapeImporter(std::istream& stream);
	void importConvexShape(sf::ConvexShape& convexShape);

private:

	sf::Vector2f importOnePoint();
	void checkSeparator(char separator);

	std::istream& stream;

};

std::istream& operator>>(std::istream& stream, sf::ConvexShape& convexShape);