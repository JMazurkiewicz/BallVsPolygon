#include <exception>
#include <iostream>
#include "Physics/Timer.h"
#include "Runtime/EventListener.h"
#include "Runtime/MainWindow.h"
#include "Runtime/ObjectManager.h"

class Application : private EventListener {

public:

	Application() : EventListener(window) { }

	void run() {

		while(window.isOpen()) {

			listenForEvents();

			objects.updateObjects(timer.getEllapsedTime().count());
			
			window.clear();
			objects.drawObjects(window);
			window.display();

		}

	}

private:

	virtual void handleKeyEvent(const sf::Event::KeyEvent& event) override {

		if(event.code == sf::Keyboard::Space) {
			switchPause();
		}

	}

	virtual void handleMouseButtonEvent(const sf::Event::MouseButtonEvent& event) override {

		if(event.button == sf::Mouse::Left) {

			const sf::Vector2f newBallPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
			objects.restartBall(newBallPosition);

		}

	}
	
	void switchPause() {
		timer.switchMode();
	}
	
	MainWindow window;
	ObjectManager objects;
	Timer timer;

};

int main() {

	try {

		Application app;
		app.run();

	} catch(std::exception& exception) {

		std::cerr << "Fatal error occured, application will be terminated.\n";
		std::cerr << "what():\n" << exception.what();

	}

}