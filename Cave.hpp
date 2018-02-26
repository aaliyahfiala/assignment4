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

	std::pair<int, int> get_location(int x, int y); //outpput spot in array if cave[a][b], (a, b)

	void bats(); //give 2 rand rooms bat
	void pits(); //give 2 rand rooms pits 
	void gold(); //give 1 room gold 
	void wumpus(); //give 1 room wumpus
	std::pair<int, int> start(); //determine starting/end room
	
	std::string percepts(int x, int y); //where [a][b] is positiong, displays message if event is up/down/left/right
};

#endif
