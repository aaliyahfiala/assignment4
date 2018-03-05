/*********************************************************************
 * ** Program Filename: Room.cpp
 * ** Description: This is the Room class function definition file
 * ** Input: none
 * ** Output: none
 * *********************************************************************/
#include "Room.hpp"

Room::Room() : event(event), event_type('n') {} //intialize to no event occurs in event class

Room::~Room() {
//	delete event; compiler error?
}

std::string Room::display_percept() { 
	return this->event->get_percept();
}

void Room::give_bat() {
	this->event = new Bats;
	event_type = 'b';
}

void Room::give_pit() {
	this->event = new Pit;
	event_type = 'p';
}

void Room::give_wumpus() {
	this->event = new Wumpus;
	event_type = 'w';
}

void Room::give_gold() {
	this->event = new Gold;
	event_type = 'g';

}

void Room::give_start() {
	this->event = new Start;
	event_type = 's';
}

bool Room::has_event() {
	bool event = false;

	if (has_bat() || has_pit() || has_wumpus() || has_gold() || is_start() )
		event = true;
	
	return event;
}

bool Room::has_bat() {
	bool bats = false;
	if (event_type == 'b')
		bats = true;
	return bats;
}

bool Room::has_pit() {
	bool pit = false;
	if (event_type == 'p')
		pit = true;
	return pit;
}

bool Room::has_wumpus() {
	bool wumpus = false;
	if (event_type == 'w')
		wumpus = true;
	return wumpus;
} 

bool Room::has_gold() {
	bool gold = false;
	if (event_type == 'g')
		gold = true;
	return gold;
}

bool Room::is_start() {
	bool start = false;
	if (event_type == 's')
		start = true;
	return start;
}

void Room::delete_event() {
	this->event = new Event;
}
