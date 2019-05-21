#include <iostream>

int main(int argc, const char* argv[])
{
	int variable = 5;
	int* variablePointer = &variable;

	std::cout << "Value of variable: " << variable << std::endl;
	std::cout << "Address of variable: " << &variable << std::endl;
	std::cout << "Value of cariable pointer: " << variablePointer << std::endl;
	std::cout << "Value of variable pointer + 1: " << variablePointer + 1 << std::endl;
	std::cout << "Value of memory at dereferenced variable pointer: " << *variablePointer << std::endl;
	std::cout << "Value of memory at dereferenced variable pointer + 1: " << *variablePointer + 1 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}