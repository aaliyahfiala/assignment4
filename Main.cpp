/*********************************************************************
 * ** Program Filename: Main.cpp
 * ** Author: Aaliyah Fiala
 * ** Date: 3/5/18
 * ** Description: This is the implimination file of the game Hunt the Wumpus
 * ** Input: grid size
 * ** Output: a fun game of hunt the wumpus
 * *********************************************************************/
#include <iostream> 

#include "Player.hpp"
#include "Cave.hpp"
#include "Room.hpp"
#include "Event.hpp"

int main(int argc, char *argv[]) {
	
	Cave c;

	//Player p(argc);	

	Player p;

	p.get_arrows();

	p.shoot_arrow();

	std::cout << "Number of arrows = " << p.get_arrows() << std::endl;

	if (p.get_arrows() == 0) {
		std::cout << "Your ran out of arrows. Game over." << std::endl;
		return 1;//change to exit loop
	}

	p.move_around();

	return 0;
}

