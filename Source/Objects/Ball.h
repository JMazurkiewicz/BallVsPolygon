#pragma once

#include "Objects/Polygon.h"
#include "Physics/Velocity.h"
#include <SFML/Graphics/CircleShape.hpp>

class Ball : public sf::CircleShape {

public:

	Ball();

	const Velocity& getVelocity() const;
	void setVelocity(const Velocity& velocity);

	sf::FloatRect makeRectangle() const;

	bool isEnabled() const;
	void enable();

	void randomizeVelocityVector();

	void update(float time);
	void bounceOnCollisionWith(const Polygon& polygon);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:

	void bounceFromSide(const Line& side);

	Velocity velocity;
	bool enabled;

};