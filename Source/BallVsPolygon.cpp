#include "Management/MainWindow.h"
#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Timer.h"

class BallVsPolygon {

public:

	void run() {

		timer.restart();

		while(window.isOpen()) {

			checkEvents();
			updateObjects();
			displayNewView();

		}

	}

private:

	void checkEvents() {

		sf::Event event;

		while(window.pollEvent(event)) {

			if(event.type == sf::Event::Closed) {

				window.close();

			} else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {

				timer.switchMode();

			} 

		}

	}

	void updateObjects() {

		const float ellapsedTime = timer.getEllapsedTime();

		ball.update(ellapsedTime);
		ball.bounceOnCollisionWith(polygon);

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			ball.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			ball.activate();
		}

	}

	void displayNewView() {

		window.clear();
		
		window.draw(ball);
		window.draw(polygon);

		window.display();

	}
	
	MainWindow window;
	Timer timer;

	Ball ball;
	Polygon polygon;

};

int main() {

	BallVsPolygon app;
	app.run();

}