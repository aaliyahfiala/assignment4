/*********************************************************************
 * ** Program Filename: Player.hpp
 * ** Description: This is the Player class definition file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include <utility> //for pair
#include <stdlib.h>//for rand and srand
#include <time.h>//for time
#include "Cave.hpp"

class Player {
private:
	Cave cave;
	int cave_size;
	int arrows;
	char direction;
	
	int x;//the players cave row
	int y;//the players cave column
	int x_start;
	int y_start;

	bool game_over;
	bool game_won;
	bool has_gold;
	bool killed_wumpus;

public:
	Player();
	Player(int cave_size);
	
	bool is_game_over();
	bool is_game_won();
	int get_arrows();
	void shoot_arrow();

	void move_around();
	void room_check();
};

#endif
