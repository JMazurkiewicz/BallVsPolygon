#pragma once

#include <istream>
#include <SFML/System/Vector2.hpp>

class Vector2fSerializer {

public:

	explicit Vector2fSerializer(std::istream& stream);

	Vector2fSerializer(const Vector2fSerializer&) = delete;
	Vector2fSerializer& operator=(const Vector2fSerializer&) = delete;

	void serialize(sf::Vector2f& vector);

private:

	void loadVector();
	void discardSeparator();

	std::istream& stream;

	sf::Vector2f result;

};