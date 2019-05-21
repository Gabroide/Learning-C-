#include <iostream>

int main(int argv, char * argc)
{
	const char* cStyleString1 = "CStyleString";
	const char* cStyleString2 = "CStyleString";

	std::cout << strcmp(cStyleString1, cStyleString2) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}