#include <iostream>

int main(int argc, const char* argv[])
{
	int intArray[5] = { 5, 6, 7, 8, 9 };
	unsigned int index = 0;

	std::cout << "Index: " << index << std::endl;
	std::cout << "Value :" << intArray[index++] << std::endl;

	std::cout << "Index: " << index << std::endl;
	std::cout << "Value: " << intArray[index++] << std::endl;

	std::cout << "Index: " << index << std::endl;
	std::cout << "Value: " << intArray[index++] << std::endl;

	std::cout << "Index: " << index << std::endl;
	std::cout << "Value: " << intArray[index++] << std::endl;

	std::cout << "Index: " << index << std::endl;
	std::cout << "Value: " << intArray[index++] << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}