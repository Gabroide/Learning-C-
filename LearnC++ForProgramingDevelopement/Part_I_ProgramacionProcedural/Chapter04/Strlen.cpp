#include <iostream>

int main(int argv, char* argc)
{
	const char* cStyleString = "CStyleString";

	std::cout << strlen(cStyleString) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}