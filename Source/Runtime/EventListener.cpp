#include "EventListener.h"

EventListener::EventListener(sf::Window& window)
	: window(window) { }

void EventListener::listenForEvents() {

	for(sf::Event event; window.pollEvent(event); ) {
		processEvent(event);
	}

}

void EventListener::processEvent(const sf::Event& event) {

	switch(event.type) {

	case sf::Event::Closed:
		window.close();
		break;

	case sf::Event::KeyPressed:
		handleKeyEvent(event.key);
		break;

	case sf::Event::MouseButtonPressed:
		handleMouseButtonEvent(event.mouseButton);
		break;

	}

}