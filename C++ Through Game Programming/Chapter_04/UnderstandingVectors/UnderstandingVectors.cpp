// Understanding vectors
// Demostrates capacity()

#include <iostream>
#include <vector>

int main()
{
	std::cout << "Using VECTOR.CAPACITY()\n";
	std::cout << "Creating a 10 elements vector to hold scores.\n";
	std::vector<int> scores(10, 0);

	std::cout << "\nVector size is: " << scores.size() << std::endl;
	std::cout << "\Vector capacity is: " << scores.capacity() << std::endl;

	std::cout << "\nA score is added.";
	scores.push_back(50);

	std::cout << "\nVector size is: " << scores.size() << std::endl;
	std::cout << "\Vector capacity is: " << scores.capacity() << std::endl;

	std::cout << "\n------------------------------------------------------------\n";

	std::cout << "\nUsing VECTOR.RESERVE()\n";
	std::cout << "Reserving more memory.\n";
	scores.reserve(20);
	std::cout << "\nVector size is: " << scores.size() << std::endl;
	std::cout << "\Vector capacity is: " << scores.capacity() << std::endl;

	std::cout << "\n------------------------------------------------------------\n";


	return 0;
}