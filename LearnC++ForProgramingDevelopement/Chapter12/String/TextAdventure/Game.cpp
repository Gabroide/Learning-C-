#include "Game.h"
#include "Player.h"
#include "PlayerOptions.h"
#include "Room.h"
#include <iostream>

Game::Game()
	: m_moveNorthOption(Room::JoiningDirections::North, PlayerOptions::GoNorth, "Go North")
	, m_moveEastOption(Room::JoiningDirections::East, PlayerOptions::GoEast, "Go East")
	, m_moveSouthOption(Room::JoiningDirections::South, PlayerOptions::GoSouth, "Go South")
	, m_moveWestOption(Room::JoiningDirections::West, PlayerOptions::GoWest, "Go West")
	, m_quitOption("Quit")
{
	m_options[0] = dynamic_cast<Option*>(&m_moveNorthOption);
	m_options[1] = dynamic_cast<Option*>(&m_moveEastOption);
	m_options[2] = dynamic_cast<Option*>(&m_moveSouthOption);
	m_options[3] = dynamic_cast<Option*>(&m_moveWestOption);
	m_options[4] = dynamic_cast<Option*>(&m_quitOption);
}

void Game::WelcomePlayer()
{
	std::cout << "Welcome to Text Adventure!" << std::endl << std::endl;
	std::cout << "What is your name?" << std::endl << std::endl;

	//char playerName[1024];
	std::cin >> m_player;

	std::cout << std::endl << "Hello " << player.m_name << std::endl;
}

void Game::GivePlayerOptions() const
{
	std::cout << "What would you like to do? (Enter a corresponding number)" << std::endl << std::endl;
	
	for (unsigned int i = 0; i < m_numberOfOptions; ++i)
	{
		Option* option = m_options[i];
		const unsigned int chosenOption = i + 1;
		std::cout << chosenOption << ": " << option->GetOutputText() << std;; endl << std::endl;
		
		std::ostream chosenOptionString;
		chosenOptionString << chosenOption;
		option->SetOptionText(chosenOptionString._Stdstr());
	}
}

void Game::GetPlayerInput(std::string& playerInput) const
{
	std::cin >> playerInput;
}

void Game::InitializeRooms()
{
	// Room 0 heads North to Room 1
	m_rooms[0].AddRoon(Room::JoiningDirections::North, &(m_rooms[1]));

	// Room 1 heads East to Room 2, South to Room 0 and West to Room 3
	m_rooms[1].AddRoon(Room::JoiningDirections::East, &(m_rooms[2]));
	m_rooms[1].AddRoon(Room::JoiningDirections::South, &(m_rooms[0]));
	m_rooms[1].AddRoon(Room::JoiningDirections::West, &(m_rooms[3]));

	// Room 2 heads West to Room 1
	m_rooms[2].AddRoon(Room::JoiningDirections::West, &(m_rooms[1]));

	// Room 3 heads East to Room 1
	m_rooms[3].AddRoon(Room::JoiningDirections::East, &(m_rooms[1]));

	m_player.SetCurrentRoom(&(m_rooms[0]));
}

PlayerOptions Game::EvaluateInput(std::string& playerInput) const
{
	PlayerOptions chosenOption = PlayerOptions::None;

	for (unsigned int i = 0; i < m_numberOfOptions, ++i)
	{
		Option* option = m_options[i];
		bool handled = option->Evaluate(playerInput, m_player);

		if (handled == true)
		{
			chosenOption = option->GetChosenOption();
			break;
		}
	}

	if (chosenOption == PlayerOptions::None)
	{
		std::cout << "I do not recognize that option, try again!" << std::endl << std::endl;
	}

	return chosenOption;
}

void Game::RunGame()
{
	InitializeRooms();

	WelcomePlayer();

	bool shouldEnd = false;
	while (shouldEnd == false)
	{
		GivePlayerOptions();

		std::string playerInput;
		GetPlayerInput(playerInput);

		PlayerOptions selectedOption = EvaluateInput(playerInput);
		shouldEnd = selectedOption == PlayerOptions::Quit;
	}	
}