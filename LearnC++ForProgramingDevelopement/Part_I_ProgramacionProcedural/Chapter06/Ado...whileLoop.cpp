#include <iostream>

int main(int argc, const char* angv[])
{
	unsigned int array[10];
	unsigned int count = 0u;

	do
	{
		array[count] = count * 2;
		
		std::cout << "Loop Iteration: " << array[count++] << std::endl;
	} while (count < 10);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}