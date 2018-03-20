#include "ConvexShapeImporting.h"

#include <ios>
#include <string>

class VectorImporter {

public:

	VectorImporter(std::istream& stream)
		: stream(stream) { }

	void importVector(sf::Vector2f& vector) {

		if(stream >> vector.x) {
			discardSeparator();
			stream >> vector.y;
		}

	}

private:

	void discardSeparator() {

		stream >> separator;
		
		if(separator != ',') {
			throwBecauseSeparatorIsInvalid();
		}

	}

	[[noreturn]]
	void throwBecauseSeparatorIsInvalid() {

		using namespace std::string_literals;

		stream.setstate(std::ios_base::failbit);
		throw std::ios_base::failure(
			"invalid separator found during loading vector from stream (expected \',\', got \'"s +
			separator +
			"\')"
		);

	}

	std::istream& stream;
	char separator;

}; 

std::istream& operator>>(std::istream& stream, sf::Vector2f& vector) {

	VectorImporter importer(stream);
	importer.importVector(vector);
	return stream;

}