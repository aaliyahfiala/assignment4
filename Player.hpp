/*********************************************************************
 * ** Program Filename: Player.hpp
 * ** Description: This is the Player class definition file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include <utility> //for pair
#include "Cave.hpp"

class Player {
private:
	Cave cave;
	int cave_size;
	int arrows;
	char direction;
	int x;//the players cave row
	int y;//the players cave column

public:
	Player();
	Player(int cave_size);

	int get_arrows();
	void shoot_arrow();

	void move_around();
	void room_check();
};

#endif
