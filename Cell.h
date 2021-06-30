#pragma once
#include <iostream>
using namespace std;

class Cell {
	char cell;
	bool free; 

public:
	Cell(); // ? Ctor
	void Print();
	void setCell(char c);
	char getCell();
	bool Is_free() { return free; }
};


