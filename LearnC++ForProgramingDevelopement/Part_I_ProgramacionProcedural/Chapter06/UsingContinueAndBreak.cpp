#include <iostream>

int main(int argc, const char* angv[])
{
	unsigned int array[10];
	unsigned int count = 0u;

	do
	{
		if ((count % 2) == 0)
		{
			++count;

			continue;
		}

		array[count] = count;

		std::cout << "Loop iteration: " << array[count++] << std::endl;

		if (count == 10)
		{
			break;
		}
	} while (true);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}