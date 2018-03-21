#pragma once

#include <istream>
#include <SFML/Graphics.hpp>

class Vector2fSerializer {

public:

	explicit Vector2fSerializer::Vector2fSerializer(std::istream& stream);

	Vector2fSerializer(const Vector2fSerializer&) = delete;
	Vector2fSerializer& operator=(const Vector2fSerializer&) = delete;

	void Vector2fSerializer::serialize(sf::Vector2f& vector);

private:

	void Vector2fSerializer::loadVector();
	void Vector2fSerializer::discardSeparator();

	std::istream& stream;

	char separator;
	sf::Vector2f result;

};