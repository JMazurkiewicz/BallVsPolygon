#pragma once

class ClosedInterval {

public:

	ClosedInterval(float beginValue, float endValue);

	bool contains(float value) const;

	float begin() const;
	float end() const;

private:

	float beginValue, endValue;

};