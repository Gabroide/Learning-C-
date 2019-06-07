// Hero's Inventory 2.0
// Demostrates vectors

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> inventory;
	inventory.push_back("sword");
	inventory.push_back("ammor");
	inventory.push_back("shield");

	std::cout << "You have: " << inventory.size() << " items.\n";
	std::cout << "\nYour items are:\n";

	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		std::cout << "\t" << inventory[i] << std::endl;
	}

	std::cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe.";

	std::cout << "\nYour items are:\n";

	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		std::cout << "\t" << inventory[i] << std::endl;
	}

	std::cout << "\nThe item name '" << inventory[0] << "' has ";
	std::cout << inventory[0].size() << " letters in it.\n";
	std::cout << "\nYour shield is destroyed in a fierence battle.";
	inventory.pop_back();
	
	std::cout << "\nYour items are:\n";

	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		std::cout << "\t" << inventory[i] << std::endl;
	}

	std::cout << "\nYou were robbed of all your possessions by a thief.";
	inventory.clear();

	if (inventory.empty())
	{
		std::cout << "\nYou have nothing.\n";
	}
	else
	{
		std::cout << "\nYou have at least one item.\n";
	}

	return 0;
}