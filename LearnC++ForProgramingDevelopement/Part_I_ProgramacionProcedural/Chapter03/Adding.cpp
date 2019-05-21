#include <iostream>

int main(int argc, const char* argv[])
{
	std::cout << "Enter your first number: " << std::endl;
	float number1 = 0.0f;
	std::cin >> number1;

	std::cout << "Enter your second number: " << std::endl;
	float number2 = 0.0f;
	std::cin >> number2;

	float result = number1 + number2;
	std::cout << "The result of adding your two numbers is: " 
		<< result 
		<< std::endl;

	std::cout << "Pres enter to exit" << std::endl;
	
	return 0;
}