// Score Rater 2.0
// Demostrates an else clause

#include <iostream>

int main()
{
	int score;

	std::cout << "Enter your score: ";
	std::cin >> score;

	if (score >= 1000)
	{
		std::cout << "You scored 1000 or more. Impressive!\n";
	}
	else
	{
	std::cout << "You scored less than 1000.\n";
	}

	return 0;
}