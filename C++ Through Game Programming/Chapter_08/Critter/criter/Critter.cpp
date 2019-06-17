// Simple Critter
// Demostrates creating a new type

#include <iostream>

class Critter			// class definition -- defines new type, Critter
{
public:
	int m_Hunger;		// data member
	void Greet();		// member function prototype
};

void Critter::Greet()	// member function definition
{
	std::cout << "Hi, I'm a critter. My hunger level s " << m_Hunger << ".\n";
}

int main()
{
	Critter crit1;
	Critter crit2;

	crit1.m_Hunger = 9;
	std::cout << "Crit1's hunger level is " << crit1.m_Hunger << ".\n";

	crit2.m_Hunger = 3;
	std::cout << "Crit2's hunger level is " << crit2.m_Hunger << ".\n\n";

	crit1.Greet();
	crit2.Greet();

	return 0;
}