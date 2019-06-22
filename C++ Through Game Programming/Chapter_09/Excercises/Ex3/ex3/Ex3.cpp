// Ex3.cpp
// Wrong code
/*
#include <iostream>

int main()
{
	int* pScore = new int;
	*pScore = 500;
	pScore = new int(100);
	delete pScore;
	pScore = 0;

	return 0;
}
*/
// Correct code
// The problem is that we have a dangling pointer which produces a leak of memory to watch this we can modify the code in this way
// Also the code is creating an int object allocating memory for the variable pScore. This object is eliminated and later we the same variable is
// using to store a literal integer.
// This can be confusing.

#include <iostream>

int main()
{
	int* pScore = new int;
	*pScore = 500;
	std::cout << *pScore << "\n\n";
	pScore = new int(100);
	std::cout << *pScore << "\n";
	std::cout << *pScore << "\n\n";
	delete pScore;
	std::cout << pScore << "\n\n";
	pScore = 0;
	std::cout << pScore;

	return 0;
}