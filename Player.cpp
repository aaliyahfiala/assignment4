/*********************************************************************
 * ** Program Filename: Player.cpp
 * ** Description: This is the Player class function definitions
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "Player.hpp"

Player::Player() : cave_size(4), cave(4), arrows(3), direction('q'), game_over(false), game_won(false), has_gold(false), killed_wumpus(false) {
	std::pair<int, int> p = cave.start();
	this->x = p.first;
	this->y = p.second; 

	this->x_start = p.first;
	this->y_start = p.second;
}

Player::Player(int cave_size) : cave_size(cave_size), cave(cave_size), arrows(3), direction('x'), game_over(false), game_won(false), has_gold(false), killed_wumpus(false) {
	std::pair<int, int> p = cave.start();
	this->x = p.first;
	this->y = p.second;
}

void Player::operator=(const Player& p) {
	this->cave = p.cave;
	this->cave_size = p.cave_size;
	this->game_over = false;
	this->game_won = false;
	this->has_gold = false;
	this->killed_wumpus = false;
	this->arrows = 3;
	this->direction = 'x';
	this->x = p.x;
	this->y = p.y;
}

bool Player::is_game_over() {
	return this->game_over;	
}

bool Player::is_game_won() {
	return this->game_won;
}

int Player::get_arrows() {
	return this->arrows;
}

void Player::shoot_arrow() {
	if(this->arrows == 0) {
		std::cout << "You ran out of arrows! Game over." << std::endl;
		this->game_over = true;
		return;
	}

	this->arrows--;

	std::cout << "Which direction would you like to shoot the arrow?" << '\n';

	if (x != 0)
		std::cout << "Enter n for north." << '\n';
	if (y != (cave_size - 1))
		std::cout << "Enter e for east." << '\n';
	if (x != (cave_size - 1))
		std::cout << "Enter s for south." << '\n';
	if (y != 0) 
		std::cout << "Enter w for west." << '\n';

	std::cin >> direction;
	
	//seg fault

	for (int i = 1, j = 1; i < 4 && j < 4; i++, j++) {
		int a = this->y;
		int b = this->x;			
			
		if (direction == 'n' && x != 0)
			a = this->x - i;
		if (direction == 's' && x != (cave_size - 1))
			a = this->x + i;
		if (direction == 'w' && y != 0)
			b = this->y - i;
		if (direction == 'e' && y != (cave_size - 1))
			b = this->y + i;

		if (cave.get_location(a, b).has_wumpus()) {
				killed_wumpus = true;
			}
		}
		
		if (killed_wumpus == false) {
			srand(time(NULL));
			int w;
			w = rand() % 4;
			if (w != 1) { //75% chance
				cave.wumpus();//wumpus moves to new spot	
			}
		}
		
}


void Player::move_around() {

	this->cave.percepts(x, y);
	
	std::cout << "Which direction would you like to move in?" << '\n';
	if (x != 0)
		std::cout << "Enter n for north." << '\n';
	if (y != (cave_size - 1))
		std::cout << "Enter e for east." << '\n';
	if (x != (cave_size - 1))
		std::cout << "Enter s for south." << '\n';
	if (y != 0) 
		std::cout << "Enter w for west." << '\n';

	std::cin >> direction;

	if (direction == 'n')
		this->x -= 1;
	if (direction == 's')
		this->x += 1;
	if (direction == 'w')
		this->y -= 1;
	if (direction == 'e')
		this->y += 1;
}

void Player::room_check() {

	std::cout << "Current location: (" << this->x << ", " << this->y << ")." << std::endl;

	if (cave.get_location(x, y).has_bat()) {
		std::cout << "Oh no! You've been dragged to a new location by bats!" << std::endl;
		srand(time(NULL));
		int new_x;
		int new_y;

		new_x = rand() % cave_size;
		new_y = rand() % cave_size;

		this->x = new_x;
		this->y = new_y;
	}

	if (cave.get_location(x, y).has_pit()) {
		std::cout << "You fell into a dark abyss! Game over." << std::endl;
		this->game_over = true;
	}

	if (cave.get_location(x, y).has_gold()) {
		std::cout << "You found gold!" << std::endl; 
		this->has_gold = true;
	}

	if (cave.get_location(x, y).has_wumpus()) {
		std::cout << "Oh no! You were violently killed by the Wumpus!" << std::endl;
		this->game_over = true;
	}

	if (this->has_gold == true && x == x_start && y == y_start && killed_wumpus == true) {
		this->game_won = true;
	}
}

