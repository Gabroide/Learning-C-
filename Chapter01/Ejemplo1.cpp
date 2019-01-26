// Ejemplo1.cpp: Defines he entry point for the console application
//

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::cout << "What is your name? " << std::endl;
	std::string name{};
	std::cin >> name;

	std::cout << "You said your name is: " << name << std::endl;
	return 0;
}
