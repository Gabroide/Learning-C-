#include <iostream>

int main(int argc, char* argv[])
{
	std::cout << "Enter your fisrt number: " << std::endl;
	int number1 = 0;
	std::cin >> number1;

	std::cout << "Enter your second number: " << std::endl;
	int number2 = 0;
	std::cin >> number2;

	bool result = number1 == number2;
	std::cout << "It's " 
		<< result 
		<< " that your first number is equal your second." 
		<< std::endl;

	std::cout << "Enter your fisrt number: " << std::endl;
	std::cin >> number1;

	std::cout << "Enter your second number: " << std::endl;
	std::cin >> number2;

	result = number1 == number2;
	std::cout << "It's "
		<< result
		<< " that your first number is equal your second."
		<< std::endl;

	return 0;
}