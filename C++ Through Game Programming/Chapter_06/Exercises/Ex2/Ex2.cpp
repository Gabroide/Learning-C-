// Exercise 2
// Wrong code

//int main()
//{
//	int score;
//	score = 1000;
//	float& rScore = score;
//
//	return 0;
//}

// The above code is bad because we are initializing a float reference with a int variable, Below it is the right code
int main()
{
	int score;
	score = 1000;
	int& rScore = score;

	return 0;
}