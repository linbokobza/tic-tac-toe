#define _CRT_SECURE_NO_WARNINGS

#include "Player.h"
#include "Board.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//Ctor
Player::Player() {
	name = nullptr;
	symbol = ' ';
}

//Ctor
Player::Player(const char* name_, char symbol_) {
	name = new char[strlen(name_) + 1];
	strcpy(name, name_);
	setSybol(symbol_);
}

//Ctor
Player::Player(const Player& other) {
	symbol = other.symbol;
	if (name) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
}

//allocate memory for the name players
void Player::setName(const char* str) {
	if (name != nullptr)
		delete[] name;

	name = new char[strlen(str) + 1];
	strcpy(name, str);
}

//Dtor
Player::~Player() {
	delete[] name;
}

//prints the players details
void Player::PrintPlayer() {
	cout << "Player name: " << name <<" with symbol: "<< symbol<< endl;
}

//ask for enter a game move
int Player::make_move() {
	int move;
	cout << "Choose your move [1-9]:\n";
	cin >> move;
	return move;
}

