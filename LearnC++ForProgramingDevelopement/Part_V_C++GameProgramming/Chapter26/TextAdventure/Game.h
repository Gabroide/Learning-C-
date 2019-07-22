#pragma once

#include "Player.h"
#include "Room.h"
#include "Option.h"
#include "MoveOption.h"
#include "QuitOption.h"
#include "AttackEnemyOption.h"
#include "OpenChestOption.h"

class Game
	: public EventHandler
	, public QuitObserver
{
private:
	static const unsigned int m_numberOfRooms = 4;
	using Rooms = std::array<Room, m_numberOfRooms>;
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
	Chest m_chest;

	using Enemies = std::vector<Enemy::Pointer>;
	Enemies m_enemies;

	bool m_playerQuit{ false };

	//static const unsigned int m_numberOfOptions = 5;
	//Option* m_options[m_numberOfOptions];

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::string& playerInput) const;
	void EvaluateInput(std::stringstream& playerInputStream);

public:
	Game();
	~Game();

	void RunGame();

	virtual void HandleEvent(const Event* pEvent);

	//From QuitObserver
	virtual void OnQuit();
};