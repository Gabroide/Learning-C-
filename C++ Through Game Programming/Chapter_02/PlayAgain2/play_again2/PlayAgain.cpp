// Play Again 2.0
// Demostrates do loops

#include <iostream>

int main()
{
	char again;

	do
	{
		std::cout << "\n***Played exciting game***";
		std::cout << "\nDo you want to play again? (u/n): ";
		std::cin >> again;
	} while (again == 'y');

	std::cout << "\nOkay, bye.";

	return 0;
}