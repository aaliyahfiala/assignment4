/*********************************************************************
 * ** Program Filename: Event.cpp
 * ** Description: This is the Event class funtion definition file
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#include "Event.hpp"

Event::Event() : percept("No Percept"){}

std::string Event::get_percept() {
	return this->percept;
}

Event::~Event() {}
