// Excercise 02

#include <iostream>

int ex02()
{
	std::cout << "seven divided by three is " << 7 / 3 << std::endl;
	// It will show 2 as a result as we are divided integer numbers and no float numbers

	std::cout << "seven divided by three is " << 7.0 / 3 << std::endl;
	// It wil show 2.3 as one of the variable is a double type number

	std::cout << "seven divided by three is " << 7.0 / 3.0 << std::endl;
	// It will show 2.3 as both numbers are float variables

	return 0;
}