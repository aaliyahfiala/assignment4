#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <iostream>

class Event {
private:
	std::string percept;
public:
	Event();
	virtual std::string get_percept();
	virtual ~Event();


};

#endif
