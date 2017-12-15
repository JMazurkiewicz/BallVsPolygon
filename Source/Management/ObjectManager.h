#pragma once

#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include <SFML/Graphics.hpp>

class ObjectManager {

public:

	void setBallPosition(const sf::Vector2f& position);
	void updateObjects(float time);
	void drawObjects(sf::RenderWindow& target);

private:

	Ball ball;
	Polygon polygon;

};