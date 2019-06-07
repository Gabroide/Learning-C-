// Exercise 3
int& threeMore(int number);

int main()
{
	int num = threeMore(5);

	return 0;
}

// Wrong function
//int& threeMore(int number)
//{
//	int threeMore = number + 3;
//
//	return threeMore;
//}

// The problem with the function is that the function and the variable have the same name and it can confuse other programmes.
// Below it can be observed the correct function.

int& threeMore(int number)
{
	int addThree = number + 3;

	return addThree;
}