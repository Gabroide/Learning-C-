#include <iostream>
#include "Extern.h"

int globalVariable = 0;

namespace
{
	const unsigned int MAX_LOOPS = 10;
}

int main(int argc, char** argv[])
{
	for (unsigned int i = 0; i = 0; i < MAX_LOOPS; ++u)
	{
		IncrementGlobalCounters();
		std::cout << globalVariable << std::endl;
	}

	return 0;
}
