
#include "Cell.h"
#include "Board.h"

// Ctor
Board::Board() : size(0), board(nullptr) {}

// Ctor
Board::Board(int size_) {
	size= size_;
	board = new Cell[size];

}

// Ctor
Board::Board(const Board& other) :size(other.size) {
	board = new Cell[size];
	for (int i = 0; i < size; i++)
		if (!other.board[i].Is_free())
			board[i].setCell(other.board[i].getCell());
}

// Dtor
Board::~Board() {
	if (board) {
		delete[] board;
	}
}

//prints the game board
void Board::Print() {
	cout << "     |     |     " << endl;
	cout << "  " << board[0].getCell() << "  |  " << board[1].getCell() << "  |  " << board[2].getCell() << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[3].getCell() << "  |  " << board[4].getCell() << "  |  " << board[5].getCell() << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[6].getCell() << "  |  " << board[7].getCell() << "  |  " << board[8].getCell() << endl;
	cout << "     |     |     " << endl;

}

//checks if there is free space in specific cell
bool Board::Set_symbol(int cellNum, char symbol) {

	if (board[cellNum - 1].Is_free() && (cellNum <= 9 && cellNum > 0) && (symbol == 'O' || symbol == 'X' || symbol == 'x' || symbol == 'o')) {
		board[cellNum - 1].setCell(symbol);
		return true;
	}
	else {
		return false;
	}
}

//count how much free cells
int Board::Count_board() {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (board[i].Is_free())
			count++;
	return count;
}

//returns the cell
char Board::Get_symbol(int cellNum) {
	 return board[cellNum].getCell();
}
	