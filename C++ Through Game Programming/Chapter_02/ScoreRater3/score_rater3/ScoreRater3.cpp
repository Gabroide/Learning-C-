// Score Rater 3.0
// Demostrates if else-if else suite

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
	else if (score >= 500)
	{
		std::cout << "You scored 500 or more. Nice.\n";
	}
	else if (score >= 250)
	{
		std::cout << "You scored 250 or more. Decent.\n";
	}
	else
	{
		std::cout << "You scored less than 250. Nothing to drag out.\n";
	}

	return 0;
}