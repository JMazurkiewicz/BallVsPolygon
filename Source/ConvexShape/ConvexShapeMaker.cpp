#include "ConvexShape/ConvexShapeMaker.h"
#include <stdexcept>

ConvexShapeMaker::ConvexShapeMaker(const std::vector<sf::Vector2f>& points) 
	: points(points) {

	checkPoints();

}

sf::ConvexShape ConvexShapeMaker::makeConvexShape() {
	
	sf::ConvexShape shape(points.size());
	
	for(std::size_t i = 0; i < points.size(); ++i) {
		shape.setPoint(i, points[i]);
	}

	return shape;

}

void ConvexShapeMaker::checkPoints() {

	if(points.size() < 3) {
		throw std::runtime_error("too little points were given");
	}

}
