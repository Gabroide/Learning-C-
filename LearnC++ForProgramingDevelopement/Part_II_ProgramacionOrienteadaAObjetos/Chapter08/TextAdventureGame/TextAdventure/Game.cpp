#include "Game.h"
#include <iostream>

void Game::WelcomePlayer()
{
	std::cout << "Welcome to Text Adventure" << std::endl << std::endl;
	std::cout << "What is your name?" << std::endl << std::endl;

	std::string name;
	std::cin >> name;
	m_player.SetName(name);

	std::cout << std::endl << "Hello " << player.GetName() << std::endl;
}

void Game::GivePlayerOptions()
{
	std::cout << "What would you like to do? (Enter a corresponding number)" << std::endl << std::endl;
	std::cout << "1: Quit" << std::endl;

}

void Game::GetPlayerInput(std::string& playerInput)
{
	std::cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(std::string& playerInput)
{
	PlayerOptions chosenOption = PlayerOptions::None;

	if (playerInput.compare("1") == 0)
	{
		std::cout << "You have chosen to Quit!" << std::endl << std::endl;
		chosenOption == PlayerOptions::Quit;
	}
	else
	{
		std::cout << "I do not recognize that option, try again!" << std::endl << std::endl;
	}

	return chosenOption;
}

void Game::RunGame()
{
	WelcomePlayer();

	bool shouldEnd = false;

	while (shouldEnd == false)
	{
		GivePlayerOptions();

		std::string playerInput;

		GetPlayerInput(playerInput);

		shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;
	}
}