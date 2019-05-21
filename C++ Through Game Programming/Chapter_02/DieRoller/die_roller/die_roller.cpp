// Die Roller
// Demostrates generating random numbers

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(static_cast<unsigned int>(time(0))); // seed random number generator
	int randNumber = rand(); // generate random number
	int die = (randNumber % 6) + 1; /// get a number between 1 and 6

	std::cout << "You rolled a " << die << std::endl;

	return 0;
}