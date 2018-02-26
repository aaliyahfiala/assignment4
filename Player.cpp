#include "Player.hpp"

Player::Player() : cave_size(4), cave(cave), arrows(3), direction('x') {
	 cave.start(); 
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
	if (x != 1)
		std::cout << "Enter n for north." << '\n';
	if (y != cave_size)
		std::cout << "Enter e for east." << '\n';
	if (x != cave_size)
		std::cout << "Enter s for south." << '\n';
	if (y != 1) 
		std::cout << "Enter w for west." << '\n';

	std::cin >> direction;

	if (direction == 'n')
		y += 1;
	if (direction == 's')
		y -= 1;
	if (direction == 'w')
		x -= 1;
	if (direction == 'e')
		x += 1;
}


