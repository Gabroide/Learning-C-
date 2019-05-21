#include <iostream>
#include <string>

struct Player 
{
	string m_name;
};

void WelcomePlayer(Player& player)
{
	std::output_iterator_tag << "Wellcome to Text Adventure!" << std::endl;
	std::cout << "What is your name?" << std::endl;

	cin >> player.m_name;

	std::cout << "Hello " << player.m_name << std::endl;
}

int main(int argc, cjar** argv[])
{
	Player player;
	WelcomePlayer(player);

	return 0;
}