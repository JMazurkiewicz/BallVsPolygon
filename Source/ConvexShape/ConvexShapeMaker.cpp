#include "ConvexShapeMaker.h"

#include <stdexcept>

ConvexShapeMaker::ConvexShapeMaker(const std::vector<sf::Vector2f>& points) : points(points) {

	throwIfPointCountIsTooSmall();

}

sf::ConvexShape ConvexShapeMaker::makeConvexShape() const {
	
	sf::ConvexShape shape(points.size());
	
	for(std::size_t index = 0; index < points.size(); ++index) {
		shape.setPoint(index, points[index]);
	}

	return shape;

}

void ConvexShapeMaker::throwIfPointCountIsTooSmall() const {

	using namespace std::string_literals;

	if(points.size() < 3) {

		throw std::runtime_error(
			static_cast<char>('0' + points.size()) +
			" point(s) were given to ConvexShapeMaker (at least 3 points are required)"s
		);

	}

}
