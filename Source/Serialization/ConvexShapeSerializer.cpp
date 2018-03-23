#include "ConvexShapeSerializer.h"

#include "ConvexShape/ConvexShapeMaker.h"

ConvexShapeSerializer::ConvexShapeSerializer(std::istream& stream)
	: stream(stream), vectorSerializer(stream) { }

void ConvexShapeSerializer::serialize(sf::ConvexShape& convexShape) {

	loadPoints();

	if(!stream.fail()) {
		ConvexShapeMaker shapeMaker(points);
		convexShape = shapeMaker.makeConvexShape();
	}

}

void ConvexShapeSerializer::loadPoints() {

	while(!stream.eof()) {
		loadOnePoint();
	}

}

void ConvexShapeSerializer::loadOnePoint() {

	sf::Vector2f point;
	vectorSerializer.serialize(point);

	if(stream) {
		points.push_back(point);
		stream >> std::ws;
	}

}
