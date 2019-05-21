// Game Stats 2.0
//Demostrates arithmetic operations with variables

#include <iostream>

int main()
{
	unsigned int score = 5000;
	std::cout << "score: " << score << std::endl;

	//altering te value of a variable
	score = score + 1000;
	std::cout << "score: " << score << std::endl;

	//combined assignment operator
	score += 100;
	std::cout << "score: " << score << std::endl;

	//increment operators
	int lives = 3;
	++lives;
	std::cout << "lives: " << lives << std::endl;

	lives = 3;
	lives++;
	std::cout << "libes: " << lives << std::endl;

	lives = 3;
	int bonus = ++lives * 10;
	std::cout << "lives, bonus; " << lives << ", " << bonus << std::endl;

	lives = 3;
	bonus = lives++ * 10;
	std::cout << "lives, bonus; " << lives << ", " << bonus << std::endl;

	//integer wrap around
	score = 4294967295;
	std::cout << "\nscore: " << ++score << std::endl;

	return 0;
}