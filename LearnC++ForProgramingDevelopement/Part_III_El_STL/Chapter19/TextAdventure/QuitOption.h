#pragma once

#include "Option.h"
#include "Player.h"
#include "PlayerOptions.h"
#include <string>

class QuitOption
	: public Option
{
private:
	bool m_shouldQuit;

public:
	QuitOption(const std::string& outputText)
		: Option(PlayerOptions::Quit, outputText)
		, m_shouldQuit(false)
	{
	}

	bool ShouldQuit() const
	{
		return m_shouldQuit;
	}

	virtual bool Evaluate(const std::string& optionText, Player& player);
};

bool QuitOption::Evaluate(const std::string& optionText, Player& player)
{
	m_shouldQuit = m_optionText.compare(optionText) == 0;

	if (m_shouldQuit == true)
	{
		std::cout << "You have chosen to quit!" << std::endl << std::endl;
	}

	return m_shouldQuit;
}