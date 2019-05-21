#include <iostream>

int main(int argc, char** argv[])
{
	if (true)
	{
		std::cout << "Print This!" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}