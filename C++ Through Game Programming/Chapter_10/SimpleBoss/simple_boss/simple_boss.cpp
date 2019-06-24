// simple_boss.cpp
// Demostrates inheritance

#include <iostream>

class Enemy 
{
public:
	int m_Damage;

	Enemy();

	void Attack() const;
};

Enemy::Enemy() :
	m_Damage(10)
{}

void Enemy::Attack() const 
{
	std::cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
	int m_DamageMultiplier;

	Boss();

	void SpecialAttack() const;
};

Boss::Boss() :
	m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const
{
	std::cout << "Special attack inflicts " << (m_DamageMultiplier * m_Damage) << " damage points!\n";
}

int main()
{
	std::cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();

	std::cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.SpecialAttack();

	return 0;
}