//: FloatVector.cpp
// Create a vector with 25 float and show it on the screen

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<float> v;
	
	for(int i = 0; i < 25; i++)
		v.push_back(i + 0.2);
	
	for(int i = 0; i < v.size(); i++)
		cout << "v[" << i+1 << "] = " << v[i] << endl;
		
	return 0;
}
