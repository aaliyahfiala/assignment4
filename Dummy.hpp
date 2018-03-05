/*********************************************************************
 * ** Program Filename: Dummy.hpp
 * ** Description: This is the dummy Player class definition file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef __DUMMY_HPP_
#define __DUMMY_HPP

#include <utility> //for pair
#include <stdlib.h>//for rand and srand
#include <time.h>//for time
#include "Cave.hpp"

class dPlayer {
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
	dPlayer(int cave_size);

	bool is_game_over();
	bool is_game_won();
	int get_arrows();
	void shoot_arrow();

	void move_around();
	void room_check();
	
	int rand_pick(int a, int b);
	void play_game();
};

#endif
