// Iventory Pointer
// Demostrates returning pointer

#include <iostream>
#include <vector>
#include <string>

// returns pointer to a string element
std::string* ptrToElement(std::vector<std::string>* const pVec, int i);

int main()
{
	std::vector<std::string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armot");
	inventory.push_back("shield");

	// displays string object that rhe returned pointer point to
	std::cout << "Sending the object ponted to bu retuned pounter to cout:\n";
	std::cout << *(ptrToElement(&inventory, 0)) << "\n\n";
	
	// assigns one pointer to another -- inexpensive assignement
	std::cout << "Assignng here the returned pointer to another pointer:\n";
	std::string* pStr = ptrToElement(&inventory, 1);
	std::cout << "Sending the object pointed to by new pointer.\n";
	std::cout << *pStr << "\n\n";

	// copies a string object -- expensive assignment
	std::cout << "Assigning object pointed to by pointer to a string to cout:\n";
	std::string str = *(ptrToElement(&inventory, 2));
	std::cout << "Sending the new string object to cout:\n";
	std::cout << str << "\n\n";

	// altering the string object though a returned pointer
	std::cout << "Altering an object through a returned pointer.\n";
	*pStr = "Healing Potion";
	std::cout << "Sending the altered object to cout:\n";
	std::cout << inventory[1] << std::endl;

	return 0;
 }

std::string* ptrToElement(std::vector<std::string>* const pVec, int i)
{
	// returns address of the string in position of vector that pVec points to
	return &((*pVec)[i]);
}