/*********************************************************************
 * ** Program Filename: Main.cpp
 * ** Author: Aaliyah Fiala
 * ** Date: 3/5/18
 * ** Description: This is the implimination file of the game Hunt the Wumpus
 * ** Input: grid size
 * ** Output: a fun game of hunt the wumpus
 * *********************************************************************/
#include <iostream> 
#include <string>
#include <stdlib.h>

#include "Player.hpp"
#include "Cave.hpp"
#include "Room.hpp"
#include "Event.hpp"

int main(int argc, char *argv[]) {
	
//	Player p = atoi(argv[1]);	
//insert error, cant have less than 4 * 4 return 1;

	Player p;

	do {

		std::cout << "You have " << p.get_arrows() << " arrows." << std::endl;
	
		p.move_around();

		p.shoot_arrow();
		
		p.room_check();

	} while (p.is_game_over() == true || p.is_game_won() == true);	

	return 0;
}

