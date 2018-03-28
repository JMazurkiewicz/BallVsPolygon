#pragma once

#include "Objects/PhysicalObject.h"
#include "Objects/Polygon.h"
#include "Objects/Updateable.h"
#include "Physics/Velocity.h"
#include <SFML/Graphics.hpp>

class Ball : public Updateable, public PhysicalObject, public sf::CircleShape {

public:

	explicit Ball(float radius, float velocity);

	sf::FloatRect makeRectangle() const;

	void bounceOnCollisionWith(const Polygon& polygon);

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:

	virtual void doUpdate(float time) override;

};