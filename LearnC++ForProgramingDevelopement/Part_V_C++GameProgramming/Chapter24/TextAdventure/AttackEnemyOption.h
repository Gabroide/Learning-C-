#pragma once

#include <iostream>

#include "Option.h"
#include "Enemy.h"
#include "Player.h"

class AttackEnemyOption
	: public Option
{
private:
	Enemy* m_enemy;

public:
	AttackEnemyOption(Enemy* enemy, const std::string& outputText);

	virtual void Evaluate(Player& player);
};

void AttackEnemyOption::Evaluate(Player& player)
{
	std::cout << std::endl << "You have chosen to " << m_outputText << std::endl << std::endl;

	if (player.HasWeapon())
	{
		if (m_enemy->IsAlive()
		{
			m_enemy->Kill();
			std::cout << "You killed it!" << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "You need to find a weapon before attacking monsters!" << std::endl << std::endl;
	}
}