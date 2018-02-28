/*********************************************************************
 * ** Program Filename: Wumpus.hpp
 * ** Description: This is the Wumpus class defintion
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#ifndef __WUMPUS_HPP
#define __WUMPUS_HPP

#include <iostream>
#include "Event.hpp"

class Wumpus : public Event {
public: 
	Wumpus();
	virtual std::string get_percept();
	virtual ~Wumpus();
};

#endif
