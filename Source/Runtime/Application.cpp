#include "Collisions/CollisionChecker.h"
#include <exception>
#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/RandomVelocityGenerator.h"
#include "Physics/Timer.h"
#include "Runtime/MainWindow.h"

namespace {

	constexpr float BALL_VELOCITY = 300.0F;
	constexpr float BALL_RADIUS = 20.0F;

}

class Application {

public:

	Application() : ball(BALL_RADIUS) { }

	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;

	void run() {

		while(window.isOpen()) {

			listenForEvents();
			updateObjects();
			displayNewView();

		}

	}

private:

	void listenForEvents() {

		for(sf::Event event; window.pollEvent(event); ) {
			processEvent(event);
		}

	}
	
	void processEvent(const sf::Event& event) {

		switch(event.type) {

		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::KeyPressed:
			processPressedKey(event.key.code);
			break;

		case sf::Event::MouseButtonPressed:
			processPressedMouseButton(event.mouseButton.button);
			break;

		}

	}

	void processPressedKey(sf::Keyboard::Key key) {

		if(key == sf::Keyboard::Space) {
			switchPause();
		}

	}

	void processPressedMouseButton(sf::Mouse::Button button) {

		if(button == sf::Mouse::Left) {
			restartBall();
		}

	}

	void updateObjects() {

		const Timer::Seconds ellapsedTime = timer.getEllapsedTime();

		ball.Updateable::update(ellapsedTime.count());
		checkCollisions();

	}

	void checkCollisions() {

		CollisionChecker collisionChecker(ball);

		if(collisionChecker.didCollisionHappenWith(polygon)) {
			ball.bounceFromLine(collisionChecker.getCollidedSide());
		}

	}

	void displayNewView() {

		window.clear();

		window.draw(ball);
		window.draw(polygon);

		window.display();

	}
	
	void switchPause() {
		timer.switchMode();
	}
	
	void restartBall() {

		const sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		ball.setPosition(mousePosition);
		
		RandomVelocityGenerator velocityGenerator(BALL_VELOCITY);
		ball.setVelocity(velocityGenerator.generate());

		ball.enable();

	}
	
	MainWindow window;

	Ball ball;
	Polygon polygon;

	Timer timer;

};

int main() {

	try {

		Application app;
		app.run();

	} catch(const std::exception& e) {

		sf::err() << "Fatal error occured, application will be terminated\n";
		sf::err() << "what(): \"" << e.what() << "\"\n";

	}

}