// Constructor Critter
// Demostrates constructors

#include <iostream>

class Critter
{
public:
	int m_Hunger;
	Critter(int hunger = 0);		// Constructor prototype
	void Greet();
};

Critter::Critter(int hunger)
{
	std::cout << "A new Critter has been born!" << std::endl;
	m_Hunger =e hunger;
}

void Critter::Greet()
{
	std::cout << "hi, I'am a critter. My hunger level is " << m_Hunger << ".\n\n";
}

int main()
{
	Critter crit(7);
	crit.Greet();

	return 0;
}