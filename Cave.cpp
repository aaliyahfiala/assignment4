/*********************************************************************
 * ** Program Filename: Cave.hpp
 * ** Description: This is the Cave funtion definitions file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "Cave.hpp"
#include <stdlib.h> //for rand and srand
#include <time.h> //for time

/*********************************************************************
 * ** Function: Cave()
 * ** Description: Default constructor for the cave class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
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

/*********************************************************************
 * ** Function: Cave()
 * ** Description: Parameterized constructor for the cave class
 * ** Parameters: cave_size
 * ** Pre-Conditions: none
 * ** Post-Conditions: cave is intialized
 * *********************************************************************/ 
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

/*********************************************************************
 * ** Function: operator=()
 * ** Description: Assignment overload for the assignment operator
 * ** Parameters: const Cave& c
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
void Cave::operator=(const Cave& c) {
	this->cave_size = c.cave_size;
	for (int i = 0, j = 0; i < cave.size() && j < cave.size(); i++, j++) {
		this->cave[i][j] = c.cave[i][j];
	}
}

/*********************************************************************
* ** Function: get_location
* ** Description: returns the room in the cave at specified location
* ** Parameters: int x, int y
* ** Pre-Conditions: none
* ** Post-Conditions: room is asscceible
* *********************************************************************/ 
Room Cave::get_location(int x, int y) {
	Room r = this->cave[x][y];
	return r;
}

/*********************************************************************
 * ** Function: bats()
 * ** Description: Puts two bats in the cave
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: two bats are randomly placed
 * *********************************************************************/ 
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
//		std::cout << "Bats at (" << x << ", " << y << ")." << std::endl;
	}
}

/*********************************************************************
 * ** Function: pits()
 * ** Description: randomly puts pits in the cave
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: pits are allocated
 * *********************************************************************/ 
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
//		std::cout << "Pits at (" << x << ", " << y << ")." << std::endl;
	}
}

/*********************************************************************
 * ** Function: gold()
 * ** Description: randomly puts gold in the cave
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: gold is placed
 * *********************************************************************/ 
void Cave::gold() { //give 1 room gold 
	srand(time(NULL));
	int x, y;
	
	do {
		x = rand() % cave_size;
		y = rand() % cave_size;

	} while(cave.at(x).at(y).has_event());
	
	cave.at(x).at(y).give_gold();

	//FOR TESTING PURPOSES DELETE LATER
//	std::cout << "Gold at (" << x << ", " << y << ")." << std::endl;
}

/*********************************************************************
 * ** Function: wumpus()
 * ** Description: randomly puts a wumpus in the cave
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: wumpus is placed
 * *********************************************************************/ 
void Cave::wumpus() { //give 1 room wumpus
	srand(time(NULL));
	int x, y;
	
	do {
		x = rand() % cave_size;
		y = rand() % cave_size;
	
	} while(cave.at(x).at(y).has_event());
	
	cave.at(x).at(y).give_wumpus();

	//FOR TESTING PURPOSES DELETE LATER
//	std::cout << "Wumpus at (" << x << ", " << y << ")." << std::endl;
}

/*********************************************************************
 * ** Function:start()
 * ** Description: determines the starting point in the cave
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: start is placed
 * *********************************************************************/ 
std::pair<int, int> Cave::start() { //determine starting/end room and return x, y coordinates
	srand(time(NULL));
	int x, y;
	
	do {
		x = rand() % cave_size;
		y = rand() % cave_size;
	
	} while(cave.at(x).at(y).has_event());
	
	cave.at(x).at(y).give_start();

	//FOR TESTING PURPOSES DELETE LATER
//	std::cout << "Starting point at (" << x << ", " << y << ")." << std::endl;

	return std::make_pair(x,y);
}
 
/*********************************************************************
 * ** Function: percepts()
 * ** Description: Displays percepts in respective rooms in the cave
 * ** Parameters: int x, int y
 * ** Pre-Conditions: none
 * ** Post-Conditions: percepts are displayed to screen
 * *********************************************************************/ 
void Cave::percepts(int x, int y) {
//where [a][b] is positiong, displays message if event is up/down/left/right
	if (y != (cave_size - 1)) {
		if (cave.at(x).at(y + 1).has_event())
			std::cout << cave.at(x).at(y + 1).display_percept() << std::endl;
	}
	
	if (x != 0) {
		if (cave.at(x - 1).at(y).has_event())
			std::cout << cave.at(x - 1).at(y).display_percept() << std::endl;
	}

	if (x != (cave_size - 1)) {
		if (cave.at(x + 1).at(y).has_event())
			std::cout << cave.at(x + 1).at(y).display_percept() << std::endl;
	}

	if (y != 0) {
		if (cave.at(x).at(y - 1).has_event())
			std::cout << cave.at(x).at(y - 1).display_percept() << std::endl;
	}
}

/*********************************************************************
 * ** Function: clear_room()
 * ** Description: deletes the event place in the room
 * ** Parameters: int x, int y
 * ** Pre-Conditions: none
 * ** Post-Conditions: event is deleted (changed to an event object)
 * *********************************************************************/ 
void Cave::clear_room(int x, int y) { //clear that rooms event
	cave.at(x).at(y).delete_event();
}

/*********************************************************************
 * ** Function: wumpus_nearby()
 * ** Description: determines if the wumpus percept has been displayed
 * ** Parameters: int x, int y
 * ** Pre-Conditions: none
 * ** Post-Conditions: wumpus nearby is returned true or false
 * *********************************************************************/ 
bool Cave::wumpus_nearby(int x, int y) {
	bool w_nearby = false; 

	if (y != (cave_size - 1)) {
		if (cave.at(x).at(y + 1).has_wumpus())
			w_nearby = true;
	}
	
	if (x != 0) {
		if (cave.at(x - 1).at(y).has_wumpus())
			w_nearby = true;
	}

	if (x != (cave_size - 1)) {
		if (cave.at(x + 1).at(y).has_wumpus())
			w_nearby = true;
	}

	if (y != 0) {
		if (cave.at(x).at(y - 1).has_wumpus())
			w_nearby = true;
	}

	return w_nearby;	
}

