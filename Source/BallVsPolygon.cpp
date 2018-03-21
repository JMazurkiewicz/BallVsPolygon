#include <cstdlib>
#include <exception>
#include <iomanip>
#include "Display/MainWindow.h"
#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Timer.h"

class BallVsPolygon {

public:

	BallVsPolygon() = default;

	BallVsPolygon(const BallVsPolygon&) = delete;
	BallVsPolygon& operator=(const BallVsPolygon&) = delete;

	void run() {

		timer.restart();

		while(window.isOpen()) {

			listenForEvents();
			updateObjects();
			displayNewView();

		}

	}

private:

	void listenForEvents() {

		for(sf::Event event; window.pollEvent(event); ) {

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

		const Timer::Seconds ellapsedTime = timer.getEllapsedTime();

		ball.update(ellapsedTime.count());
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

	} catch(const std::exception& e) {

		sf::err() << "Fatal error occured, application will be terminated\n";
		sf::err() << "what(): " << std::quoted(e.what()) << '\n';
		return EXIT_FAILURE;

	}

}