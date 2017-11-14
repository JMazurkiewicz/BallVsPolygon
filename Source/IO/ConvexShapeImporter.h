#pragma once

#include <istream>
#include <SFML/Graphics.hpp>

class ConvexShapeImporter {

public:

	ConvexShapeImporter(std::istream& stream);
	void importConvexShape(sf::ConvexShape& convexShape);

private:

	std::istream& stream;

};

std::istream& operator>>(std::istream& stream, sf::ConvexShape& convexShape);