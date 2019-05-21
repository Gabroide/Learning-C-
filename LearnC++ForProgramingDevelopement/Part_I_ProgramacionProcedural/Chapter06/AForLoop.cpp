#include <iostream>

int main(int argc, const char* angv[])
{
	for (unsigned int i = 0; i < 10; ++i)
	{
		std::cout << "Loop Iteration: " << i << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}