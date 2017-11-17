#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Timer.h"
#include <SFML/Graphics.hpp>

// Do refaktoryzacji:
// 1) Klasa 'Ball', 'BallBouncer'
// ---2) Zmiana systemu liczenia czasu, a co za tym idzie prêdkoœci (czas bêdzie zewnêtrzny, wspólny dla wszystkich)
// 3) Naprawa b³êdów w odbijaniu pi³ki
//
// Do implementacji:
// 1) Pauza za pomoc¹ spacji,
// 2) Mo¿liwoœæ ustawienia pi³ki w losowym miejscu z losowym wektorem prêdkoœci.

class BallVsPolygon {

public:

	BallVsPolygon() : window(sf::VideoMode(1200, 600), "BallVsPolygon") { }

	void run() {

		gameTimer.restart();

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

		const float ellapsedTime = gameTimer.getEllapsedTime();

		ball.update(ellapsedTime);
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
	Timer gameTimer;

};

int main() {

	BallVsPolygon app;
	app.run();

}