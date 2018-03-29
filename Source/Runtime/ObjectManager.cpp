#include "ObjectManager.h"

#include "Collisions/BallBouncer.h"
#include "Collisions/CollisionChecker.h"
#include "Physics/RandomVelocityGenerator.h"

namespace {
	constexpr float BALL_VELOCITY = 300.0F;
	constexpr float BALL_RADIUS = 20.0F;
}

void ObjectManager::drawObjects(sf::RenderWindow& window) {
	
	if(isBallActive()) {
		window.draw(*ball);
	}

	window.draw(polygon);

}

void ObjectManager::updateObjects(float time) {

	if(isBallActive()) {
		ball->update(time);
		checkCollisions();
	}

}

void ObjectManager::restartBall(const sf::Vector2f& newPosition) {

	createBallIfItIsNotActive();

	ball->setPosition(newPosition);

	RandomVelocityGenerator velocityGenerator(BALL_VELOCITY);
	ball->setVelocity(velocityGenerator.generate());

}

void ObjectManager::checkCollisions() {

	CollisionChecker collisionChecker(*ball);

	if(collisionChecker.didCollisionHappenWith(polygon)) {
		
		BallBouncer bouncer(*ball);
		bouncer.bounceFrom(collisionChecker.getCollidedSide());

	}

}

void ObjectManager::createBallIfItIsNotActive() {

	if(!isBallActive()) {
		ball = std::make_unique<Ball>(BALL_RADIUS);
	}

}

bool ObjectManager::isBallActive() const {
	return ball != nullptr;
}