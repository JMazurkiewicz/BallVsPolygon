#include "Display/MainWindow.h"
#include <exception>
#include <iomanip>
#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/RandomVelocityGenerator.h"
#include "Physics/Timer.h"

namespace {

	constexpr float BALL_VELOCITY = 50;

}

class BallVsPolygon {

public:

	BallVsPolygon() : ball(20, BALL_VELOCITY) { }

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

		ball.Updateable::update(ellapsedTime.count());
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
		
		RandomVelocityGenerator velocityGenerator(BALL_VELOCITY);
		ball.setVelocity(velocityGenerator.generate());

		ball.enable();

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
		sf::err() << "what(): \"" << e.what() << "\"\n";

	}

}