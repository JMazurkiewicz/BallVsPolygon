#include <cstdlib>
#include <exception>
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

				switchPause();

			} else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {

				setBallPositionToMousePosition();

			}

		}

	}

	void updateObjects() {

		const float ellapsedTime = timer.getEllapsedTime();

		ball.update(ellapsedTime);
		ball.bounceOnCollisionWith(polygon);

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
	
	void setBallPositionToMousePosition() {

		const sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		ball.setPosition(mousePosition);
		ball.activate();

	}
	
	MainWindow window;
	Timer timer;

	Ball ball;
	Polygon polygon;

};

int main() {

	try {

		BallVsPolygon app;
		app.run();

	} catch(const std::exception&) {

		sf::err() << "Fatal error occured, application will be terminated";
		return EXIT_FAILURE;

	}

}