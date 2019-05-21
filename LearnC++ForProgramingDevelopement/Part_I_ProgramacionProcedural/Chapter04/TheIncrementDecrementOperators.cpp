#include <iostream>

int main(int argc, const char* arg[])
{
	int value = 0;
	std::cout << value << std::endl;
	std::cout << value++ << std::endl;
	std::cout << ++value << std::endl;
	std::cout << value-- << std::endl;
	std::cout << --value << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}