//: C03:Menu.cpp
// Simple menu program demostrating
#include <iostream>
using namespace std;

int main()
{
	char c;
	while(true)
	{
		cout << "MAIN MENU: " << endl;
		cout << "l: left, r: right, q: quit -> ";
		cin >> c;
			
		if(c == 'q')
			break; // Out of "while(1)"
		if(c == 'l')
		{
			cout << "LEFT MENU: " <<endl;
			cout << "select a or b: ";
			cin >> c;
			if(c == 'a')
			{
				cout << "you chose 'a'" << endl;
				continue; // Back to main menu
			}
			if(c == 'b')
			{
				cout << "you chose 'b'" << endl;
				continue;
			}
			else
			{
				cout << "you didn't choose a or b!" << endl;
				continue;
			}
		}
		if(c == 'r')
		{
			cout << "RIGHT MENU: " << endl;
			cout << "select c or d: ";
			cin >> c;
			if(c == 'c')
			{
				cout << "you chose 'c'" << endl;
				continue;
			}
			if(c == 'd')
			{
				cout << "you chise 'd'" << endl;
				continue;
			}
			else
			{
				cout << "you didn's choose c or d!" << endl;
				continue;
			}
		}
		else
			cout << "you ust tyoe l or r or q!" << endl;
	}
	cout << "quitting menu..." << endl;
}///:~

