#include "Event.hpp"

Event::Event() : percept(""){}

std::string Event::get_percept() {
	return this->percept;
}

Event::~Event() {}
