#pragma once

class Updateable {

public:

	Updateable();

	void update(float time);

	bool isEnabled() const;
	void enable();

protected:

	virtual void doUpdate(float time) = 0;

private:

	bool enabled;

};