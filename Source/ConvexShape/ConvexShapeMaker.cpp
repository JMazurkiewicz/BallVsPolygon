#include "ConvexShape/ConvexShapeMaker.h"
#include <cstddef>
#include <stdexcept>

ConvexShapeMaker::ConvexShapeMaker(const std::vector<sf::Vector2f>& points)
	: points(points) {

	throwIfPointCountIsTooSmall();

}

sf::ConvexShape ConvexShapeMaker::makeConvexShape() const {
	
	sf::ConvexShape shape(points.size());
	
	for(std::size_t i = 0; i < points.size(); ++i) {
		shape.setPoint(i, points[i]);
	}

	return shape;

}

void ConvexShapeMaker::throwIfPointCountIsTooSmall() const {

	if(points.size() < 3) {
		throw std::logic_error("too little points were given");
	}

}
