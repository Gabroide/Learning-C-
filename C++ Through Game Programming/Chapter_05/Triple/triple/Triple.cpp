// Triple
// Demostrates function overloading

#include <iostream>
#include <string>

int triple(int number);
std::string triple(std::string text);

int main()
{
	std::cout << "Tripling 5: " << triple(5) << "\n\n";
	std::cout << "Tripling 'gamer': " << triple("gamer");

	return 0;
}

int triple(int number)
{
	return (number * 3);
}

std::string triple(std::string text)
{
	return (text + text + text);
}