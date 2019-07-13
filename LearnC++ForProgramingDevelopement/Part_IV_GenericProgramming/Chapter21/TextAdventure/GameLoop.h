#pragma once

#include "Player.h"
#include "PlayerOptions.h"

namespace GameLoop
{
	void WelcomePlayer(Player& player);
	void GetPlayerInput(std::string& playerInput);

	PlayerOptions EvaluateInput(std::string& playerIntpu);

	bool RunGame();
}