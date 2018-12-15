#include "GameLoop.h"
#include <iostream>

using namespace std;

namespace GameLoop
{
	void WelcomePlayer(Player& player)
	{
		string name;

		cout << "Welcome to Text Adventure" << endl << endl;
		cout << "What is your name?" << endl << endl;

		cin >> name;

		player.SetName(name);

		cout << endl << "Hello " << name << endl;
	}

	void GivePlayerOptions()
	{
		cout << "What would you like to do? (Enter a corresponding number" << endl << endl;

	}

	void GetPlayerInput(string& playerInput)
	{
		cin >> playerInput;
	}

	PlayerOptions EvaluateInput(string& playerInput)
	{
		PlayerOptions chosenOption = PlayerOptions::None;

		if (playerInput.compare("1") == 0)
		{
			cout << "You have chosen to Quit" << endl << endl;
			chosenOption = PlayerOptions::Quit;
		}
		else
		{
			cout << "I do not recognize that option, try again!" << endl << endl;
		}

		return chosenOption;
	}

	bool RunGame()
	{
		bool shouldEnd = false;
		GivePlayerOptions();

		string playerInput;
		GetPlayerInput(playerInput);

		shouldEnd = EvaluateInput(playerInput) == PlayerOptions::Quit;

		return !shouldEnd;
	}
}