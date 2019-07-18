void function2(int variable1)
{
	int variable2{ variable1 };
}

void function1(int variable)
{
	function2(variable);
}

int main()
{
	int variable{ 0 };
	function1(variable);

	return 0;
}