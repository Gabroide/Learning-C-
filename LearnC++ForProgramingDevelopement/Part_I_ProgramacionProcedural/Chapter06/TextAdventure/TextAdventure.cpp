#include <iostream>
#include <string>

struct Player
{
	std::string m_name;
};

enum class PlayerOptions
{
	Quit,
	None
};

void WelcomePlayer(Player& player)
{
	std::cout << "Welcome to Text Adventure!" << std::endl << std::endl;
	std::cout << "What is your name?" << std::endl << std::endl;

	//char playerName[1024];
	std::cin >> player.m_name;

	std::cout << std::endl << "Hello " << player.m_name << std::endl;
}

void GivePlayerOptions()
{
	std::cout << "What would you like to do? (Enter a corresponding number)" << std::endl << std::endl;
	std::cout << "1. Quit" << std::endl << std::endl;
}

void GetPlayerInput(std::string& playerInput)
{
	std::cin >> playerInput;
}

PlayerOptions EvaluateInput(std::string& playerInput)
{
	PlayerOptions chosenOption = PlayerOptions::None;

	if (playerInput.compare("1") == 0)
	{
		std::cout << "You have chosen to Quit!" << std::endl << std::endl;
		chosenOption = PlayerOptions::Quit;
	}
	else
	{
		std::cout << "I do not recognize that option, try again!" << std::endl << std::endl;
	}

	return chosenOption;
}

bool RunGame()
{
	bool shouldEnd = false;

	GivePlayerOptions();

	std::string playerInput;
	GetPlayerInput(playerInput);
	
	shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;

	return !shouldEnd;
}

int main()
{
	Player player;
	WelcomePlayer(player);

	bool isPlaying = true;
	while (isPlaying)
	{
		isPlaying = RunGame();
	}

	return 0;
}