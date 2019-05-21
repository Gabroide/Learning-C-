#include <iostream>
#include <string>

int main()
{
	std::cout << "Welcome to Text Adventure!" << std::endl << std::endl;
	std::cout << "What's your nam? " << std::endl << std::endl;

	string playerName;
	
	std::cin >> playerName;

	std::cout << std::endl << "Hello " << playerName << std::endl;

	return 0;
}