//: C03:Guess2.cpp
// The guess program using do-while
#include <iostream>
using namespace std;

int main()
{
	int secret = 15;
	int guess = 0;
	
	do{
		cout << "guess the number: ";
		cin >> guess; // Initialization happen
	}while(guess != secret);
	
	cout << "You got it!" << endl;
}///:~
