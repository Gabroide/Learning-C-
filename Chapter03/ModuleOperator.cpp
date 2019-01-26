#include <iostream>

int main(int argc, const char* argv[])
{
	std::cout << "Enter your first number: " << std::endl;
	int number1 = 0;
	std::cin >> number1;

	std::cout << "Enter your second number: " << std::endl;
	int number2 = 0;
	std::cin >> number2;

	float result = number1 % number2;
	std::cout << "The reminder from diviing your two numbers is: "
		<< result
		<< std::endl;

	std::cout << "Press enter to exit" << std::endl;

	return 0;
}