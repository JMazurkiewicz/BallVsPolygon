#pragma once

#include <istream>
#include <SFML/Graphics.hpp>

class VectorImporter {

public:

	VectorImporter(std::istream& stream);
	void importVector(sf::Vector2f& vector);

private:

	void getSeparator();
	void throwIfSeparatorIsInvalid(char separator);

	std::istream& stream;

};

std::istream& operator>>(std::istream& stream, sf::Vector2f& vector);