#pragma once
#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Player.h"

using namespace std;

class Game {
	Board board;
	Player players[2];
	enum statuses { win, draw, start };
	statuses status;
	char turn;

public:
	Game(char* str1, char* str2); // Ctor
	void Play();
	int checkMove(int index);
	void swichPlayer();
	void gameOver();
	void checkWin();
};