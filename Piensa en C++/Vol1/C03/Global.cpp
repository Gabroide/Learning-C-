//: C03:Global.cpp
//(L) Global2
// Demostration of global variables
#include <iostream>
using namespace std;

int globe;
void func();

int main()
{
	globe = 12;
	cout << globe << endl;
	func(); // Modifies global
	cout << globe << endl;
} ///:~
