#pragma once

#include <SFML/System/Vector2.hpp>

class Line {

public:

	Line();
	explicit Line(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);

	void assignLinePassingThroughPoints(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);

	float GetCParam() const;
	sf::Vector2f getNormalVector() const;

	bool isParallelTo(const Line& other) const;

	float getDistanceFromPoint(const sf::Vector2f& point) const;
	float getDistanceFromLine(const Line& other) const;

	sf::Vector2f getCommonPointWith(const Line& other) const;

	Line getParallelLinePassingThroughPoint(const sf::Vector2f& point) const;
	Line getPerpendicularLinePassingThroughPoint(const sf::Vector2f& point) const;

private:

	float a, b, c;

	void throwIfLinesAreNotParallel(const Line& other) const;
	void throwIfPointsAreNotOnOneLine(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const;
	void throwIfLinesHaveNoCommonPoint(const Line& other) const;

};