#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <string>

int main()
{
	// Generate unique random numbersusing the current time
	srand(time(NULL));

	// Get a random number between 0 and 99
	unsigned int numberToGuess = rand() % 100;

	std::cout << "Guess a number between 0 and 99" << std::endl;

	unsigned int playersNumber{};
	std::cin >> playersNumber;

	std::cout << "You guessed: "
		<< playersNumber
		<< " The actual number was :" 
		<< numberToGuess
		<< std::endl;

	std::cout << "press enter to exit" << std::endl;
	
	return 0;
}