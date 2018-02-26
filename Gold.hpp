#ifndef __GOLD_HPP
#define __GOLD_HPP

#include "Event.hpp"

class Gold : public Event {
public: 
	Gold();
	virtual std::string get_percept();
	virtual ~Gold();
};
#endif
