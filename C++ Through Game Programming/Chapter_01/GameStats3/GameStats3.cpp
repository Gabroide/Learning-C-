// Game Stats 3.0
//Demostates constants

#include <iostream>

int main()
{
	const int ALIEN_POINTS = 150;
	int aliensKilled = 10;
	int score = aliensKilled * ALIEN_POINTS;

	std::cout << "score: " << score << std::endl;

	enum difficulty
	{
		NOVICE,
		EASY,
		NORMAL,
		HARD,
		UNBEATABLE
	};

	difficulty myDifficulty = EASY;

	enum shipCost
	{
		FIGHTER_COST = 25,
		BOMBER_COST,
		CRUISER_COST = 50
	};

	shipCost myShipCost = BOMBER_COST;
	std::cout << "\nTo upgrade my ship to a Cruiser will cost " << (CRUISER_COST - myShipCost) << " Resource Pints. \n";

	return 0;
}