#include "game.h"
using namespace std;


Game :: Game()
{
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Virat";
	players[1] = "Rohit";
	players[2] = "Dhawan";
	players[3] = "Pant";
	players[4] = "Karthik";
	players[5] = "KLRahul";
	players[6] = "Jadeja";
	players[7] = "Hardik";
	players[8] = "Bumrah";
	players[9] = "BKumar";
	players[10] = "Ishant";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}


void Game :: welcome() {
	cout << "\n\n";
	cout << "*********************************************************" << endl;
	cout << "**====================== CRIC-IN ======================**" << endl;
	cout << "**                                                     **" << endl;
	cout << "**         Welcome To The Virtual Cricket Game         **" << endl;
	cout << "**                                                     **" << endl;
	cout << "*********************************************************" << endl;
	cout << "*********************************************************" << endl;
	cout << "\n\n";

	cout << "*********************************************************" << endl;
	cout << "**=================== Instructions ====================**" << endl;
	cout << "**                                                     **" << endl;
	cout << "**   1) Create two teams (Team-A and TeamB with 4      **" << endl;
	cout << "**      players each) from the given pool of players.  **" << endl;
	cout << "**                                                     **" << endl;
	cout << "**   2) Lead the toss and decide the choice of play.   **" << endl;
	cout << "**                                                     **" << endl;
	cout << "**   3) Each inning will be of 6 balls.                **" << endl;
	cout << "**                                                     **" << endl;
	cout << "*********************************************************" << endl;
	cout << "*********************************************************" << endl;
	cout << "\n\n";

}


void Game :: displayPlayers(void) {
	cout << "\n\n";
	cout << "*********************************************************" << endl;
	cout << "**================== Pool of Players ==================**" << endl;
	cout << "**                                                     **" << endl;
	cout << "**                   [0] Virat                         **" << endl;
	cout << "**                   [1] Rohit                         **" << endl;
	cout << "**                   [2] Dhawan                        **" << endl;
	cout << "**                   [3] Pant                          **" << endl;
	cout << "**                   [4] Karthik                       **" << endl;
	cout << "**                   [5] KLRahul                       **" << endl;
	cout << "**                   [6] Jadeja                        **" << endl;
	cout << "**                   [7] Hardik                        **" << endl;
	cout << "**                   [8] Bumrah                        **" << endl;
	cout << "**                   [9] BKumar                        **" << endl;
	cout << "**                   [10] Ishant                       **" << endl;
	cout << "**                                                     **" << endl;
	cout << "*********************************************************" << endl;
	cout << "*********************************************************" << endl;
	cout << "\n\n";
}

int Game :: takeIntegerInput(void){
	int n;

	while(!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!!! \nPlease try again... ";
	}
	return n;
}


bool Game :: validateSelectedPlayer(int index) {
	int n;
	vector<Player> players;

	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++){
		if(players[i].id == index){
			return false;
		}
	}

	players = teamB.players;
	n = players.size();
	for (int i = 0; i < n; i++){
		if(players[i].id == index){
			return false;
		}
	}
	return true;
}


void Game :: selectPlayers(){
	cout << "\n\n";
	cout << "*********************************************************" << endl;
	cout << "**=============  Create Team-A and Team-B  ============**" << endl;
	cout << "*********************************************************" << endl;

	for(int i = 0; i < playersPerTeam; i++){

		teamASelection:
			cout << "\t\tSelect Player " << i+1 << " of Team-A - ";
			int playerIndexTeamA = takeIntegerInput();

			if(playerIndexTeamA < 0 || playerIndexTeamA > 10){
				cout << "\t\tPlease Enter a Valid Number..." << endl;
				goto teamASelection;
			}

			else if(!(validateSelectedPlayer(playerIndexTeamA))){
				cout << "\t\tThis Player has already been Selected!!!" << endl;
				goto teamASelection;
			}

			else{
				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
			}

		teamBSelection:
				cout << "\t\tSelect Player " << i+1 << " of Team-B - ";
				int playerIndexTeamB = takeIntegerInput();

				if(playerIndexTeamB < 0 || playerIndexTeamB > 10){
					cout << "\t\tPlease Enter a Valid Number..." << endl;
					goto teamBSelection;
				}

				else if(!(validateSelectedPlayer(playerIndexTeamB))){
					cout << "\t\tThis Player has already been Selected!!!" << endl;
					goto teamBSelection;
				}

				else{
					Player teamBPlayer;
					teamBPlayer.id = playerIndexTeamB;
					teamBPlayer.name = players[playerIndexTeamB];
					teamB.players.push_back(teamBPlayer);
				}

	}
}


void Game :: showTeamPlayers(){
	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;
	cout << "\n\n";
	cout << "*********************************************************" << endl;
	cout << "**======= Team-A =======**     **======= Team-A =======**" << endl;
	cout << "**                                                     **" << endl;

	for(int i = 0 ; i < playersPerTeam ; i++){
		cout << "\t" << "[" << i << "]" << teamAPlayers[i].name <<
				"\t\t\t" << "[" << i << "]" << teamBPlayers[i].name << endl;
	}

	cout << "**                                                     **" << endl;
	cout << "*********************************************************" << endl;
	cout << "*********************************************************" << endl;
	cout << "\n\n";
}

void Game :: toss(){
	cout << "\n\n";
	cout << "*********************************************************" << endl;
	cout << "**====================  Let's Toss  ===================**" << endl;
	cout << "*********************************************************" << endl;

	cout << "\n\t\t\tTossing the coin..." << endl;

	srand(time(NULL));
	int temp = rand() % 2;

	switch(temp) {
		case 0 :
			cout << "\t\t\tTeam-A Won the Toss." << endl ;
			tossChoice(teamA);
			break;
		case 1 :
			cout << "\t\t\tTeam-B Won the Toss." << endl ;
			tossChoice(teamB);
			break;
	}

}

void Game :: tossChoice(Team tossWinnerTeam) {
	cout << "\n\t\tChoose 1 to bat or 2 to bowl. \n\t\t\t1.Bat \n\t\t\t2.Bowl  " << endl;
	int tossInput = takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch(tossInput) {
			case 1 :
				cout << "\n\t" << tossWinnerTeam.name << " won the Toss and choose to Bat." << endl ;

				if(tossWinnerTeam.name.compare("Team-A") == 0){
					battingTeam = &teamA;
					bowlingTeam = &teamB;
				}
				else{
					battingTeam = &teamB;
					bowlingTeam = &teamA;
				}

				break;
			case 2 :
				cout << "\n\t" << tossWinnerTeam.name << " won the Toss and choose to Bowl." << endl ;

				if(tossWinnerTeam.name.compare("Team-A") == 0){
					battingTeam = &teamB;
					bowlingTeam = &teamA;
				}
				else{
					battingTeam = &teamA;
					bowlingTeam = &teamB;
				}

				break;
			default:
				cout << "Invalid Input! Please Try Again...\n" << endl;
				tossChoice(tossWinnerTeam);
				break;
		}

}


void Game :: startFirstInnings(){
	cout << "\n\n\t\t||| First Innings |||\n" << endl ;

	isFirstInnings = true;
	initializePlayers();
	playInnings();

}

void Game :: startSecondInnings(){
	cout << "\n\n\t\t||| Second Innings |||\n" << endl ;
	Team *temp;
	isFirstInnings = false;
	temp = battingTeam;
	battingTeam = bowlingTeam;
	bowlingTeam = temp;
	initializePlayers();
	playInnings();

}

void Game :: initializePlayers(){
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << "\n\t\t" << battingTeam->name << "-" << batsman->name << " is batting." << endl;
	cout << "\t\t" << bowlingTeam->name << "-" << bowler->name << " is bowling.\n" << endl;
}


void Game :: playInnings(){

	for(int i = 0; i < maxBalls; i++){
		cout << "\tPress Enter to Bowl...";
		getchar();
		cout << "Bowling..." << endl;
		bat();

		if(!validateInningsScore()){
			break;
		}

	}

}

void Game :: bat(){
	srand(time(NULL));
	int runsScored = rand() % 7;

	batsman->runsScored += runsScored;
	battingTeam->totalRunsScored += runsScored;
	batsman->ballsPlayed += 1;

	bowler->ballsBowled += 1;
	bowlingTeam->totalBallsBowled += 1;
	bowler->runsGiven += runsScored;


	if(runsScored != 0){
		cout << "\n\t" << bowler->name << " to " << batsman->name << " " << runsScored << " runs!\n" << endl;
		showGameScorecard();
	}
	else{
		cout << "\n\t" << bowler->name << " to " << batsman->name << " " << " Out!!!\n" << endl;

		battingTeam->wicketsLost +=  1;
		bowler->wicketsTaken += 1;
		showGameScorecard();

		int nextPlayerIndex = battingTeam->wicketsLost;
		batsman = &battingTeam->players[nextPlayerIndex];

	}
}


bool Game :: validateInningsScore(){

	if(isFirstInnings){

		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){

			cout << "\n\n\t\t||| First Innings |||\n" << endl ;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1 << " runs to win." << endl << endl;
			return false;
		}
	}
	else{
		if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){
			cout << "***********************************************************" << endl;
			cout << "**                 " << battingTeam->name << " won the match.                 **" << endl;
			cout << "***********************************************************" << endl;
		}

		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){

			cout << "\n\n\t\t||| Second Innings |||\n" << endl ;

			if(battingTeam->totalRunsScored < bowlingTeam->totalRunsScored){
				cout << "***********************************************************" << endl;
				cout << "**            " << bowlingTeam->name << " won the match by " << bowlingTeam->totalRunsScored - battingTeam->totalRunsScored << " runs." << "            **" << endl;
				cout << "***********************************************************" << endl;
			}
			else{
				cout << "***********************************************************" << endl;
				cout << "**                 The match was Draw                    **" << endl;
				cout << "***********************************************************" << endl;
			}

			return false;
		}
	}
	return true;
}


void Game :: showGameScorecard(){
	cout << "\n\n";
		cout << "***********************************************************" << endl;
		cout << "** " << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
				<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") |"
				<< batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed
				<< ") \t" << bowler->name << " " << bowler->ballsBowled << " - "
				<< bowler->runsGiven << " - " << bowler->wicketsTaken <<" **" << endl;

		cout << "***********************************************************" << endl;
}



void Game :: matchSummary() {
	vector<Player> teamAPlayers = teamA.players;
	vector<Player> teamBPlayers = teamB.players;

	cout << teamA.name << " " << teamA.totalRunsScored << " - " << teamA.wicketsLost << " (" << teamA.totalBallsBowled << ")" << endl;

	cout << "***********************************************************" << endl;
	cout << "**  Player                Batting               Bowling  **" << endl;
	cout << "***********************************************************" << endl;

	for(int i = 0 ; i < playersPerTeam ; i++){
		cout << "**  " << "[" << i << "]" << teamAPlayers[i].name << "\t\t    "<< teamAPlayers[i].runsScored << "(" << teamAPlayers[i].ballsPlayed << ")" << "\t\t"<< teamAPlayers[i].ballsBowled << "-" << teamAPlayers[i].runsGiven << "-" << teamAPlayers[i].wicketsTaken << "    **" << endl;
		cout << "***********************************************************" << endl;
	}

	cout << "\n\n";
	cout << teamB.name << " " << teamB.totalRunsScored << " - " << teamB.wicketsLost << " (" << teamB.totalBallsBowled << ")" << endl;
	cout << "***********************************************************" << endl;
	cout << "**  Player                Batting               Bowling  **" << endl;
	cout << "***********************************************************" << endl;

	for(int i = 0 ; i < playersPerTeam ; i++){
		cout << "**  " << "[" << i << "]" << teamBPlayers[i].name << "\t\t    " << teamBPlayers[i].runsScored << "(" << teamBPlayers[i].ballsPlayed << ")" << "\t\t"<< teamBPlayers[i].ballsBowled << "-" << teamBPlayers[i].runsGiven << "-" << teamBPlayers[i].wicketsTaken << "    **" << endl;
		cout << "***********************************************************" << endl;
	}
}












