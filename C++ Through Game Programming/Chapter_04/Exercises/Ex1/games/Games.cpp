// Exercise 1
// A game list using vector

#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> games;
	games.push_back("Assassin's Creed");
	games.push_back("Crazy Taxi");
	games.push_back("Diablo");

	std::vector<std::string>::iterator myIter;
	std::vector<std::string>::const_iterator iter;

	std::cout << "\nYour games: \n";

	for (iter = games.begin(); iter != games.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}

	char choose;
	std::cout << "\nDo you want to add a game? (y/n)";
	std::cin >> choose;

	if (choose == 'y')
	{
		games.insert(games.begin(), "Mario Bross");

		for (iter = games.begin(); iter != games.end(); ++iter)
		{
			std::cout << "\t" << *iter << std::endl;
		}
	}

	std::cout << "\nDo you want to erase a game? (y/n)";
	char choose2;
	std::cin >> choose2;

	if (choose2 == 'y')
	{
		games.erase(games.begin());

		for (iter = games.begin(); iter != games.end(); ++iter)
		{
			std::cout << "\t" << *iter << std::endl;
		}
	}

	return 0;
}