#pragma once

#include "Objects/DynamicObject.h"
#include "Objects/Updateable.h"
#include <SFML/Graphics.hpp>

class Ball : public Updateable, public DynamicObject, public sf::CircleShape {

public:

	explicit Ball(float radius);

	Ball(const Ball&) = delete;
	Ball& operator=(const Ball&) = delete;

	virtual void update(float time) override;

private:

	void initBallStyle();

};