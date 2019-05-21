// Guess My Number 2.0
// 3rd exercise of chapter 2. In this case the computer should guess the number choosen by the player

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int tries = 0;
	int secretNumber = 0;
	int guess;

	std::cout << "Insert a number between 1 and 100 to guess: ";
	std::cin >> guess;

	do
	{
		secretNumber = rand() % 100 + 1;

		std::cout << "Is your number " << secretNumber << " ?";

		if (secretNumber == guess)
		{
			std::cout << "\nYep, you got it after " << tries << " tries";
		}
		else
		{
			std::cout << "\nNope! Try again.";
			++tries;
		}
	} while (secretNumber != guess);

	return 0;
}