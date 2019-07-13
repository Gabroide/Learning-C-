#include "Game.h"
#include "Player.h"
#include "PlayerOptions.h"
#include "Room.h"
#include "EventManager.h"
#include "Singleton.h"
#include <iostream>

Game::Game()
	:m_attackDragonOption(&m_dragon, "Attack Dragon")
	, m_attackOrcOption(&m_orc, "Attack Orc")
	: m_moveNorthOption(Room::JoiningDirections::North, PlayerOptions::GoNorth, "Go North")
	, m_moveEastOption(Room::JoiningDirections::East, PlayerOptions::GoEast, "Go East")
	, m_moveSouthOption(Room::JoiningDirections::South, PlayerOptions::GoSouth, "Go South")
	, m_moveWestOption(Room::JoiningDirections::West, PlayerOptions::GoWest, "Go West")
	, m_openSwordChest(&m_swordChest, "Open Chest")
	, m_quitOption("Quit")
	, m_swordChet(&m_Sword)
	, m_dragon(Enemy::EnemyType::Dragon)
	, m_orc(Enemy::EnemyType::Orc)
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
	
	// Print the Options for the room
	m_player.GetCurrentRoom()->PrintOptions();
}

void Game::GetPlayerInput(std::string& playerInput) const
{
	std::cin >> playerInput;
}

void Game::InitializeRooms()
{
	// Room 0 heads North to Room 1
	m_rooms[0].AddRoon(Room::JoiningDirections::North, &(m_rooms[1]));
	m_rooms[0].AddStaticOption(&m_moveNorthOption);
	m_rooms[0].AddStaticOption(&m_quitOption);
	m_rooms[0].AddDynamicOption(&m_openSwordChest);

	// Room 1 heads East to Room 2, South to Room 0 and West to Room 3
	m_rooms[1].AddRoon(Room::JoiningDirections::East, &(m_rooms[2]));
	m_rooms[1].AddStaticOption(&m_moveEastOption);
	m_rooms[1].AddRoon(Room::JoiningDirections::South, &(m_rooms[0]));
	m_rooms[1].AddStaticOption(&m_moveSouthOption);
	m_rooms[1].AddRoon(Room::JoiningDirections::West, &(m_rooms[3]));
	m_rooms[1].AddStaticOption(&m_moveWestOption);
	m_rooms[1].AddStaticOption(&m_quitOption);

	// Room 2 heads West to Room 1
	m_rooms[2].AddRoon(Room::JoiningDirections::West, &(m_rooms[1]));
	m_rooms[2].AddStaticOption(&m_moveWestOption);
	m_rooms[2].AddStaticOption(&m_quitOption);
	m_rooms[2].AddDynamicOption(&m_attackDragonOption);

	// Room 3 heads East to Room 1
	m_rooms[3].AddRoon(Room::JoiningDirections::East, &(m_rooms[1]));
	m_rooms[3].AddStaticOption(&m_moveEastOption);
	m_rooms[3].AddStaticOption(&m_quitOption);
	m_rooms[3].AddStaticOption(&m_attackOrcOption);

	m_player.SetCurrentRoom(&(m_rooms[0]));
}

PlayerOptions Game::EvaluateInput(std::stringstream& playerInputStream)
{
	PlayerOptions chosenOption = PlayerOptions::None;
	unsigned int playerInputChoice{ 0 };
	playerInputStream << playerInputChoice;

	try
	{
		Option* option = m_player.GetCurrentRoom()->EvaluateInput(playerInputChoice);
		option->Evaluate(m_player);
	}
	catch (const std::out_of_range&)
	{
		std::cout << "I do nor recognize that option, try again!" << std::endl << std::endl;
	}

	return chosenOption;
}

void Game::HandleEvent(const Event* pEvent)
{
	if (pEvent->GetID() == QuitEvent)
	{
		m_playerQuit = true;
	}
}

void Game::RunGame()
{
	new EventManager();

	RegisterEvent(QuitEvent);
	AttachEvent(QuitEvent, this);

	InitializeRooms();

	WelcomePlayer();

	bool playerWon = false;
	
	while (m_playerQuit == false && playerWon == false)
	{
		GivePlayerOptions();

		std::stringstream playerInputStream;
		GetPlayerInput(playerInputStream);

		EvaluateInput(playerInputStream);

		playerWon = m_dragon.IsAlive() == false && m_orc.IsAlive() == false;
	}

	if (playerWon == true)
	{
		std::cout << "Congratulations, you rid the dungeon of monsters!" << std::endl;
		std::cout << "Type goodbye to end" << std::endl;
		std::string input;
		std::cin >> input:
	}

	DetachEvent(QuitEvent, this);
	delete EventManager::GetSingletonPtr();
}