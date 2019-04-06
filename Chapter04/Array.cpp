#include <iostream>

int main(int argc, const char* argv[])
{
	int intArray[5] = { 0, 1, 2, 3, 4 };

	std::cout << intArray[0] << std::endl;
	std::cout << intArray[1] << std::endl; 
	std::cout << intArray[2] << std::endl;
	std::cout << intArray[3] << std::endl;
	std::cout << intArray[4] << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}