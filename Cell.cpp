#include "Cell.h"

// Ctor
Cell::Cell(): cell(' '), free(true){}

void Cell::setCell(char c) {
	cell = c;
	free = false;
}

char Cell::getCell() {
	 return cell; 
}

void Cell::Print() {
	cout  << cell  << endl;
}