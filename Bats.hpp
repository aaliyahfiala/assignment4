/*********************************************************************
 * ** Program Filename: Bats.hpp
 * ** Description: This is the Bats class definition file
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#ifndef __BATS_HPP
#define __BATS_HPP

#include "Event.hpp"

class Bats : public Event {
public:
	Bats();
	virtual std::string get_percept();
	virtual ~Bats();
};

#endif
