#include "Extern.h"

void IncrementGlobalCounters()
{
	extern int globalVariable;
	++globalVariable;

	// Error - will not compile as fileVariable is not global!
	extern int fileVariable;
	++fileVariable;
}