/*********************************************************************
 * ** Program Filename: Cave.hpp
 * ** Description: This is the Cave funtion definitions file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "Cave.hpp"
#include <stdlib.h> //for rand and srand
#include <time.h> //for time


Cave::Cave() : cave_size(4) {
	for (int i = 0; i < 4; i++) {
		std::vector<Room> row;
		for (int j = 0; j < 4; j++) {
			Room r;
			row.push_back(r);
		}
		cave.push_back(row);
	}

	pits();
	bats();
	wumpus();
	gold();
}

Cave::Cave(int n) : cave_size(n) {
	for (int i = 0; i < n; i++) {
		std::vector<Room> row;
		for (int j = 0; j < n; j++) {
			Room r;
			row.push_back(r);
		}
		cave.push_back(row);
	}

	pits();
	bats();
	wumpus();
	gold();
}
	
Room Cave::get_location(int x, int y) {
	return cave[x][y];
}

void Cave::bats() { //give 2 rand rooms bat
	srand(time(NULL));
	int x, y;
	
	for (int i = 0; i < 2; i++ ) {
	
		do {
			x = rand() % cave_size;
			y = rand() % cave_size;
	
		} while(cave.at(x).at(y).has_event());
	
		cave.at(x).at(y).give_bat();

		//FOR TESTING PURPOSES DELETE LATER
		std::cout << "Bats at (" << x << ", " << y << ")." << std::endl;
	}
}

void Cave::pits() { //give 2 rand rooms pits 
	srand(time(NULL));
	int x, y;
	
	for (int i = 0; i < 2; i++ ) {
	
		do {
			x = rand() % cave_size;
			y = rand() % cave_size;
	
		} while(cave.at(x).at(y).has_event());
	
		cave.at(x).at(y).give_pit();

		//FOR TESTING PURPOSES DELETE LATER
		std::cout << "Pits at (" << x << ", " << y << ")." << std::endl;
	}
}

void Cave::gold() { //give 1 room gold 
	srand(time(NULL));
	int x, y;
	
	do {
		x = rand() % cave_size;
		y = rand() % cave_size;

	} while(cave.at(x).at(y).has_event());
	
	cave.at(x).at(y).give_gold();

	//FOR TESTING PURPOSES DELETE LATER
	std::cout << "Gold at (" << x << ", " << y << ")." << std::endl;
}

void Cave::wumpus() { //give 1 room wumpus
	srand(time(NULL));
	int x, y;
	
	do {
		x = rand() % cave_size;
		y = rand() % cave_size;
	
	} while(cave.at(x).at(y).has_event());
	
	cave.at(x).at(y).give_wumpus();

	//FOR TESTING PURPOSES DELETE LATER
	std::cout << "Wumpus at (" << x << ", " << y << ")." << std::endl;
}

std::pair<int, int> Cave::start() { //determine starting/end room and return x, y coordinates
	srand(time(NULL));
	int x, y;
	
	do {
		x = rand() % cave_size;
		y = rand() % cave_size;
	
	} while(cave.at(x).at(y).has_event());
	
	cave.at(x).at(y).give_start();

	//FOR TESTING PURPOSES DELETE LATER
	std::cout << "Starting point at (" << x << ", " << y << ")." << std::endl;

	return std::make_pair(x,y);
}
 

void Cave::percepts(int x, int y){
//where [a][b] is positiong, displays message if event is up/down/left/right
	if (x != (cave_size - 1) && y != (cave_size - 1)) {
		if (cave.at(x + 1).at(y + 1).has_event())
			std::cout << cave.at(x + 1).at(y + 1).display_percept() << std::endl;
	}
	
	if (x != 0 && y != (cave_size - 1)) {
		if (cave.at(x - 1).at(y + 1).has_event())
			std::cout << cave.at(x - 1).at(y + 1).display_percept() << std::endl;
	}

	if (x != (cave_size - 1) && y != 0) {
		if (cave.at(x + 1).at(y - 1).has_event())
			std::cout << cave.at(x + 1).at(y - 1).display_percept() << std::endl;
	}

	if (x != 0 && y != 0) {
		if (cave.at(x - 1).at(y - 1).has_event())
			std::cout << cave.at(x - 1).at(y - 1).display_percept() << std::endl;
	}
}
