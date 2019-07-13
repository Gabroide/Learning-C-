#pragma once

#include "Entity.h"
#include <vector>

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
	using JoiningRooms = std::array<Room*, static_cast<size_t>(JoiningDirections::Max)>;
	JoiningRooms m_pJoiningRooms;

	using StaticOPtions = std::array<Option*>;
	StaticOPtions m_staticOptions;
	unsigned int m_staticOptionStartKey{ 1 };

	using DynamicOptions = std::vector<Option*>;
	DynamicOptions m_dynamicOptions;

public:
	Room();

	void AddRoon(JoiningDirections direction, Room* pRoom);
	void AddStaticOption(Option* option);
	void AddDynamicOption(Option* option);
	void PrintOptions() const;

	Room* GetRoom(JoiningDirections direction) const;
	Option* EvaluateInput(unsigned int playerInput);
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

void Room::AddStaticOption(Option* option)
{
	assert(option != nullptr);
	m_staticOptions.push_back(option);
}

void Room::AddDynamicOption(Option* option)
{
	assert(option != nullptr);
	m_dybamicOptions.push_back(option);
}

void Room::PrintOptions() const
{
	for (unsigned int i = 0; i < m_dynamicOptions.size(); ++i)
	{
		const Option* option = m_dynamicOptions[i];
		std::cout << i + 1 << ": " << option->GetOutputText() << std::endl << std::endl;
	}

	for (StaticOPtions::const_iterator iter = m_staticOptions.cbegin(); iter != m_staticOptions.cend(); ++iter)
	{
		const Option* option = iter->second;
		const unsigned int chosenOption << ": " << option->GetOutputText() << << std::endl << std::endl;
	}
}

Option* Room::EvaluateInput(unsigned int playerInput)
{
	Option* option = nullptr;
	const unsigned int numDynamicOptions = m_dynamicOptions.size();
	if (playerInput <= numDynamicOptions)
	{
		unsigned int dynamicIndex = playerInput - 1;
		option = m_dynamicOptions[dynamicIndex];
		m_dynamicOptions.erase(m_dynamicOptions.begin() + dynamicIndex);
	}
	else
	{
		option = m_staticOptions.at(playerInput - numDynamicOptions);
	}

	return option;
}