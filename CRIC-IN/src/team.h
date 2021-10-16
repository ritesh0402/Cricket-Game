#pragma once
#include <vector>
#include "player.h"

class Team
{
	public:
		Team();

		std::string name;
		int totalRunsScored ;
		int ballsPlayed ;
		int totalBallsBowled ;
		int wicketsLost ;
		std::vector<Player> players;
};
