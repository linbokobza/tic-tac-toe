#pragma once
#include <iostream>
#include "Board.h"
#include <stdio.h>
#include <string>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Player {
	char* name;
	char symbol;
	Player(const Player& other);

public:
	Player(); // Ctor
	Player(const char* name_, char symbol_);
	~Player(); // dtor
	int make_move();
	void PrintPlayer();
    char* GetName() { return name; }
	char GetSymbol() { return symbol; }
	void setName(const char* str);
	void setSybol(char sym) { symbol=sym; }
};


