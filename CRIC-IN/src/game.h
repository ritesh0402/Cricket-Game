#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

#include "team.h"

class Game {
	public:
		Game();
		void welcome(void);
		void displayPlayers(void);
		int takeIntegerInput(void);
		void selectPlayers(void);
		bool validateSelectedPlayer(int);
		void showTeamPlayers();
		void toss(void);
		void tossChoice(Team);
		void startFirstInnings();
		void initializePlayers();
		void playInnings();
		void bat();
		bool validateInningsScore();
		void showGameScorecard();
		void startSecondInnings();
		void matchSummary();

		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];

		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;
};
