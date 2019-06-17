// Static Critter
// Demostrates static member variables and functions

#include <iostream>

class Critter
{
public:
	static int s_Total;			// static member variable declaration
								// total number of Critter objects in existence

	Critter(int hunger = 0);
	static int GetTotal();		// static member function prototype

private:
	int m_Hunger;
};

int Critter::s_Total = 0;		// static member function prototype

Critter::Critter(int hunger):
	m_Hunger(hunger)
	{
	std::cout << "A critter has been born!" << std::endl;
	++s_Total;
	}

int Critter::GetTotal()
{
	return s_Total;
	}

int main()
{
	std::cout << "The total number of critters is: ";
	std::cout << Critter::s_Total << "\n\n";
	Critter	crit1, crit2, crit3;

	std::cout << "\nThe total number of critters is: ";
	std::cout << Critter::GetTotal() << "\n";

	return 0;
}