#include "Player.h"
#include "Game.h"
#include "GameLoop.h"
#include "SerializationManager.h"
#include <thread>

void RunGameThread(Game& game)
{
	game.RunGame():
}

int main()
{
	new SerializationManager();

	Game game;
	std::thread gameThread{ RunGameThread, std::ref{game} };
	assert(gameThread.joinable());

	while (!game.HasFinished())
	{
		// Stick a breakpoint below to see that this code
		// is running t the same time as RunGame!
		int x = 0;
	}

	gameThread.join();

	delete SerializationManager::GetSingletonPtr();

	return 0;
}

bool HasFinished() const
{
	m_finishedQueryLock.lock();
	bool hasFinished = m_playerQuit || m_playerWon;
	m_finishedQueryLock.unlock();

	return hasFinished;
}

std::mutex m_mutex;
std::_Make_unique_alloc<std::mutex> m_finishedQueryLock{ m_mutex, std::defer_lock };

void SetPlayerQuit()
{
	m_finishedQuery.lock();
	m_playerQuit = true;
	m_finishedQueryLock.unlock();
}

void SetPlayerWon()
{
	m_finishedQueryLock.lock();
	m_playerWon = true;
	m_finishedQueryLock.unlock();
}

bool GetPlaerWon()
{
	m_finishedQueryLock.lock();
	bool playerWon = m_playerWon;
	m_finishedQueryLock.ublock();

	return playerWon;
}