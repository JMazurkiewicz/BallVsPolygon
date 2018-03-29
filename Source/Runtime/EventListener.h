#pragma once

#include <SFML/Window.hpp>

class EventListener {

public:

	explicit EventListener(sf::Window& window);

	void listenForEvents();

protected:

	virtual void handleKeyEvent(const sf::Event::KeyEvent& event) = 0;
	virtual void handleMouseButtonEvent(const sf::Event::MouseButtonEvent& event) = 0;

private:

	sf::Window& window;

	void processEvent(const sf::Event& event);

};