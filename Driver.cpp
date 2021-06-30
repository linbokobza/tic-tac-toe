/*Assignment: 1
Author: Lin Bokobza, ID: 209482801*/

#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

//main function
int main() {
	char name1[60], name2[60];
	cout << "enter the first name: " << endl;
	cin >> name1;
	cout << "enter the second name: " << endl;
	cin >> name2;

	Game game(name1, name2); //game Ctor
	game.Play();
	return 0;
}
