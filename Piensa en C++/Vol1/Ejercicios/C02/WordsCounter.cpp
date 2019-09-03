//: WordsCounter.cpp
// Create a program that opens a file and count the whitespaces-separated words in that file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int count = 0;
	ifstream in("WordsCounter.cpp");
	string words;
	
	while(in >> words)
		++count;
		
	cout << "white-separated words: " << count << endl;
	
	return 0;
}
