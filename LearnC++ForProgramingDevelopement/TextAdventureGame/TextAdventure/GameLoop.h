#ifndef __GameLoop_h__
#define __GameLoop_h__

#include "Player.h"
#include "PlayerOptions.h"

namespace GameLoop 
{
	void WelcomePlayer(Player& player);
	void GivePlayerOptions();
	void GetPlayerInput(std::string& playerInput);

	PlayerOptions EvaluateInput(std::string& playerInput);

	bool RunGame();
}

#endif // __GameLoop_h__