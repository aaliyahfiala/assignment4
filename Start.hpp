#ifndef __START_HPP
#define __START_HPP

#include "Event.hpp"

class Start : public Event {
public: 
	Start();
	virtual std::string get_percept();
	virtual ~Start();
};

#endif
