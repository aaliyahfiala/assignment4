/*********************************************************************
 * ** Program Filename: Dummy.cpp
 * ** Description: This is the Player class function definitions
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "Dummy.hpp"

/*********************************************************************
 * ** Function: dPlayer()
 * ** Description: Parameterized constructor for the player class
 * ** Parameters: cave_size
 * ** Pre-Conditions: none
 * ** Post-Conditions: player is intialized
 * *********************************************************************/ 
dPlayer::dPlayer(int cave_size) : cave_size(cave_size), cave(cave_size), arrows(3), direction('x'), game_over(false), game_won(false), has_gold(false), killed_wumpus(false) {
	std::pair<int, int> p = cave.start();
	this->x = p.first;
	this->y = p.second;
	this->x_start = p.first;
	this->y_start = p.second;
}

/*********************************************************************
 * ** Function: is_game_over()
 * ** Description: Determines if the game is over
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
bool dPlayer::is_game_over() {
	//std::cout << "bool is_game_over() : " << this->game_over << std::endl;
	return this->game_over;	
}

/*********************************************************************
 * ** Function: is_game_won()
 * ** Description: Determines if the game is won
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
bool dPlayer::is_game_won() {
	//std::cout << "bool is_game_won() : " << this->game_won << std::endl;
	return this->game_won;
}

/*********************************************************************
 * ** Function: get_arrows()
 * ** Description: Accessor for the number of arrows
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
int dPlayer::get_arrows() {
	return this->arrows;
}

/*********************************************************************
 * ** Function: shoot_arrow()
 * ** Description: shoots an arrow in the user specified direction
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: arrow is shot
 * *********************************************************************/ 
void dPlayer::shoot_arrow() {
	if(this->arrows == 0 && killed_wumpus == false) {
		std::cout << "You ran out of arrows! Game over." << std::endl;
		this->game_over = true;
		return;
	}

	if(this->arrows < 1) {
		std::cout << "You don't have anymore arrows to shoot!" << std::endl;
		return;
	}

	this->arrows--;

	this->cave.percepts(x, y);
	
	int r = rand_pick(4, 1);

	switch(r) {
		case 1: 
			direction = 'n';
			if (x == 0) {
				direction = 'e';
			}
			break;
		case 2: 	
			direction = 'e';
			if (y == (cave_size - 1)) {
				direction = 's';
			}
			break;
		case 3:
			direction = 's';
			if (x == (cave_size - 1)) {
				direction = 'w';
			}
			break;
		case 4: 
			direction = 'w';
			if (y == 0) {
				direction = 'n';
			}
			break;
	}

	std::cout << "Arrow shot " << direction << std::endl;

	
	for (int i = 1, j = 1; i < 4 && j < 4; i++, j++) {
		int a = this->x;
		int b = this->y;			
			
		if (direction == 'n' && (x - i) > -1) {
			a = this->x - i;
		}
		if (direction == 's' && (x + i) < cave_size) {
			a = this->x + i;
		}
		if (direction == 'w' && (y - i) > -1) {
			b = this->y - i;
		}
		if (direction == 'e' && (y + i) < cave_size) {
			b = this->y + i;
		}
	
		std::cout << "Shoot arrow (a, b) = (" << a << ", " << b << ")" << std::endl;
	
		if (cave.get_location(a, b).has_wumpus()) {
			this->killed_wumpus = true;
			std::cout << "You killed the wumpus!" << std::endl;
			this->cave.clear_room(a, b);
			return;
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

/*********************************************************************
 * ** Function: move_around()
 * ** Description: move around the cave in the users choice
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: user moved to a new spot in the cave
 * *********************************************************************/ 
void dPlayer::move_around() {
	this->cave.percepts(x, y);
	
	int r = rand_pick(4, 1);
	srand(r);

	std::cout << "Random pick: " << r << std::endl;

	switch(r) {
		case 1: 
			direction = 'n';
			if (x == 0) {
				direction = 's';
			}
			break;
		case 2: 	
			direction = 'e';
			if (x == (cave_size - 1)) {
				direction = 'w';
			}
			break;
		case 3:
			direction = 's';
			if (y == 0) {
				direction = 'n';
			}

			break;
		case 4: 
			direction = 'w';
			if (x == 0) {
				direction = 'e';
			}

			break;
	}
	
	std::cout << "Moving " << direction << std::endl;

	if (direction == 'n')
		this->x -= 1;
	if (direction == 's')
		this->x += 1;
	if (direction == 'w')
		this->y -= 1;
	if (direction == 'e')
		this->y += 1;

	//char prvios direction?
	//dont move?
}

/*********************************************************************
 * ** Function: room_check()
 * ** Description: checks the room the player is in for events and handles them
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
void dPlayer::room_check() {
	
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

	if (cave.get_location(x, y).has_gold() && has_gold == false) {
		std::cout << "You found gold!" << std::endl; 
		this->has_gold = true;
	//	this->cave.clear_room(x, y);
	}

	if (cave.get_location(x, y).has_wumpus() && killed_wumpus == false) {
		std::cout << "Oh no! You were violently killed by the Wumpus!" << std::endl;
		this->game_over = true;
	}

	if (this->has_gold == true && this->x == x_start && this->y == y_start && killed_wumpus == true) {
		std::cout << "Congrats! You won!" << std::endl;
		this->game_won = true;
	}
}

/*********************************************************************
 * ** Function: rand_pick()
 * ** Description: randomly picks a number between a and b
 * ** Parameters: int a, int b
 * ** Pre-Conditions: none
 * ** Post-Conditions: random number returned
 * *********************************************************************/ 
int dPlayer::rand_pick(int a, int b) {
	srand(time(NULL));
	int r;
	if (a < b) {
		r = rand() % (b - a) + a + 1;
	}
	if (b < a) {
		r = rand() % (a - b) + b + 1;
	}
	return r;
}

/*********************************************************************
 * ** Function: play_game()
 * ** Description: calls functions needed for dummy to play the game
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: none
 * *********************************************************************/ 
void dPlayer::play_game() { 
	int break_loop = 0;
	do{
		move_around();
	
		if(cave.wumpus_nearby(x, y) && killed_wumpus == false) {
 			shoot_arrow();
		}	
		
		room_check();
		
		if (is_game_over() == true) {
			break_loop = 1;
		}
		if (is_game_won() == true) {
			break_loop = 1;
		}

	} while (break_loop == 0);
}
