#include <iostream>

int main()
{
	std::cout << "Welcome to Text Adventure!" << std::endl << std::endl;
	std::cout << "What is your name?" << std::endl << std::endl;

	//char playerName[1024];
	std::string playerName;
	std::cin >> playerName;

	std::cout << std::endl << "Jello " << playerName << std::endl;

	return 0;
}