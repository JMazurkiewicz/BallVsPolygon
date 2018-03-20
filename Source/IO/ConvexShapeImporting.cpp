#include "ConvexShapeImporting.h"

#include "ConvexShape/ConvexShapeMaker.h"
#include <vector>

std::istream& operator>>(std::istream& stream, sf::ConvexShape& convexShape) {

	std::vector<sf::Vector2f> points;

	for(sf::Vector2f point; stream >> point; ) {
		points.push_back(point);
	}

	ConvexShapeMaker convexShapeMaker(points);
	convexShape = convexShapeMaker.makeConvexShape();

	return stream;

}
