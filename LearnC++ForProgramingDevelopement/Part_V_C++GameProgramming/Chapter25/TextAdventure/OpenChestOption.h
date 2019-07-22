#pragma once

#include <iostream>

#include "Option.h"
#include "Player.h"
#include "Chest.h"

class OpenChestOption
	: public Option
{
private:
	Chest* m_chest;

public:
	OpenChestOption(Chest* chest, const std::string& outputText)
		: m_chest{ chest }
	{

	}

	virtual void Evaluate(Player& player);
};

void OpenChestOption::Evaluate(Player& player)
{
	if (m_chest->IsOpen() == false)
	{
		const Item* item = m_chest->Open();
		player.AddItem(item);

		std::cout << "You picked uo a " << item->GetName() << " from the chest!" << std::endl << std::endl;
	}
}