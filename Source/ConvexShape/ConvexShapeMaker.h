#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class ConvexShapeMaker {

public:

	explicit ConvexShapeMaker(const std::vector<sf::Vector2f>& points);

	sf::ConvexShape makeConvexShape() const;

private:

	void throwIfPointCountIsTooSmall() const;

	const std::vector<sf::Vector2f>& points;

};