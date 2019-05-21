#include <iostream>

int main()
{
	int number1 = 0, number2 = 0, number3 = 0, average = 0;

	std::cout << "Enter the first score: ";
	std::cin >> number1;

	std::cout << "Enter the second score: ";
	std::cin >> number2;

	std::cout << "Enter the third score: ";
	std::cin >> number3;

	average = (number1 + number2 + number3) / 3.0;
	std::cout << "Your average is: " << average << std::endl;
}