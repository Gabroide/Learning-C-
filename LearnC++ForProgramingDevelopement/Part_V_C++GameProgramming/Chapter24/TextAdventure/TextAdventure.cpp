#include "Player.h"
#include "Game.h"
#include "GameLoop.h"
#include "SerializationManager.h"

int main()
{
	new SerializationManager();

	Game game;
	game.RunGame();

	delete SerializationManager::GetSingletonPtr();

	return 0;
}