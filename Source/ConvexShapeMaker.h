#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class ConvexShapeMaker {

public:

	ConvexShapeMaker(const std::vector<sf::Vector2f>& points);
	sf::ConvexShape makeConvexShape();

private:

	void checkPoints();

	const std::vector<sf::Vector2f>& points;

};