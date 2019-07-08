#include <iostream>
#include <sstream>
#include <iomanip>
#include <ios>

void StrinStreamExemple()
{
	std::stringstream myStringStream;

	myStringStream << "Hi" << std::endl;

	std::cout << "width: " << myStringStream.width() << std::endl;
	myStringStream << 123 << std::endl;
	myStringStream << std::setw(10) << 123 << std::end;
	myStringStream << std::setw(0) << 123 << std::endl;

	myStringStream << 123.567 << std::endl;
	myStringStream << std::setprecision(4) << 123.567 << std::endl;
	myStringStream << std::fixed << std::setprecision(2) << 123.567 << std::endl;
	myStringStream << std::defaultfloat << std::setprecision(0) << 123.567 << std::endl;

	myStringStream << 110 << std::endl << std::showbase;
	myStringStream << std::hex << 110 << std::endl;
	myStringStream << std::oct << 110 << std::endl;
	myStringStream << std::dec << 110 << std::endl << std::noshowbase;

	std::string myString = myStringStream.str();
	std::cout << myString;
}