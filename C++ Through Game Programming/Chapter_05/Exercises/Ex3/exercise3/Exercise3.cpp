// Exercise 3
// Creating a function with default value

#include <iostream>

int askNumber(std::string prompt = "Insert a number");

int main()
{
	int num = askNumber();
	std::cout << "\n\nThe first nimber is: " << num;

	num = askNumber("\n\nInsert a second number");
	std::cout << "The second number is: " << num;
}

int askNumber(std::string prompt)
{
	int number;
	
	std::cout << prompt;
	std::cin >> number;

	return number;
}