#include "Updateable.h"

Updateable::Updateable()
	: enabled(false) { }

void Updateable::update(float time) {

	if(isEnabled()) {
		doUpdate(time);
	}

}

bool Updateable::isEnabled() const {
	return enabled;
}

void Updateable::enable() {
	enabled = true;
}

void Updateable::disable() {
	enabled = false;
}