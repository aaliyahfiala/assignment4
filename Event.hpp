/*********************************************************************
 * ** Program Filename: Event.hpp
 * ** Description: This is the Event class definition file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <iostream>

class Event {
private:
	std::string percept;
public:
	Event();
	virtual std::string get_percept() = 0;
	virtual ~Event();
};

#endif
