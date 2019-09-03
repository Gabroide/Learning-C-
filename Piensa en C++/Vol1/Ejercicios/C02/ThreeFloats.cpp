//: ThreeFloats.cpp
// Create three float vectors, filling two with a float and the third one with the sum of the others
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<float> v1;
	vector<float> v2;
	vector<float> v3;
	
	for(int i = 0; i < 25; i++)
	{
		v1.push_back(i+0.2);
		v2.push_back(i+0.5);
		v3.push_back(v1[i] + v2[i]);
	}
	
	for(int i = 0; i < v1.size(); i++)
		cout << "v1[" << i+1 << "] = " << v1[i] << "\tv2[" << i+1 << "] = " << v2[i] << "\tv3[" << i+1 << "] = " << v3[i] << endl;
	
}
