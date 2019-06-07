// Word Jumble 2.0
// Getting a score; now the game doesn't finish till the user types quit.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main()
{
	enum fields{ WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const std::string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all abut."}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	int countHint = 0;
	std::string theWord = WORDS[choice][WORD]; // Word to guess
	std::string theHint = WORDS[choice][HINT];

	std::string jumble = theWord; // jumbled version of word
	int length = jumble.size();
	for (unsigned int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	std::cout << "\t\tWelcome to Word Jumble!\n\n";
	std::cout << "Unscramble the letters to make a word.\n";
	std::cout << "Enter 'hint' for a hint.\n";
	std::cout << "Enter 'quit' to quit the game.\n\n";
	std::cout << "The jumble is: " << jumble;

	std::string guess;
	std::cout << "\nYour guess: ";
	std::cin >> guess;

	// Game Loop
	while ((guess != theWord) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			std::cout << theHint;
			++countHint;
		}
		else
		{
			std::cout << "Sorry, That's not it.";
		}

		std::cout << "\nYour guess: ";
		std::cin >> guess;
	}

	if (guess == theWord)
	{
		std::cout << "\nThat's it! You guessed it!\n";
		std::cout << "\nYour score is " << (theWord.length() - 3*countHint) << ".\n";
	}
	if (guess == "quit")
	{
		std::cout << "Thanks for playing.\n";
	}

	std::cout << "Thanks for playing.\n";

	return 0;
}