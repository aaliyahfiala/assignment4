#ifndef __WUMPUS_HPP
#define __WUMPUS_HPP

#include "Event.hpp"

class Wumpus : public Event {
public: 
	Wumpus();
	virtual std::string get_percept();
	virtual ~Wumpus();
};

#endif
