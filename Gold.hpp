/*********************************************************************
 * ** Program Filename: Gold.cpp
 * ** Description: This is the Gold class definition file
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#ifndef __GOLD_HPP
#define __GOLD_HPP

#include <iostream>
#include "Event.hpp"

class Gold : public Event {
public: 
	Gold();
	virtual std::string get_percept();
	virtual ~Gold();
};
#endif
