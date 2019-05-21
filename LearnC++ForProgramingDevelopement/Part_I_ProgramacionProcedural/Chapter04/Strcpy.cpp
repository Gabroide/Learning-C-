#include <iostream>

int main(int argc, char* argv)
{
	const char* cStyleString1 = "CStyleString";
	char cStyleString2[13];

	strcpy_s(cStyleString2, cStyleString1);

	std::cout << cStyleString2 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}