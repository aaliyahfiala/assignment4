/*********************************************************************
 * ** Program Filename: Event.cpp
 * ** Description: This is the Event class funtion definition file
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#include "Event.hpp"

/*********************************************************************
 * ** Function: Event()
 * ** Description: Default constructor for the Event class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
Event::Event() : percept("No Percept"){}

/*********************************************************************
 * ** Function: get_percept()
 * ** Description: makes the virtual percept function accessible
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
std::string Event::get_percept() {
	return this->percept;
}

/*********************************************************************
 * ** Function: ~Event()
 * ** Description: Default destructor for the event class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
Event::~Event() {
}
