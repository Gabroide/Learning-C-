// Array Paser
// Demostrates retionship between pointers and arrays

#include <iostream>

void increase(int* const array, const int NUM_ELEMENTS);
void display(const int* array, const int NUM_ELEMENTS);

int main()
{
	std::cout << "Creating an array of high scores.\n\n";
	const int NUM_SCORES = 3;
	int highScores[NUM_SCORES] = { 5000, 3500, 2700 };
	
	std::cout << "Displaying scores using array name as a constant pointer.\n";
	std::cout << *highScores << std::endl;
	std::cout << *(highScores + 1) << std::endl;
	std::cout << *(highScores + 2) << std::endl;
	
	std::cout << "Increasing scores by passing array as a constant pounter.\n\n";
	increase(highScores, NUM_SCORES);
	
	std::cout << "Displaying scores passing array as a constant pounter to a constant.\n";
	display(highScores, NUM_SCORES);

	return 0;
}

void increase(int* const array, const int NUM_ELEMENTS)
{
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		array[i] += 500;
	}
}

void display(const int* const array, int NUM_ELEMENTS)
{
	for (int i = 0; i < NUM_ELEMENTS; ++i)
	{
		std::cout << array[i] << std::endl;
	}
}