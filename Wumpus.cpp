/*********************************************************************
 * ** Program Filename: Wumpus.hpp
 * ** Description: This is the Wumpus class funtion definition file
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#include "Wumpus.hpp"

/*********************************************************************
 * ** Function: Wumpus()
 * ** Description: Default constructor for the wumpus class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
Wumpus::Wumpus() {}

/*********************************************************************
 * ** Function: get_percept()
 * ** Description: returns the percept for the wumpus class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
std::string Wumpus::get_percept() {
	return "You smell a terrible stench.";
}

/*********************************************************************
 * ** Function: ~Wumpus()
 * ** Description: Default destructor for the wumpus class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
Wumpus::~Wumpus() {}

