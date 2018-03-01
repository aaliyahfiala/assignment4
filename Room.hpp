/*********************************************************************
 * ** Program Filename: Room.hpp
 * ** Description: This is the Room class definition file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef __ROOM_HPP
#define __ROOM_HPP

#include <iostream>
#include "Event.hpp"


//QUESTION: Am I doing this accuratley? 
#include "Bats.hpp"
#include "Pit.hpp"
#include "Wumpus.hpp"
#include "Gold.hpp"
#include "Start.hpp"

class Room {
private:
	Event* event;
	char event_type;
public:
	Room();
	~Room();
	
	std::string display_percept();

	void give_bat();
	void give_pit();
	void give_wumpus();
	void give_gold();
	void give_start();

	bool has_event();
	bool has_bat();
	bool has_pit();
	bool has_wumpus();
	bool has_gold();
	bool is_start();
};

#endif
