#pragma once

#include "Objects/Polygon.h"
#include "Physics/Basics/Velocity.h"
#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape {

public:

	Ball();

	const Velocity& getVelocity() const;
	void setVelocity(const Velocity& velocity);

	bool isActive() const;
	void activate();

	void update(float time);
	void bounceOnCollisionWith(const Polygon& polygon);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:

	Velocity velocity;
	bool activity;

};