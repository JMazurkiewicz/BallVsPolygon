#pragma once

#include "Objects/PhysicalObject.h"
#include "Objects/Updateable.h"
#include <SFML/Graphics.hpp>

class Ball : public Updateable, public PhysicalObject, public sf::CircleShape {

public:

	explicit Ball(float radius);

	Ball(const Ball&) = delete;
	Ball& operator=(const Ball&) = delete;

	virtual void update(float time) override;

private:

	void initBallStyle();

};