#include "ConvexShape/ConvexShapeMaker.h"
#include "IO/ConvexShapeImporter.h"
#include "IO/VectorImporter.h"
#include <stdexcept>
#include <vector>

ConvexShapeImporter::ConvexShapeImporter(std::istream& stream)
	: stream(stream) { }

void ConvexShapeImporter::importConvexShape(sf::ConvexShape& convexShape) {
	
	std::vector<sf::Vector2f> points;

	for(sf::Vector2f point; stream >> point; ) {
		points.push_back(point);
	}

	ConvexShapeMaker convexShapeMaker(points);
	convexShape = convexShapeMaker.makeConvexShape();

}

std::istream& operator>>(std::istream& stream, sf::ConvexShape& convexShape) {

	ConvexShapeImporter importer(stream);
	importer.importConvexShape(convexShape);
	return stream;

}
