// Referencing
// Demostrates using references

#include <iostream>

int main()
{
	int myScore = 1000;
	int& nosvScore = myScore;

	std::cout << "myScore is: " << myScore << "\n";
	std::cout << "nosvScore is; " << nosvScore << "\n\n";

	std::cout << "Adding 500 to myScore\n";
	myScore += 500;
	std::cout << "myScore is: " << myScore << "\n";
	std::cout << "nosvScore is: " << nosvScore << "\n\n";

	std::cout << "Adding 500 to nosvScore\n";
	nosvScore += 500;
	std::cout << "myScore is: " << myScore << "\n";
	std::cout << "nosvScore is: " << nosvScore << "\n\n";

	return 0;
}