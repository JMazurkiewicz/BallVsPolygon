#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class ConvexShapeMaker {

public:

	ConvexShapeMaker(const std::vector<sf::Vector2f>& points);

	sf::ConvexShape makeConvexShape() const;

private:

	[[noreturn]]
	void throwBecausePointCountIsTooSmall() const;

	const std::vector<sf::Vector2f>& points;

};