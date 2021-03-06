// Critter Caretaker 3.0

#include <iostream>

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);

	int GetHunger();
	int GetBoredom();

private:
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	std::cout << "I am a critter and I feel ";
	int mood = GetMood();

	if (mood > 15)
	{
		std::cout << "mad.\n";
		std::cout << "Play with me or I will start destroying the house.\n";
	}
	else if (mood > 10)
	{
		std::cout << "frustated.\n";
		std::cout << "I am crying because you don't play with me.\n";
	}
	else if (mood > 5)
	{
		std::cout << "okay.\n";
		std::cout << "I would like to play a bite.\n";
	}
	else
	{
		std::cout << "happy.\n";
		std::cout << "I am tired of playing.\n";
	}

	PassTime();
}

void Critter::Eat(int food)
{
	std::cout << "Brrrup.\n";

	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	PassTime();
}

void Critter::Play(int fun)
{
	std::cout << "Wheeeee!\n";
	m_Boredom -= fun;

	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}

	PassTime();
}

int Critter::GetHunger()
{
	return m_Hunger;
}

int Critter::GetBoredom()
{
	return m_Boredom;
}

int main()
{
	Critter crit;
	crit.Talk();

	int choice;
	do
	{
		std::cout << "\nCritter Caretaker\n\n";
		std::cout << "0 - Quit\n";
		std::cout << "1 - Listen to your critter\n";
		std::cout << "2 - Feed your critter\n";
		std::cout << "3 - Play with your critter\n";
		std::cout << "4 - Hunger level\n";
		std::cout << "5 - Boredom level\n\n";

		std::cout << "Choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 0:
			std::cout << "Good-bye\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4:
			std::cout << "My hunger level is " << crit.GetHunger() << "\n";
			break;
		case 5:
			std::cout << "My boredom level is " << crit.GetBoredom() << "\n";
			break;
		default:
			std::cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
			break;
		}
	} while (choice != 0);

	return 0;
}