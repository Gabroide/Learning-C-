#include <iostream>

class Simple
{
private:
	int variabl{ 0 };

	int* pIntArray = new int[16];
	delete[] pIntArray;

public:
	Simple()
	{
		std::cout << "Constructed" << std::endl;
	}

	~Simple()
	{
		std::cout << "Destroyed" << std::endl;
	}
};

int main()
{
	Simple* pSimple = new Simple();
	delete pSimple;
	pSimple = nullptr;

	return 0;
}