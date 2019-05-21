#include <iostream>

int main(int arc, const char* argv[])
{
	int test = 0x0000000F;

	std::cout << ~test << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}