//: C03:Specify.cpp
// Demostrates the use of specifiers
#include <iostream>
using namespace std;

int main()
{
	char c;
	unsigned char cu;
	int i;
	unsigned int iu;
	short int is;
	short iis; // Same as shirt int
	unsigned short int isu;
	unsigned short iisu; // Same as unsigned short int
	long int il;
	long iil; // Same as long int
	unsigned long int ilu;
	unsigned long iilu; // Same as unsigned long int
	float f;
	double d;
	long double ld;
	cout 
		<< "\n char = " << sizeof(c)
		<< "\n unsigned char = " << sizeof(cu)
		<< "\n int = " << sizeof(i)
		<< "\n unsigned int = " << sizeof(iu)
		<< "\n short int = " << sizeof(is)
		<< "\n short = " << sizeof(iis)
		<< "\n usigned short int = " << sizeof(isu)
		<< "\n unsiged short = " << sizeof(iisu)
		<< "\n long int = " << sizeof(il)
		<< "\n long = " << sizeof(iil)
		<< "\n unsigned long int = " << sizeof(ilu)
		<<  "\n unsigned long = " << sizeof(iilu)
		<< "\n float = " << sizeof(f)
		<< "\n double = " << sizeof(d)
		<< "\n long double = " << sizeof(ld)
		<< endl;
}
