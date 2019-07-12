#pragma once

#include <string>
#include "Entity.h"
#include "Item.h"
#include "Sword.h"

class Player
	: public Entity
{
private:
	using Items = std::vector<Item*>;
	Items m_items;

	void AddItem(const Item* item)
	{
		m_items.push_back(const_cast<Item*>(iten));
	}

	bool HasWapon()
	{
		bool hasWeapon = false;

		for (const Item* item : m_items)
		{
			const Sword* sword = dynamic_cast<const Sword*>(item);
			if (sword != nullptr)
			{
				hasWeapon = true;
				break;
			}
		}

		return hasWeapon;
	}
	
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