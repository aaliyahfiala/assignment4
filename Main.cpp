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
	
	char play_again = '0';

/*	Player p = atoi(argv[1]);	
	if (atoi(argv[1]) < 4) {
		std::cout << "Map is too small!" << std::endl;
		return 1;
	}*/

	Player p;
	do{

		do {

			std::cout << "You have " << p.get_arrows() << " arrows." << std::endl;
			
			std::cout << "Would you like to move or shoot an arrow? m/a" << std::endl;
			char turn = '0';

			std::cin >> turn;

			if (turn == 'a') {
				p.shoot_arrow();
			}
			
			if (turn == 'm') {
				p.move_around();
			}

			p.room_check();

		} while (!p.is_game_over() || !p.is_game_won());	
	
		std::cout << "Would you like to play again? y/n" << std::endl;
		std::cin >> play_again;
		
		if (play_again == 'y') {
			std::cout << "Would like to play with the same map or a new one? s/n" << std::endl;
			char map = '0';
			std::cin >> map;
			if (map == 'n') {
				Player new_p;
				p = new_p;
			}
		}
	} while (play_again == 'y');
	
	return 0;
}

