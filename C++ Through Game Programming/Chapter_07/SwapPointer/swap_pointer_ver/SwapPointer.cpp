// Swap Pointer
// Deostrates passing constants pointers to alter argument variable
#include <iostream>

void badSwap(int x, int y);
void goodSwap(int* const pX, int* const pY);

int main() 
{
	int myScore = 150;
	int yourScore = 1000;

	std::cout << "Original values:\n";
	std::cout << "myScore: " << myScore << "\n";
	std::cout << "yourScore: " << yourScore << "\n\n";
	
	std::cout << "Calling badSwap()\n";
	badSwap(myScore, yourScore);
	std::cout << "myScore; " << myScore << "\n";
	std::cout << "yourScore: " << yourScore << "\n\n";

	std::cout << "Callint goodSwap()\n";
	goodSwap(&myScore, &yourScore);
	std::cout << "myScore: " << myScore << "\n";
	std::cout << "yourScore: " << yourScore << "\n\n";

	return 0;
}

void badSwap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void goodSwap(int* const pX, int* const pY)
{
	// store value pointed by pX in temp
	int temp = *pX;
	
	// Store value pointed by pY in addess pointed to by pX
	*pX = *pY;

	// store value originally pointed to by pX in address pointed to by pY
	*pY = temp;
}