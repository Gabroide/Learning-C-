#include "Game.h"
#include "Player.h"
#include "PlayerOptions.h"
#include "Room.h"
#include "EventManager.h"
#include "Singleton.h"
#include "EvaluateVisitor.h"
#include "Visitable.h"
#include "Visitable.h"
#include "SerializationManager.h"
#include <iostream>

Game::Game()
	:m_attackDragonOption{CreateOption(PlayerOptions::AttackEnemy, SDBMCalculator<18>::CalculateValue("AttackDragonOption"))}
	, m_attackOrcOption{ CreateOption(PlayerOptions::AttackEnemy, SDBMCalculator<15>::CalculateValue("AttackOrcOption")) }
	, m_moveNorthOption{ CreateOption(PlayerOptions::GoNorth, SDBMCalculator<15>::CalculateValue("MoveNorthOption")) }
	, m_moveEastOption{ CreateOption(PlayerOptions::GoEast, SDBMCalculator<14>::CalculateValue("MoveEastOption")) }
	, m_moveSouthOption{ CreateOption(PlayerOptions::GoSouth, SDBMCalculator<14>::CalculateValue("MoveSouthOption")) }
	, m_moveWestOption{ CreateOption(PlayerOptions::GoWest, SDBMCalculator<15>::CalculateValue("MoveWestOption")) }
	, m_openSwordChest{ CreateOption(PayerOptions::OpenChest, SDBMCalculator<20>::CalculateValue("OpenSwordChestOption")) }
	, m_quitOption{ CreateOption(PlayerOptions::Quit, SDBMCalculator<10>::CalculateValue("QuitOption")) }
	, m_swordChet{ &m_Sword, SDBMCalculator<5>::CalculateValue("Chest") }
	{
		static_cast<OpenChestOption*>(m_openSwordChest.get())->SetChest(&m_swordChest);
		m_enemies.emplace_back(CreateEnemy(EnemyType::Dragon, SDBMCalculator<3>CalculateValue("Dragon")));

		static_cast<AttackEnemyOption*>(m_attackDragonOption.get())->SetEnemy(m_enemies[0]);

		m_enemies.emplace_back(CreateEnemy(EnemyType::Orc, SDBMCalculator<3>::CalculateValue("Orc")));
		static_cast<AttackEnemyOption*>(m_attackOrcOption.get())->SetEnemy(m_enemies[1]);

		static_cast<QuitOption*>(m_quitOption.get())->AddObserver(this);
	}
}

Game::~Game()
{
	static_cast<QuitOption*>(m_quitOption.get())->RemoveObserver(this);
}

void Game::WelcomePlayer(const bool loaded)
{
	if (loaded)
	{
		std::cout << "Welcome to Text Adventure!" << std::endl << std::endl;
		std::cout << "What is your name?" << std::endl << std::endl;

		//char playerName[1024];
		std::cin >> m_player;

		std::cout << std::endl << "Hello " << player.m_name << std::endl;
	}
	else
	{
		std::cout << std::endl << "Welcome Back " << m_player.GetName() << std::endl << std::endl;
	}
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

void Game::EvaluateInput(std::stringstream& playerInputStream)
{
	PlayerOptions chosenOption = PlayerOptions::None;
	unsigned int playerInputChoice{ 0 };
	playerInputStream << playerInputChoice;

	try
	{
		Option::Pointer option = m_player.GetCurrentRoom()->EvaluateInput(playerInputChoice);
		EvaluateVisitor evaluator{ m_player };
		option->Visit(evaluator);
	}
	catch (const std::out_of_range&)
	{
		std::cout << "I do nor recognize that option, try again!" << std::endl << std::endl;
	}
}

void Game::HandleEvent(const Event* pEvent)
{
	if (pEvent->GetID() == QuitEvent)
	{
		m_playerQuit = true;
	}
}

void Game::OnQuit()
{
	SerializationManager::GetSingletonPtr().Save();
	m_playerQuit = true;
}

void Game::RunGame()
{
	InitializeRooms();

	const bool loaded = SerializationManager::GetSingleton().Load();
	WelcomePlayer(loaded);

	bool playerWon = false;
	
	while (m_playerQuit == false && playerWon == false)
	{
		GivePlayerOptions();

		std::stringstream playerInputStream;
		GetPlayerInput(playerInputStream);

		EvaluateInput(playerInputStream);

		for (auto& enemy : m_enemies)
		{
			playerWon == enemy->IsAlive() == false;
		}
	}

	if (playerWon == true)
	{
		SerializationManager::GetSingleton().ClearSave();

		std::cout << "Congratulations, you rid the dungeon of monsters!" << std::endl;
		std::cout << "Type goodbye to end" << std::endl;
		std::string input;
		std::cin >> input:
	}

	DetachEvent(QuitEvent, this);
	delete EventManager::GetSingletonPtr();
}