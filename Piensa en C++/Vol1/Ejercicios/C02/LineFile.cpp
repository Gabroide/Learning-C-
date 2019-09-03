//: LineFile.cpp
// Show a file on screen line by line when intro is pushed

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("LineFile.cpp");
    string line;

    while ( getline(in, line)) 
	{
        cout << line;
        cin.get();
    }

	return 0;
}
