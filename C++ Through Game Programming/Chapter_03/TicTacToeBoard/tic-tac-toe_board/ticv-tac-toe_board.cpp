// Tic - Tac - Toe Board
// Demostrattes multidimensional arrays

#include <iostream>

int main()
{
	const int ROWS = 3;
	const int COLUMNS = 3;
	char board[ROWS][COLUMNS] = { {'O', 'X', 'O'},
								 {' ', 'X', 'X'},
								 {' X', 'O', 'O'} };

	std::cout << "Here's the tic-tac-toe board:\n";
	for (unsigned int i = 0; i < ROWS; ++i)
	{
		for (unsigned int j = 0; j < COLUMNS; ++j)
		{
			std::cout << board[i][j];
		}

		std::cout << std::endl;
	}

	std::cout << "\nX moves to the empty location.\n";
	board[1][0] = 'X';

	std::cout << "Now the tic - tac - toe borad is:\n";
	for (unsigned int i = 0; i < ROWS; ++i)
	{
		for (unsigned int j = 0; j < COLUMNS; ++j)
		{
			std::cout << board[i][j];
		}

		std::cout << std::endl;
	}

	std::cout << "\n'X' wins!";

	return 0;
}