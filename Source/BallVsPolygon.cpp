#include "Ball.h"
#include "ConvexShapeImporter.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <fstream>

// Zrobi� klas� Polygon dziedzicz�c� po sf::ConvexShape
// Uporz�dkowa� klas� BallVsPolygon (g��wn�)
// Upodz�dkowa� struktur� folder�w

class BallVsPolygon {

public:

	BallVsPolygon() : window(sf::VideoMode(1200, 600), "Title", sf::Style::Titlebar) {
		
		preparePolygon();
		prepareBall();

	}

	void run() {

		while(window.isOpen()) {

			closeIfSpaceIsPressed();
			updateObjects();
			displayNewView();

		}

	}

private:

	void preparePolygon() {

		loadPolygonFromFile();
		
		polygon.setFillColor(sf::Color::Black);

		polygon.setOutlineColor(sf::Color::White);
		polygon.setOutlineThickness(1);

	}

	void loadPolygonFromFile() {

		std::ifstream file("points.txt");
		file >> polygon;

	}

	void prepareBall() { }

	void closeIfSpaceIsPressed() {

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			window.close();
		}

	}

	void updateObjects() {

		ball.move();

	}

	void displayNewView() {

		window.clear();

		window.draw(polygon);
		window.draw(ball);

		window.display();

	}


	Ball ball;
	sf::ConvexShape polygon;
	sf::RenderWindow window;

};

int main() {

	BallVsPolygon app;
	app.run();

}