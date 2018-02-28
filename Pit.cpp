/*********************************************************************
 * ** Program Filename: Pit.cpp
 * ** Description: This is the Pit class funtion definition file
 * ** Input: none
 * ** Output: none
 * ********************************************************************/
#include "Pit.hpp"

/*********************************************************************
 * ** Function: Pit()
 * ** Description: Default constructor for the start class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
Pit::Pit() {}

/*********************************************************************
 * ** Function: get_percept()
 * ** Description: returns percept for the pit class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
std::string Pit::get_percept() {
	return "You feel a breeze.";
}

/*********************************************************************
 * ** Function: ~Pit()
 * ** Description: Default destructor for the pit class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
Pit::~Pit() {}
