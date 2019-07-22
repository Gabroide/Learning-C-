#pragma once

#include "Option.h"
#include "Player.h"
#include "PlayerOptions.h"
#include "Notifier.h"
#include <string>

class QuitOption
	: public Option
	, public Notifier<QuitObserver>
{
private:
	bool m_shouldQuit;

public:
	QuitOption(const std::string& outputText)
		: Option(PlayerOptions::Quit, outputText)
		//, m_shouldQuit(false)
	{
	}

	/*bool ShouldQuit() const
	{
		return m_shouldQuit;
	}*/

	//virtual bool Evaluate(const std::string& optionText, Player& player);
	virtual void Evaluate(Player& player);
};

namespace
{
	constexpr int QuitEvent = SDBMCalculato<>::CalculateValue("QuitEvent");
}

void QuitOption::Evaluate(Player& player)
{
	Notify<&QuitObserver::OnQuit>();
}