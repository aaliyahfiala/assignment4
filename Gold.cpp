/*********************************************************************
 * ** Program Filename: Gold.cpp
 * ** Description: This is the Gold class funtion definition file
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#include "Gold.hpp"

/*********************************************************************
 * ** Function: Gold()
 * ** Description: Default constructor for the gold class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
Gold::Gold() {}

/*********************************************************************
 * ** Function: get_percept()
 * ** Description: returns the percpt for the gold class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
std::string Gold::get_percept() {
	return "You see a glimmer nearby.";
}

/*********************************************************************
 * ** Function: ~Gold()
 * ** Description: Default destructor for the Gold class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
Gold::~Gold() {}

