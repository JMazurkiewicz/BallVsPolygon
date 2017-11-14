#include "IO/VectorImporter.h"
#include <stdexcept>

VectorImporter::VectorImporter(std::istream& stream)
	: stream(stream) { }

void VectorImporter::importVector(sf::Vector2f& vector) {

	stream >> vector.x;

	if(stream.good()) {
		getSeparator();
		stream >> vector.y;
	}

}

void VectorImporter::getSeparator() {

	char separator;
	stream >> separator;
	throwSeparatorIsInvalid(separator);

}

void VectorImporter::throwSeparatorIsInvalid(char separator) {

	if(separator != ',') {
		stream.setstate(std::ios_base::failbit);
		throw std::runtime_error("invalid separator found during loading vector from stream");
	}

}

std::istream& operator>>(std::istream& stream, sf::Vector2f& vector) {

	VectorImporter importer(stream);
	importer.importVector(vector);
	return stream;

}