#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Timer.h"
#include <SFML/Graphics.hpp>

// Opis b³êdu w odbijaniu pi³ki:
// Pi³ka jest odbijana po zetkniêciu siê z ca³¹ lini¹, nie tylko z jej fragmentem ograniczonym punktami.
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