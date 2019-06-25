//Abstract Creature
//Demonstrates abstract classes

#include <iostream>

class Creature  //abstract class
{
public:
	Creature(int health = 100);
	virtual void Greet() const = 0;   //pure virtual member function
	virtual void DisplayHealth() const;

protected:
	int m_Health;
};

Creature::Creature(int health) :
	m_Health(health)
{}

void Creature::DisplayHealth() const
{
	std::cout << "Health: " << m_Health << std::endl;
}

class Orc : public Creature
{
public:
	Orc(int health = 120);
	virtual void Greet() const;
};

Orc::Orc(int health) :
	Creature(health)
{}

void Orc::Greet() const
{
	std::cout << "The orc grunts hello.\n";
}

class OrcBoss : public Creature
{
public:
	OrcBoss(int health = 180);
	virtual void Greet() const;
};

OrcBoss::OrcBoss(int health) :
	Creature(health)
{}

void OrcBoss::Greet() const
{
	std::cout << "The orc boss growls hello.\n";
}

int main()
{
	Creature* pCreature = new Orc();
	pCreature->Greet();
	pCreature->DisplayHealth();

	Creature* pCreatureB = new OrcBoss();
	pCreatureB->Greet();
	pCreatureB->DisplayHealth();

	return 0;
}
