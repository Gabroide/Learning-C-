#include <iostream>
#include <string>

struct Player 
{
	string m_name;
};

void WelcomePlayer(Player& player)
{
	std::cout << "Wellcome to Text Adventure!" << std::endl;
	std::cout << "What is your name?" << std::endl;

	std::cin >> player.m_name;

	std::cout << "Hello " << player.m_name << std::endl;
}

void GivePlayerOptions()
{
	std::cout << "What would you like to do? (Enter a corresponding numbre)" << std::endl << std::endl;;
	std::cout << "1: Quit" << std::endl << std::endl;
}

void GetPlayerInput(string& playerInput)
{
	std::cin >> playerInput;
}

enum class PlayerOptions
{
	Quit,
	None
};

PlayerOptions EvaluateUnput(string& PlayerInput)
{
	if (playerInput.compare("1") == 0)
	{
		std::cout << "You hacve chosen to Quit." << std::endl  std::endl;
	}
	else
	{
		std::cout << "I do not recognize that option, try again!" << std::endl << std::endl:
	}

	return chosenOptopm;
}

bool RunGame()
{
	bool shouldEnd = false;

	GivePlayerOptions();

	string playerInput;

	GetPlayerInput(playerInput);

	shouldNed = EvaluateInput(playerInput) == PlayerOptions::Quit;

	return shouldEnd;
}

int main(int argc, char** argv[])
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