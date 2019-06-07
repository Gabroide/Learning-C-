// Hero's Inventory 3.0
// Demostrates iterators

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	std::vector<std::string>::iterator myIterator;
	std::vector<std::string>::const_iterator iter;

	std::cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}

	std::cout << "\nYou trade your sword for a battle axe.";
	myIterator = inventory.begin();
	*myIterator = "battle axe";

	std::cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}

	std::cout << "\nThe item name '" << *myIterator << "' has ";
	std::cout << (*myIterator).size() << " letters in it.\n";
	
	std::cout << "\nThe item name '" << *myIterator << "' has ";
	std::cout << myIterator->size() << " letters in it.\n";

	std::cout << "\You recover a crossbow from a slain enemy.";
	inventory.insert(inventory.begin(), "crossbow");

	std::cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}

	std::cout << "\nYour armor is destroyed in a fierece battle.";
	inventory.erase(inventory.begin() + 2);
	std::cout << "\nYour items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}

	return 0;
}