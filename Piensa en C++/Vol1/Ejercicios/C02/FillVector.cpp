//: C02:FillVector.cpp
// Copy an entire file into a vector of string and show it in a reverse order
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    vector<string> v;
    ifstream in("FillVector.cpp");
    string line;
    while(getline(in, line))
        v.push_back(line);

    for(int i = v.size()-1; i >= 0; i--)
        cout << i << ": " << v[i] << endl;
} ///:~
