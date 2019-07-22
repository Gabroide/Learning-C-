#pragma once

#include "Player.h"
#include "Room.h"
#include "Option.h"
#include "MoveOption.h"
#include "QuitOption.h"
#include "AttackEnemyOption.h"
#include "OpenChestOption.h"
#include "Event.h"
#include "QuitObserver.h"
#include "EnemyBase.h"

#include <mutex>

class Game
	: public EventHandler
	, public QuitObserver
{
private:
	static const unsigned int m_numberOfRooms = 4;
	using Rooms = std::array<Room::Pointer, m_numberOfRooms>;
	Rooms m_rooms;

	Player m_player;

	Option::Pointer m_attackDragonOption;
	Option::Pointer m_attackOrcOption;
	Option::Pointer m_moveNorthOption;
	Option::Pointer m_moveEastOption;
	Option::Pointer m_moveSouthOption;
	Option::Pointer m_moveWestOption;
	Option::Pointer m_openSwordChest;
	Option::Pointer m_quitOption;

	Sword m_sword;
	Chest m_swordChest;
	
	using Enemies = std::vector<EnemyBase::Pointer>;
	Enemies m_enemies;

	std::mutex m_mutex;
	mutable std::unique_lock<std::mutex> m_finishedQueryLock{ m_mutex, std::defer_lock };
	bool m_playerQuit{ false };
	void SetPlayerQuit()
	{
		m_finishedQueryLock.lock();
		m_playerQuit = true;
		m_finishedQueryLock.unlock();
	}
	
	bool m_playerWon{ false };

	void SetPlayerWon()
	{
		m_finishedQueryLock.lock();
		bool playerWon = m_playerWon;
		m_finishedQueryLock.unlock();
	}

	bool GetPlayerWon()
	{
		m_finishedQueryLock.lock();
		bool playerWon = m_playerWon;
		m_finishedQueryLock.unlock();

		return playerWon;
	}

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::string& playerInput) const;
	void EvaluateInput(std::stringstream& playerInput);

public:
	Game();
	virtual ~Game();

	void RunGame();

	virtual void HandleEvent(const Event* pEvent);

	//From QuitObserver
	virtual void OnQuit();

	bool HasFinished() const
	{
		m_finishedQueryLock.lock();
		bool hasFinished = m_playerQuit || m_playerWon;
		m_finishedQueryLock.unlock();

		return hasFinished;
	}
};