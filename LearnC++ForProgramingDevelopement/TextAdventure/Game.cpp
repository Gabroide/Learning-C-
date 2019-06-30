#include "Game.h"
#include "Player.h"
#include "PlayerOptions.h"
#include "Room.h"
#include <iostream>


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
	std::cout << "1. Go North" << std::endl << std::endl;
	std::cout << "2. Go East" << std::endl << std::endl;
	std::cout << "3. Go South" << std::endl << std::endl;
	std::cout << "4. Go West" << std::endl << std::endl;
	std::cout << "5. Quit" << std::endl << std::endl;
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

	if (playerInput.compare("1") == 0)
	{
		std::cout << "You have chosen to Go North!" << std::endl << std::endl;
		chosenOption = PlayerOptions::GoNorth;
	}
	else if (playerInput.compare("2") == 0)
	{
		std::cout << "You have chosen to Go East!" << std::endl << std::endl;
		chosenOption = PlayerOptions::GoEast;
	}
	else if (playerInput.compare("3") == 0)
	{
		std::cout << "You have chosen to Go South!" << std::endl << std::endl;
		chosenOption = PlayerOptions::GoSouth;
	}
	else if (playerInput.compare("4") == 0)
	{
		std::cout << "You have chosen to Go West!" << std::endl << std::endl;
		chosenOption = PlayerOptions::GoWest;
	}
	else if (playerInput.compare("5") == 0)
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

void Game::UpdateOption(PlayerOptions selectedOption)
{
	if (selectedOption == PlayerOptions::GoNoth ||
		selectedOption == PlayerOptions::GoEast || 
		selectedOption == PlayerOptions::GoSouth ||
		selectedOption == PlayerOptions::GoWest || )
	{
		Room::JoiningDirections directionToMove = Room::JoiningDirections::North;

		switch (selectedOption)
		{
		case PlayerOptions::GoEast:
			directionToMove = Room::JoiningDirections::East;
			break;

		case PlayerOptions::GoSouth:
			directionToMove = Room::JoiningDirections::South;
			break;

		case PlayerOptions::GoWest:
			directionToMove = Room::JoiningDirections::West;
			break;
		}

		const Room* pPlayerCurrentRoom = m_player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(directionToMove);

		if (pNewRoom)
		{
			m_player.SetCurrentRoom(pNewRoom);
		}
		else
		{
			const char* strDirection = "North";
			switch (selectedOption)
			{
			case PlayerOptions::GoEast:
				strDirection = "East";
				break;

			case PlayerOptions::GoSouth:
				strDirection = "South";
				break;

			case PlayerOptions::GoWest:
				strDirection = "West";
				break;
			}
			std::cout << "There is no room to the " << strDirection << std::endl << std::endl;
		}
	}
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
		if (shouldEnd == false)
		{
			UpdateOption(selectedOption);
		}
	}	
}