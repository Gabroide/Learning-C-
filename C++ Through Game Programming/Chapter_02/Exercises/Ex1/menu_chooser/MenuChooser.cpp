// Menu Chooser 2.0
// First excercise, the aim is to add an enumerate to choose the option insted of a number

#include <iostream>

enum option
{
	Easy = 1,
	Normal,
	Hard
};

int main()
{
	std::cout << "Difficulty levels:\n\n";
	std::cout << "1.- Easy.\n";
	std::cout << "2.- Normal.\n";
	std::cout << "3.- Hard.\n\n";

	int choice;

	std::cout << "Choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		std::cout << "You picked Easy.\n";
		break;

	case 2:
		std::cout << "You picked Normal.\n";
		break;

	case 3:
		std::cout << "You picked Hard.\n";
		break;
	
	default:
		std::cout << "You made an illegal choice.\n";
		break;
	}

	return 0;
}