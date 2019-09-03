//: AWordCounter.cpp
// Create a program that opens a file and count the whitespaces-separated words in that file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	int count = 0;
	string key;
	
	cout << "Please enter the word to search: ";
	cin >> key;
	
	ifstream in("WordsCounter.cpp");
	string words;
	
	while(in >> words)
		if(words == key)
			++count;
	
	cout << "The word " << key << " appears " << count << " times." << endl;
	
	return 0;
}
