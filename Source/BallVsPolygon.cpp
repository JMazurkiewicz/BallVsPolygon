#include "Management/MainWindow.h"
#include "Management/ObjectManager.h"
#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Timer.h"

class BallVsPolygon {

public:

	void run() {

		gameTimer.restart();

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

			}

		}

	}

	void updateObjects() {

		const float ellapsedTime = gameTimer.getEllapsedTime();
		objects.updateObjects(ellapsedTime);

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			objects.setBallPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		}

	}

	void displayNewView() {

		window.clear();
		objects.drawObjects(window);
		window.display();

	}
	
	MainWindow window;
	ObjectManager objects;
	Timer gameTimer;

};

int main() {

	BallVsPolygon app;
	app.run();

}