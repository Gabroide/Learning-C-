// Excercise 3
// Wrong code
const int ROWS = 2;
const int COLUMNS = 3;
char board[COLUMNS][ROWS] = {{'O', 'X', 'O'},
							 {' ', 'X', 'X'}};

// The problem un the previous code is that the dimension of the array is wrong. To correct it the order declaring the array should be changed.
// Above you can see the correct code.

const int ROWS = 2;
const int COLUMNS = 3;
char board[ROWS][COLUMNS] = { {'O', 'X', 'O'},
							  {' ', 'X', 'X'} };