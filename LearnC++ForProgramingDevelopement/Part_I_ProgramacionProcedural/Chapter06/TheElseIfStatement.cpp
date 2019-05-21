#include <iostream>

int main(int argc, const char* argv[])
{
	if (false)
	{
		std::cout << "Print This When True!" << std::endl;
	}
	else if (true)
	{
		std::cout << "Print This When False!" << std::endl;
	}
	else
	{
		std::cout << "Print This if All false" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}