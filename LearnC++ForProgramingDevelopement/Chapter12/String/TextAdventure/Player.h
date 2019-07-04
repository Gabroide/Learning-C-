#pragma once

#include <string>
#include "Entity.h"

class Player
	: public Entity
{
private:
	const Room* m_pCurrentRoom;
	std::string m_name;

public:
	Player()
	{
	}

	Player(const Player& originalPlayer)
	{
		m_pCurrentRoom = originalPlayer.m_pCurrentRoom;
		m_name = originalPlayer.m_name;
	}

	Player& operator=(const Player& originalPlayer)
	{
		m_pCurrentRoom = originalPlayer.m_pCurrentRoom;
		m_name = originalPlayer.m_name;
		return *this;
	}

	void SetName(const std::string& name)
	{
		m_name = name;
	}

	const std::string& GetName() const
	{
		return m_name;
	}

	void SetCurrentRoom(const Room* pCurrentRoom)
	{
		m_pCurrentRoom = pCurrentRoom;
	}

	const Room* GetCurrentRoom() const
	{
		return m_pCurrentRoom;
	}

	void CopyPlayer(Player player)
	{

	}

	void PassPlayerByConstReference(const Player& plyer)
	{

	}

	Player(Player&& tempPlayer)
	{
		m_pCurrentRoom = tempPlayer.m_pCurrentRoom;
		m_name = tempPlayer.m_name;
	}

	Player& operator=(Player&& tempPlayer)
	{
		if (this != &tempPlayer)
		{
			m_pCurrentRoom = tempPlayer.m_pCurrentRoom;
			m_name = tempPlayer.m_name;

			tempPlayer.m_pCurrentRoom = nullptr;
			m_name.clser();
		}

		return *this;
	}
};