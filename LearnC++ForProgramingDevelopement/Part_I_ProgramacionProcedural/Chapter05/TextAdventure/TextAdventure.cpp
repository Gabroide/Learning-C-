#include <iostream>
#include <string>

struct Player
{
	std::string m_name;
};

void WelcomePlayer(Player& player)
{
	std::cout << "Welcome to Text Adventure!" << std::endl << std::endl;
	std::cout << "What is your name?" << std::endl << std::endl;

	//char playerName[1024];
	std::cin >> player.m_name;

	std::cout << std::endl << "Hello " << player.m_name << std::endl;
}

int main()
{
	Player player;
	WelcomePlayer(player);

	return 0;
}