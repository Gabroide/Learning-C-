// Simple Boss 3.0
// First excercise chapter 10

#include <iostream>

class Enemy
{
public:
	Enemy();
	void Attack() const;

public:
	int m_Damage;
};

Enemy::Enemy() :
	m_Damage(10)
{}

void Enemy::Attack() const
{
	std::cout << "Attack inflicts " << m_Damage << " damage point!\n";
}

class Boss : public Enemy
{
public:
	Boss();
	void SpecialAttack() const;

public:
	int m_DamageMultiplier;
};

Boss::Boss() :
	m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const
{
	std::cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage) << " damage points!\n";
}

class FinalBoss : public Enemy
{
	FinalBoss();
	void MegaAttack() const;

protected:
	int m_MegaDamageMultiplier;
};

FinalBoss::FinalBoss() :
	m_MegaDamageMultiplier(10)
{}

void FinalBoss::MegaAttack() const
{
	std::cout << "Mega Attack inflicts " << (m_MegaDamageMultiplier * m_DamageMultiplier * m_Damage) << " damge points!\n";
}

int main()
{
	std::cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();

	std::cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();

	std::cout << "\nCreating a final boss.\n";
	FinalBoss finalBoss;
	finalBoss.Attack();
	finalBoss.SpecialAttack();
	finalBoss.MegaAttack();

	return 0;
}