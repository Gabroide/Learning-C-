#include <iostream>

struct SumParameters
{
	int		valueA;
	int		valueB;
	int		result;
};

void ReturnSum (SumParameters& params)
{
	params.result = params.valueA + params.valueB;
}

int main(int argc, char** argv[])
{
	SumParameters sum;
	sum.valueA = 3;
	sum.valueB = 6;
	sum.result = 0;

	ReturnSum(sum);

	std::cout << sum.result << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Enter a 0 to finish the program" << std::endl;
	int number;
	std::cin >> number;

	return 0;
}