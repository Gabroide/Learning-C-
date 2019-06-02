// Exercise 2
// The classic game of hangman using functions 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

char PlayerGuess();
bool IsGuessed(const std::string THE_WORD, char guess);


int main()
{
	// setup
	const int MAX_WRONG = 8;					// Maximum number of incorrect guesses allowed

	std::vector<std::string> words;				// collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	std::random_shuffle(words.begin(), words.end());

	const std::string THE_WORD = words[0];		// word to guess
	int wrong = 0;								// number of incorrect guesses
	std::string soFar(THE_WORD.size(), '-');	// word guessed so far
	std::string used = "";						// letters already guessed

	std::cout << "Welcome to Hangman. Good luck!\n";

	// main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		std::cout << "\n\nYou have " << (MAX_WRONG - wrong);
		std::cout << " incorrect guesses left.\n";
		std::cout << "\nYou've used the following letters: \n" << used << std::endl;
		std::cout << "\nSo far. the word is: " << soFar << std::endl;

		char guess = PlayerGuess();

		while (used.find(guess) != std::string::npos)
		{
			std::cout << "\nYou have already guessed: " << guess << std::endl;
			
			char guess = PlayerGuess();
		}

		used = guess;

		//if (THE_WORD.find(guess) != std::string::npos)
		if (IsGuessed(THE_WORD, guess))
		{
			std::cout << "That's right! " << guess << " is in the word.\n";

			// update soFar to include newly guessed letter
			for (unsigned int i = 0u; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			std::cout << "Sorry, " << guess << " isn't in the word.\n";
			++wrong;
		}
	}

	// shut down
	if (wrong == MAX_WRONG)
	{
		std::cout << "\nYou've been hanged!";
	}
	else
	{
		std::cout << "\nYou guessed it!";
	}

	std::cout << "\nThe word was " << THE_WORD << std::endl;

	return 0;

}

char PlayerGuess()
{
	char guess;
	std::cout << "\n\nEnter your guess: ";
	std::cin >> guess;
	guess = toupper(guess);					// make uppercase since secret word is in uppercase

	return guess;
}

bool IsGuessed(const std::string THE_WORD, char guess)
{
	if(THE_WORD.find(guess) != std::string::npos)
		return true;
	else
		return false;
}