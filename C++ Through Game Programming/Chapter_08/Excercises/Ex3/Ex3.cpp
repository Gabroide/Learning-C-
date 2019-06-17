// Design problem
/*
#include <iostream>

class Critter
{
public:
	int GetHunger() const
	{
		return m_Hunger;
	}

private:
	int m_Hunger;
};

int main()
{
	Critter crit;
	std::cout << crit.GetHunger() << std::endl;

	return 0;
}*/

// Explanation: THe problem is that the definition of GetHunger() function is placed where should be the prototype definition.
// The program will run with any problem as it is a structure problem and no a code problem; but this structure can generate confusion 
// to other programmers who have to follow or keep on with the code.

// Design problem solved
#include <iostream>

class Critter
{
public:
	int GetHunger() const;

private:
	int m_Hunger;
};

int Critter::GetHunger() const
{
	return m_Hunger;
}

int main()
{
	Critter crit;
	std::cout << crit.GetHunger() << std::endl;

	return 0;
}