#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include <SFML/Graphics.hpp>

class BallVsPolygon {

public:

	BallVsPolygon() : window(sf::VideoMode(1200, 600), "Title", sf::Style::Titlebar) { }

	void run() {

		while(window.isOpen()) {

			closeIfSpaceIsPressed();
			updateObjects();
			displayNewView();

		}

	}

private:

	void closeIfSpaceIsPressed() {

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			window.close();
		}

	}

	void updateObjects() {

		ball.update();

	}

	void displayNewView() {

		window.clear();

		window.draw(polygon);
		window.draw(ball);

		window.display();

	}


	Ball ball;
	Polygon polygon;
	sf::RenderWindow window;

};

int main() {

	BallVsPolygon app;
	app.run();

}