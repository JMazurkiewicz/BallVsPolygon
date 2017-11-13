#pragma once

#include <SFML/Graphics.hpp>

class Polygon : public sf::ConvexShape {

public:

	Polygon();

private:

	void loadFromFile();

};