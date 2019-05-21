#include <iostream>

int main(int argc, const char* angv[])
{
	enum class Colors
	{
		Red,
		Green,
		Blue,
	};

	Colors color = Colors::Red;

	switch (color)
	{
	case Colors::Red:
	{
		std::cout << "The color is Red!";

	}
	break;

	case Colors::Green:
	{
		std::cout << "The color is Green!";
	}
	break;

	default:
	{
		std::cout << "Unknown color!";
	}
	break;

	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}