#pragma once

#include <SFML/Graphics.hpp>

class MainWindow : public sf::RenderWindow {

public:

	MainWindow();

	MainWindow(const MainWindow&) = delete;
	MainWindow& operator=(const MainWindow&) = delete;

};