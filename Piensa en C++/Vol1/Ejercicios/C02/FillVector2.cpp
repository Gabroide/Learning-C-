//: C02:FillVector2.cpp
// Copy an entire file into a vector of string and concatenate two elements
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    vector<string> v;
    ifstream in("FillVector2.cpp");
    string line;
    string overall;

    while(getline(in, line))
        v.push_back(line);

    for(int i = 0; i < v.size(); i++)
        overall = overall + v[i] + '\n';

    cout << overall << endl;

	return 0;
}
