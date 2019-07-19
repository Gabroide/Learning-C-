#pragma once

#include "PlayerOptions.h"
#include <string>

class Option
	: public Visitable
{
public:
	using Pointer = std::shared_ptr<Option>;

protected:
	PlayerOptions	m_chosenOption;
	std::string		m_outoutText;

public:
	Option(PlayerOptions chosenOption, const std::string& outputText)
		: m_chosenOption(chosenOption)
		, m_outoutText(outputText)
	{
	}

	const std::string& GetOutputText() const
	{
		return m_outoutText;
	}

	virtual bool Evaluate(const std::string& optionText, Player& player) = 0;
};

Option* CreatedOption(PlayerOptions optionType)
{
	Option* pOption = nullptr;

	switch (optionType)
	{
	case PlayerOptions::GoNorth:
		pOption = new MoveOption(Room::JoiningDirections::North, PlayerOptions::GoNorth, "Go North");
		break;
		
	case PlayerOptions::GoSouth:
		pOption = new MoveOption(Room::JoiningDirections::South, PlayerOptions::GoSouth, "Go South");
		break;

	case PlayerOptions::GoEst:
		pOption = new MoveOption(Room::JoiningDirections::Est, PlayerOptions::GoEst, "Go Est");
		break;

	case PlayerOptions::GoWest:
		pOption = new MoveOption(Room::JoiningDirections::West, PlayerOptions::GoWest, "Go West");
		break;

	case PlayerOptions::OpenChest:
		pOption = new OpenChestOption("Open Chest");
		break;

	case PlayerOptions::AttackEnemy:
		pOption = new AttackEnemyOption();
		break;

	case PlayerOptions::Quit:
		pOption = new QuitOption("Quit");
		break;

	case PlayerOptions::None:
		break;

	default:
		break;
	}

	return pOption;
}