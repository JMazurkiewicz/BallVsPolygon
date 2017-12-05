#pragma once

class ClosedInterval {

public:

	ClosedInterval(float begin, float end);
	bool contains(float value) const;

private:

	float begin, end;

};