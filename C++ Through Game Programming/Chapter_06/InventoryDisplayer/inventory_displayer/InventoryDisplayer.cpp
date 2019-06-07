// Inventory Displayer
// Demostrates constant references

#include <iostream>
#include <string>
#include <vector>

// parameter vec is a constant reference to a vector of strings
void display(const std::vector<std::string>& inventory);

int main()
{
	std::vector<std::string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	display(inventory);
}

// parameter vec is a constantreference to a vector of strings
void display(const std::vector<std::string>& vec)
{
	std::cout << "Your items:\n";

	for (std::vector<std::string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		std::cout << "\t" << *iter << std::endl;
	}
}