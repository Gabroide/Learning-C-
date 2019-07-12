#pragma once

#include "Player.h"
#include "Room.h"
#include "Option.h"
#include "MoveOption.h"
#include "QuitOption.h"
#include "AttackEnemyOption.h"
#include "OpenChestOption.h"

class Game
{
private:
	static const unsigned int m_numberOfRooms = 4;
	using Rooms = std::array<Room, m_numberOfRooms>;
	Rooms m_rooms;

	Player m_player;

	AttackEnemyOption m_attackDragonOption;
	AttackEnemyOption m_attackOrcOption;
	MoveOption m_moveNorthOption;
	MoveOption m_moveEastOption;
	MoveOption m_moveSouthOption;
	MoveOption m_moveWestOption;
	OpenChestOption m_openSwordChest;

	QuitOption m_quitOption;

	Sword m_sword;
	Chest m_chest;
	Enemy m_dragon;
	Enemy m_orc;

	static const unsigned int m_numberOfOptions = 5;
	Option* m_options[m_numberOfOptions];

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::string& playerInput) const;
	
	PlayerOptions EvaluateInput(std::stringstream& playerInputStream);

public:
	Game();

	void RunGame();
};