// Excercise 1 Chapter 7
// Demostrates Pointer to a pointer

#include <iostream>

int main()
{
	std::string str = "Hello world!";
	std::string* pStr;
	pStr = &str;

	//std::string* pSize = 0;
	int size = pStr->size();
	int* pSize = &size;

	std::cout << pStr << "\n";
	std::cout << *pSize;
}