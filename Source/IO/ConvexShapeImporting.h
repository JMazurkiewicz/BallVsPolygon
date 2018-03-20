#pragma once

#include <istream>
#include <SFML/Graphics.hpp>

std::istream& operator>>(std::istream& stream, sf::Vector2f& vector);
std::istream& operator>>(std::istream& stream, sf::ConvexShape& convexShape);