//: C03:PrintBinary.cpp (O)
#include <iostream>
//#include <PrintBinary.h>

void PrintBnary(const unsigned char val)
{
	for(int i = 7; i >= 0; i--)
	{
		if(val & (1 << i))
			std::cout << "1";
		else
			std::cout << "0";
	}///:~
}
