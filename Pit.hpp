/*********************************************************************
 * ** Program Filename: Pit.hpp
 * ** Description: This is the Pit class definition file
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#ifndef __PIT_HPP
#define __PIT_HPP

#include "Event.hpp"

class Pit : public Event { 
public:
	Pit();
	virtual std::string get_percept();
	virtual ~Pit();
};

#endif
