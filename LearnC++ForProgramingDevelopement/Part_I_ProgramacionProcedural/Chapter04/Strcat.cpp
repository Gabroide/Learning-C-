#include <iostream>

int main(int argc, char* argv)
{
	char cStyleString1[13];
	strcpy_s(cStyleString1, "CStyle");
	const char* cStyleString2 = "String";
	strcat_s(cStyleString1, cStyleString2);

	std::cout << cStyleString1 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}