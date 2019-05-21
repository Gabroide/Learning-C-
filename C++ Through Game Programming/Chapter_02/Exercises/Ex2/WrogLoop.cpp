// Wrong Loop
#include <iostream>

int main()
{
	/*int x = 0;
	while (x)
	{
		++x;
		std::cout << x << std::endl;
	}

	The problem is that as x value is 0, it means that it is false so the loop will never be executed.
	To allow the program go inside the loop, is should be writen in the following way:*/

	int x = 0;

	while (!x)
	{
		++x;
		std::cout << x << std::endl;
	}
}