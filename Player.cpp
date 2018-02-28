/*********************************************************************
 * ** Program Filename: Player.cpp
 * ** Description: This is the Player class function definitions
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "Player.hpp"

Player::Player() : cave_size(4), cave(4), arrows(3), direction('x') {
	std::pair<int, int> p = cave.start();
	this->x = p.first;
	this->y = p.second; 
}

Player::Player(int cave_size) : cave_size(cave_size), cave(cave_size), arrows(3), direction('x') {
	std::pair<int, int> p = cave.start();
	this->x = p.first;
	this->y = p.second;
}

int Player::get_arrows() {
	return this->arrows;
}

void Player::shoot_arrow() {
	this->arrows--;
}

void Player::move_around() {

	std::cout << "Which direction would you like to move in?" << '\n';
	if (x != 0)
		std::cout << "Enter n for north." << '\n';
	if (y != (cave_size - 1))
		std::cout << "Enter e for east." << '\n';
	if (x != (cave_size - 1))
		std::cout << "Enter s for south." << '\n';
	if (y != 0) 
		std::cout << "Enter w for west." << '\n';

	cave.percepts(this->x, this->y);
	
	std::cin >> direction;

	if (direction == 'n')
		this->y += 1;
	if (direction == 's')
		this->y -= 1;
	if (direction == 'w')
		this->x -= 1;
	if (direction == 'e')
		this->x += 1;
}

void Player::room_check() {
	if (cave.get_location(x, y).has_bat()) {
		//randomly move x and y to another room
	}
	if (cave.get_location(x, y).has_pit()) {
		//cout game over and return 1 and end game
	}
	if (cave.get_location(x, y).has_gold()) {
		//cout << you got gold! << 
		//remove gold from room?
		//player needs gold to win
	}
	if (cave.get_location(x, y).has_wumpus()) {
		//player dies
		//same as if it has pits, game over
		//Usually, the Wumpus is peacefully asleep in his cave. Two things wake the Wumpus up, however: the adventurer entering his room or shooting an arrow and missing him. If the Wumpus wakes up while in the same room as the adventurer, the Wumpus will angrily eat the adventurer, ending the game. If the Wumpus just wakes up from hearing an arrow being fired, though, there’s a 75% chance he will move to a random empty room in the cave to avoid being found.
	}
}
