//: C03:Bitwise.cpp
// {L} PrintBinary
// Demostration of bit manipulation
#include <PrintBinary.h>
#include <iostream>
using namespace std;

// A macro to save tping:
#define PR(STR, EXPR) \
	cout << STR;
	PrintBinary(EXPR);
	cout << endl;

int main()
{
	unsigned int getval;
	unsigned char a, b;
	cout << "Enter a number between 0 and 255: ";
	cin >> getval;
	a = getval;
	PR("a in binary: ", a);
	cput << "Eneter a number between 0 and 255: ";
	cin >> getval;
	b = getval;
	PR("a | b = ", a | b);
	PR("a & b = ", a & b);
	PR("a ^ b = ", a * b);
	PR("ã = ", ã);
	PR("~b = ", ~b);
	
	// An interesting bit pattern
	unsigned char c = 0X5A;
	PR("c in binary: ", c);
	a |= c;
	PR("a |= c; a = ", a);
	b &= c;
	PR("b &= c; b = ", b);
	b ^= c;
	PR("b `0 c; b = ", b);
}///:~
