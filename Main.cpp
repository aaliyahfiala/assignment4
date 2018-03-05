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
#include "Dummy.hpp"

int main(int argc, char *argv[]) {
	char play_again = '0';
	int break_loop = 0;
	
	if (atoi(argv[1]) < 4) {
		std::cout << "Map is too small!" << std::endl;
		return 1;
	}

	Player p = atoi(argv[1]);	
	dPlayer d = atoi(argv[1]);

	std::cout << "Do you want to play, or let the dummy do it? p/d" << std::endl;		
	char play = 'd';
	std::cin >> play;

	if (play == 'p') {
//	Player p;
		do{
	
			do {
				std::cout << "\nYou have " << p.get_arrows() << " arrows." << std::endl;
			
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
	
				if (p.is_game_over() == true) {
					break_loop = 1;
				}

				if (p.is_game_won() == true) {
					break_loop = 1;
				}
			
			} while (break_loop == 0);	
	
			std::cout << "Would you like to play again? y/n" << std::endl;
			std::cin >> play_again;
		
			if (play_again == 'y') {
				std::cout << "\nWould like to play with the same map or a new one? s/n" << std::endl;
				p.reset_game();

				char map = '0';
				std::cin >> map;
				if (map == 'n') {
					Player new_p = atoi(argv[1]);
					p = new_p;
				}
			}
		} while (play_again == 'y'); 

	} else {
		d.play_game();
	}

	return 0;
}

