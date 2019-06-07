// High Scores
// Demostrates algorithms

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int main()
{
	std::vector<int>::const_iterator iter;

	std::cout << "Creating a list of scores.";
	
	std::vector<int> scores;
	scores.push_back(1500);
	scores.push_back(3500);
	scores.push_back(7500);

	std::cout << "\nHigh Scores:\n";

	for (iter = scores.cbegin(); iter != scores.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}

	std::cout << "\nFinding a score.";

	int score;
	std::cout << "\nEnter a score to find: ";
	std::cin >> score;
	iter = find(scores.begin(), scores.end(), score);
	if (iter != scores.end())
	{
		std::cout << "Score found.\n";
	}
	else
	{
		std::cout << "Score not found.\n";
	}

	std::cout << "\nRandomizing scores.";
	srand(static_cast<unsigned int>(time(0)));
	std::random_shuffle(scores.begin(), scores.end());
	std::cout << "\nHigh Scores:\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}

	std::cout << "\nSorting Scores.";
	sort(scores.begin(), scores.end());
	std::cout << "\nHigh Scores:\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}

	return 0;
}