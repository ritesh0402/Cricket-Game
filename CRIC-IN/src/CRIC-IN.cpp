//============================================================================
// Name        : Cricket.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


//#include "team.cpp"
#include "game.h"
//#include "game.cpp"
//#include "player.cpp"
using namespace std;


int main() {

	class Game game;
	game.welcome();

	cout << "Press Enter to continue..." << endl;
	getchar();

	game.displayPlayers();

	cout << "Press Enter to continue..." << endl;
	getchar();

	game.selectPlayers();
	game.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Press Enter to continue..." << endl;
	getchar();

	game.toss();

	game.startFirstInnings();
	game.startSecondInnings();
	game.matchSummary();
	return 0;
}







