#include "Player.h"
#include "Board.h"
#include "Game.h"
#include  <cstdlib>
#include <random>
#include <ctime>

// Ctor
Game::Game(char* str1, char* str2):board(9){

	//rand number
	srand(time(nullptr));
	int pr;
	pr = rand() % 2; 

	status = start;
	players[0].setName(str1);
	players[0].setSybol('X');

	players[1].setName(str2);
	players[1].setSybol('O');

	system("cls");

	//enabled the first player
	if (pr == 0)
		turn = players[0].GetSymbol();
	else turn =players[1].GetSymbol();
}

//game manager
void Game::Play() {
	int move;
	board.Print();

	do
	{
		if (turn == players[0].GetSymbol()) {
			players[0].PrintPlayer();
			move = checkMove(0);
		}
		else {
			players[1].PrintPlayer();
			move = checkMove(1);
		}

		system("cls");
		board.Print();
		swichPlayer();
		gameOver();
		if(board.Count_board()<=4)
			checkWin();
		
	} while (status==start);
}

//ask for player move
int Game::checkMove(int index) {
	int move;
	move = players[index].make_move();
	
	while (board.Set_symbol(move, turn) == false) {
		cout << "Please try again" << endl;
		move = players[index].make_move();
	}
	board.Set_symbol(move, turn);
	return move;
}

//swich player turn
void Game::swichPlayer(){
	if (turn == 'X')
		turn = 'O';
	else turn = 'X';
}


//checks if it's a draw
void Game::gameOver() {	
	if (board.Count_board() == 0) {
		status = draw;
		cout << "It's a DRAW!" << endl;
	}
}

//checks if it's a win
void Game::checkWin() {
	int i = 0;
	
	//rows check
	while (i <= 6) {
		if ((board.Get_symbol(i) == board.Get_symbol(i + 1) && board.Get_symbol(i + 1) == board.Get_symbol(i + 2)) && board.Get_symbol(i) != ' ') {
			cout << "It's WIN!" << endl << "Player details:" << endl;
			status = win;
			if (board.Get_symbol(i) == players[0].GetSymbol()) {
				players[0].PrintPlayer();
				break;
			}
			else if (board.Get_symbol(i) == players[1].GetSymbol()) {
				players[1].PrintPlayer();
				break;
			}
		}
		i += 3;
	}

	//col check
	i = 0;
	while (i <= 3) {
		if ((board.Get_symbol(i) == board.Get_symbol(i + 3) && board.Get_symbol(i + 6) == board.Get_symbol(i + 3))&& board.Get_symbol(i)!=' ')
		{
			cout << "It's WIN!" << endl << "Player details:" << endl;
			status = win;
			if (board.Get_symbol(i) == players[0].GetSymbol()) {
				players[0].PrintPlayer();
				break;
			}
			else if (board.Get_symbol(i) == players[1].GetSymbol()) {
				players[1].PrintPlayer();
				break;
			}
		}
		i++;
	}

	//main diagonal line check
	i = 0;
	if ((board.Get_symbol(i) == board.Get_symbol(i + 4) && board.Get_symbol(i + 4) == board.Get_symbol(i + 8)) && board.Get_symbol(i) != ' ') {
		cout << "It's WIN!" << endl << "Player details:" << endl;
		status = win;
		if (board.Get_symbol(i) == players[0].GetSymbol()) {
			players[0].PrintPlayer();
		}
		else if (board.Get_symbol(i) == players[1].GetSymbol()) {
			players[1].PrintPlayer();
		}
	}

	//secondery diagonal line check
	i = 2;
	if ((board.Get_symbol(i) == board.Get_symbol(i + 2) && board.Get_symbol(i + 2) == board.Get_symbol(i + 4)) && board.Get_symbol(i) != ' ') {
		cout << "It's WIN!" << endl << "Player details:" << endl;
		status = win;
		if (board.Get_symbol(i) == players[0].GetSymbol()) {
			players[0].PrintPlayer();
		}
		else if (board.Get_symbol(i) == players[1].GetSymbol()) {
			players[1].PrintPlayer();
		}
	}
}