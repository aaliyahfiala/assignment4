/*********************************************************************
 * ** Program Filename: Cave.hpp
 * ** Description: This is the Cave class definition file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef __CAVE_HPP
#define __CAVE_HPP

#include <vector>
#include <utility>

#include "Room.hpp"

class Cave {
private:
	int cave_size;
	std::vector<std::vector<Room> > cave; // change to user specified size

public:
	Cave(); //sets it to a 4 * 4
	Cave(int n); //user defined
	
	void operator=(const Cave& c);

	Room get_location(int x, int y); //retruns cave[x][y]
	
	void bats(); //give 2 rand rooms bat
	void pits(); //give 2 rand rooms pits 
	void gold(); //give 1 room gold 
	void wumpus(); //give 1 room wumpus
	std::pair<int, int> start(); //determine starting/end room
	
	void percepts(int x, int y); //where [a][b] is positiong, displays message if event is up/down/left/right
	void clear_room(int x, int y); 
	bool wumpus_nearby(int x, int y);
};

#endif
