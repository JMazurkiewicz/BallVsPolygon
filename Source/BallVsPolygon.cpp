#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include <SFML/Graphics.hpp>

// Przed nowymi dodatkami nale�y dokona� refaktoryzacji kodu.
//
// Do implementacji:
// 1) Pauza za pomoc� spacji,
// 2) Mo�liwo�� ustawienia pi�ki w losowym miejscu z losowym wektorem pr�dko�ci.

class BallVsPolygon {

public:

	BallVsPolygon() : window(sf::VideoMode(1200, 600), "BallVsPolygon") { }

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
		ball.bounceOnCollisionWith(polygon);

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