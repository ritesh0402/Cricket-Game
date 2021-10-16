#pragma once
#include <string>

class Player {
	public:
		Player(void);

		std::string name;
		int id ;
		int runsScored ;
		int runsGiven ;
		int ballsPlayed ;
		int ballsBowled ;
		int wicketsTaken ;
};
