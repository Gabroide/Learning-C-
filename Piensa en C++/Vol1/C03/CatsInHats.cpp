//: C03:CatsInHats.cpp
// Simple demostration of recursion
#include <iostream>
using namespace std;

void removeHat(char cat)
{
	for(char c = 'A'; c < cat; c++)
	{
		cout << " ";
		if(cat <= 'Z')
		{
			cout << "cat " << cat << endl;
			removeHat(cat + 1); // Recursice call
		}
		else
		{
			cout << "VOOM!!!" << endl;
		}
	}
}

int main()
{
	removeHat('A');
}///:~
