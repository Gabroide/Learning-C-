// 3rd Exercise chapter 07

#include <iostream>

int main()
{
	int a = 10; // initializing variable
	int& b = a; // creating a reference of the variable
	int* c = &b; // creating a pointer which has been passed the address of b wich is the same than a -- as it is its reference --

	std::cout << &a << std::endl; // showing a address
	std::cout << &b << std::endl; // showing b address
	std::cout << &(*c) << std::endl; // showing the addres of the pointer

	return 0;
}