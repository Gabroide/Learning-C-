#include <iostream>

int main()
{
	std::cout << "Welcome to Text Adventure!" << std::endl << std::endl;
	std::cout << "What's your nam? " << std::endl << std::endl;

	char playerName[1024];
	std::cin >> playerName;

	std::cout << std::endl << "Hello " << playerName << std::endl;

	return 0;
}