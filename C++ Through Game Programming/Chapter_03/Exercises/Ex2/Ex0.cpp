// Ex2
// Wrong loop

#include <iostream>
#include <string>

int main()
{
	std::string phrase = "Game Over!";

	for (int i = 0; i <= phrase.size(); ++i)
	{
		std::cout << "Character position " << i << " is: " << phrase[i] << std::endl;
	}

	// The previous code is wrong because when we are programming the first position value is a 0; so we will start counting in 0. To avoid this problem and 
	// assign to each letter its correct position we have to add 1 for i.
	// Also to avoid appearing the end of array simbol we have to rest 1 to phrase.size() in the loop.
	// Above lines it is showed the correct code.

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i <= (phrase.size()-1); ++i)
	{
		std::cout << "Character position " << (i + 1) << " is: " << phrase[i] << std::endl;
	}
}