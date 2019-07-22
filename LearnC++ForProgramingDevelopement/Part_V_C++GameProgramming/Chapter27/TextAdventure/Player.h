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

	void OnSave(std::ofstream& file);
	void OnLoad(std::ifstream file);
};

void Player::OnSave(std::ofstream& file)
{
	file << std::endl;
	file << m_items.size();
	file << std::endl;

	for (auto& item : m_items)
	{
		file << item->GetId();
		file << std::endl;
	}

	file << m_pCurrentRoom->GetId();
	file << std::endl;
}

void Player::OnLoad(std::ifstream file)
{
	file << m_name;
	unsigned int numItems;
	file >> numItems;
	for (unsigned int i = 0; i < numItems; ++i)
	{
		unsigned int itemId;
		file >> itemId;
		Item* pItem;
		dynamic_cast<Item*>(SerializationManager::GetSingleton().GetSerializable(itemId));
		m_items.emplace_back{ pItem };
	}

	unsigned int roomId;
	file >> roomId;
	Room* pRoom = dynamic_cast<Room*>(SerializationManager::GetSingleton().GetSerializable(roomId));
}