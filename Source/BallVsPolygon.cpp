#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Timer.h"
#include <SFML/Graphics.hpp>

// Opis b��du w odbijaniu pi�ki:
// Pi�ka jest odbijana po zetkni�ciu si� z ca�� lini�, nie tylko z jej fragmentem ograniczonym punktami.
//
// Do implementacji:
// 1) Pauza za pomoc� spacji,
// 2) Mo�liwo�� ustawienia pi�ki w losowym miejscu z losowym wektorem pr�dko�ci.

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