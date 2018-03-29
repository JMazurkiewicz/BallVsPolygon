#pragma once

#include <memory>
#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include <SFML/Graphics.hpp>

class ObjectManager {

public:

	void drawObjects(sf::RenderWindow& window);
	void updateObjects(float time);

	void restartBall(const sf::Vector2f& newPosition);

private:

	void checkCollisions();

	void createBallIfItIsNotActive();
	bool isBallActive() const;

	std::unique_ptr<Ball> ball;
	Polygon polygon;

};