#include "ConvexShapeImporter.h"
#include "ConvexShapeMaker.h"
#include <stdexcept>
#include <vector>

ConvexShapeImporter::ConvexShapeImporter(std::istream& stream)
	: stream(stream) { }

void ConvexShapeImporter::importConvexShape(sf::ConvexShape& convexShape) {
	
	std::vector<sf::Vector2f> points;

	while(stream) {
		points.push_back(importOnePoint());
		stream >> std::ws;
		stream.peek(); // try next character
	}

	ConvexShapeMaker convexShapeMaker(points);
	convexShape = convexShapeMaker.makeConvexShape();

}

sf::Vector2f ConvexShapeImporter::importOnePoint() {

	sf::Vector2f point;
	char separator;
	
	stream >> point.x;

	stream >> separator;
	checkSeparator(separator);

	stream >> point.y;

	return point;

}

void ConvexShapeImporter::checkSeparator(char separator) {
	if(separator != ',') {
		throw std::runtime_error("invalid separator found during loading data from stream");
	}
}

std::istream& operator>>(std::istream& stream, sf::ConvexShape& convexShape) {
	ConvexShapeImporter importer(stream);
	importer.importConvexShape(convexShape);
	return stream;
}
