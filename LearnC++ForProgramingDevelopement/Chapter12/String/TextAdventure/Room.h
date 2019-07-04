#pragma once

#include "Entity.h"

class Room
	: public Entity
{
public:
	enum class JoiningDirections
	{
		North = 0,
		East,
		South,
		West,
		Max
	};

private:
	Room* m_pJoiningRooms[static_cast<unsigned int>(JoiningDirections::Max)];

public:
	Room();

	void AddRoon(JoiningDirections direction, Room* pRoom);

	Room* GetRoom(JoiningDirections direction) const;
};

Room::Room()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(JoiningDirections::Max); ++i)
	{
		m_pJoiningRooms[i] = nullptr;
	}
}

void Room::AddRoon(Room::JoiningDirections direction, Room* pRoom)
{
	m_pJoiningRooms[static_cast<unsigned int>(direction)] = pRoom;
}

Room* Room::GetRoom(Room::JoiningDirections direction) const
{
	return m_pJoiningRooms[static_cast<unsigned int>(direction)];
}