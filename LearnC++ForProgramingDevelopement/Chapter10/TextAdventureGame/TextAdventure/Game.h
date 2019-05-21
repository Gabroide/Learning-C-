#ifndef __Game_h__
#define __Game_h__

#include "Player.h"
#include "PlayerOptions.h"

class Game
{
private:
	Player player;

	void WelcomePlayer();
	void GivePlayerOptions();
	void GetPlayerInput(std::string& playerInput);

	PlayerOptions EvaluateInput(std::string& playerInput);

public:
	void RunGame();
}

#endif // __Game_h__