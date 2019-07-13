#pragma once

#include "Room.h"
#include "PlayerOptions.h"
#include "Option.h"
#include <string>
#include <iostream>

class MoveOption
	: public Option
{
private:
	Room::JoiningDirections m_directionToMove;

public:
	MoveOption(Room::JoiningDirections joiningDirection, PlayerOptions chosenOption, const std::string& outputText)
		: Option(chosenOption, outputText)
		, m_directionToMove(joiningDirection)
	{
	}

	virtual bool Evaluate(const std::string& optionText, Player& player);
};

bool MoveOption::Evaluate(const std::string& optionText, Player& player)
{
	bool handled = false;

	if (m_optionText.compare(optionText) == 0)
	{
		const Room* pPlayerCurrentRoom = player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(m_directionToMove);

		if (pNewRoom != nullptr)
		{
			player.SetCurrentRoom(pNewRoom);
			std::cout << "You have chosen to " << std::endl << std::endl;
		}
		else
		{
			const char* strDirection = "North";
			switch (m_chosenOption)
			{
			case PlayerOptions::GoEast:
				strDirection = "East";
				break;

			case PlayerOptions::GoSouth:
				strDirection = "South";
				break;

			case PlayerOptions::GoWest:
				strDirection = "West";
				break;
			}

			std::cout << "There is no room to the " << strDirection << std::endl << std::endl;
		}

		handled = true;
	}

	return handled;
}