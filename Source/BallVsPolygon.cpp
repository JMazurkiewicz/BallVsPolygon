#include "Objects/Ball.h"
#include "Objects/Polygon.h"
#include "Physics/Basics/Timer.h"
#include <SFML/Graphics.hpp>

// 2) Mo�liwo�� ustawienia pi�ki w losowym miejscu z losowym wektorem pr�dko�ci (przy rozpocz�ciu)

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

			} else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {

				pause();

			}

		}

	}

	void pause() {

		while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
		gameTimer.restart();

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