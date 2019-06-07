// Taking Damage
// Demostrates function  inling

#include <iostream>

int radiation(int health);

int main()
{
	int health = 80;
	std::cout << "Your health is " << health << "\n\n";

	health = radiation(health);
	std::cout << "After radiation exposure your health is " << health << "\n\n";

	health = radiation(health);
	std::cout << "After radiation exposure your health is " << health << "\n\n";

	health = radiation(health);
	std::cout << "After radiation exposure your health is " << health << "\n\n";

	return 0;
}

inline int radiation(int health)
{
	return (health / 2);
}