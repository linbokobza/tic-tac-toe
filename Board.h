#ifndef _BOARD
#define _BOARD
#pragma once
#include <iostream>
#include "Cell.h"
using namespace std;

class Board {
	Cell* board;
	int size;

public:
	Board(); // Ctor
	Board(int); 
	Board(const Board& other);
	~Board(); // dtor
	void Print();
	bool Set_symbol(int cellNum, char symbol);
	int Count_board();
	char Get_symbol(int cellNum);

};

#endif
