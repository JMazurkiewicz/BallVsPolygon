#pragma once

#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Line.h"

class CollisionChecker {

public:

	CollisionChecker(const Ball& ball, const Polygon& polygon);

	bool didCollisionHappen();
	Line getCollidedSide() const;

private:

	sf::Vector2f getBeginingOfLine(std::size_t sideIndex) const;
	sf::Vector2f getEndingOfLine(std::size_t sideIndex) const;

	bool didCollisionHappenWithSide(const sf::Vector2f& begining, const sf::Vector2f& endng) const;
	
	const Ball& ball;
	const Polygon& polygon;

	Line collisionSide;

};