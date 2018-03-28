#include "Vector2fSerializer.h"

Vector2fSerializer::Vector2fSerializer(std::istream& stream)
	: stream(stream) { }

void Vector2fSerializer::serialize(sf::Vector2f& vector) {

	loadVector();

	if(!stream.fail()) {
		vector = result;
	}

}

void Vector2fSerializer::loadVector() {

	if(stream >> result.x) {

		discardSeparator();
		if(stream) {
			stream >> result.y;
		}

	}

}

void Vector2fSerializer::discardSeparator() {

	char separator;

	if(stream >> separator) {
		if(separator != ',') {
			stream.setstate(std::ios_base::failbit);
		}
	}

}
