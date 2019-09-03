//: C02:Area.cpp
// Ask for a radius and gives back the circle area
#include <iostream>
#define PI 3.14159
using namespace std;

int main()
{
	cout << "Insert the radius of a circle: ";
	float radius;
	cin >> radius;
	
	cout << "the area of a circle with a radius of " << radius << " is: " << PI*radius*radius << endl;
} ///:~
