//: PowVector.cpp
// Create a float vector of 25 elements and replace every position for its power.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<float> v;
	
	for(int i = 0; i < 25; i++)
	{
		v.push_back(i+0.5);
		cout << "v[" << i+1 << "] = " << v[i] << endl;
	}
	
	cout << endl;
	
	for(int i = 0; i < v.size(); i++)
	{
		v[i] *= v[i];
		cout << "v[" << i+1 << "] = " << v[i] << endl;
	}
}
