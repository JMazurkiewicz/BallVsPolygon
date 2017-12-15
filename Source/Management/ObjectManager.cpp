#include "ObjectManager.h"

void ObjectManager::setBallPosition(const sf::Vector2f& position) {
	
	ball.setPosition(position);

}

void ObjectManager::updateObjects(float time) {

	ball.update(time);
	ball.bounceOnCollisionWith(polygon);

}

void ObjectManager::drawObjects(sf::RenderWindow& target) {

	target.draw(ball);
	target.draw(polygon);

}
