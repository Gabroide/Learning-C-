#include <iostream>

int main(int argc, const char* angv[])
{
	unsigned int array[10];

	for (unsigned int i = 0; i < 10; ++i)
	{
		array[i] = i * 2;

		std::cout << "Loop Iteration: " << array[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}