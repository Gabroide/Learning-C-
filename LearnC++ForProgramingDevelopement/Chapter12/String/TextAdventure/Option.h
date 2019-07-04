#pragma once

#include "PlayerOptions.h"
#include <string>

class Option
{
protected:
	PlayerOptions	m_chosenOption;
	std::string		m_outoutText;
	std::string		m_optionText;

public:
	Option(PlayerOptions chosenOption, const std::string& outputText)
		: m_chosenOption(chosenOption)
		, m_outoutText(outputText)
	{
	}

	void SetOptionText(const std::string& optionText)
	{
		m_optionText = optionText;
	}

	const std::string& GetOutputText() const
	{
		return m_outoutText;
	}

	PlayerOptions GetChosenOptuin() const
	{
		return m_chosenOption;
	}

	virtual bool Evaluate(const std::string& optionText, Player& player) = 0;
};