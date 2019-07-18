#include <iostream>

class Simple
{
private:
	int variabl{ 0 };

	int* pIntArray = new int[16];
	//delete[] pIntArray;

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

struct MemoryAllocationHeader
{
	void* pStart{ nullptr };
	void* pNextFree{ nullptr };
	size_t size{ 0 };
};

namespace
{
	const unsigned int ONE_MEGABYTE = 1024 * 1024 * 1024;
	char pMemoryHeap[ONE_MEGABYTE];
	const size_t SIZE_OF_MEMORY_HEADER = sizeof(MemoryAllocationHeader);
}

void* operator new(size_t size)
{
	MemoryAllocationHeader* pHeader = reinterpret_cast<MemoryAllocationHeader*>(pMemoryHeap);

	while (pHeader != nullptr && pHeader->pNextFree != nullptr)
	{
		pHeader = reinterpret_cast<MemoryAllocationHeader*>(pHeader->pNextFree);
	}

	pHeader->pStart = reinterpret_cast<char*>(pHeader) + SIZE_OF_MEMORY_HEADER;
	pHeader->pNextFree = reinterpret_cast<char*>(pHeader->pStart) + size;
	pHeader->size = size;

	return pHeader->pStart;
}

void operator delete(void* pMemory)
{
	MemoryAllocationHeader* pLast = nullptr;
	MemoryAllocationHeader* pCurrent = reinterpret_cast<MemoryAllocationHeader*>(pMemoryHeap);

	while (pCurrent != nullptr && pCurrent->pStart != nullptr)
	{
		pLast = pCurrent;
		pCurrent = reinterpret_cast<MemoryAllocationHeader*>(pCurrent->pNextFree);
	}

	if (pLast != nullptr)
	{
		pLast->pNextFree = reinterpret_cast<char*>(pCurrent->pNextFree);
	}

	pCurrent->pStart = nullptr;
	pCurrent->pNextFree = nullptr;
	pCurrent->size = 0;
}

void PrintAllocations()
{
	MemoryAllocationHeader* pHeader = reinterpret_cast<MemoryAllocationHeader*>(pMemoryHeap);

	while (pHeader != nullptr)
	{
		std::cout << pHeader << std::endl;
		std::cout << pHeader->pStart << std::endl;
		std::cout << pHeader->pNextFree << std::endl;
		std::cout << pHeader->size << std::endl;

		pHeader = reinterpret_cast<MemoryAllocationHeader*>(pHeader->pNextFree);

		std::cout << std::endl << std::endl;
	}
}

int main()
{
	memset(pMemoryHeap, 0, SIZE_OF_MEMORY_HEADER);

	PrintAllocations();

	Simple* pSimple1 = new Simple();

	PrintAllocations();

	Simple* pSimple2 = new Simple();

	PrintAllocations();

	Simple* pSimple3 = new Simple();

	PrintAllocations();

	delete pSimple2;
	pSimple2 = nullptr;

	PrintAllocations();

	pSimple2 = new Simple();
	
	PrintAllocations();

	delete pSimple2;
	pSimple2 = nullptr;

	PrintAllocations();

	delete pSimple3;
	pSimple3 = nullptr;

	PrintAllocations();
	
	delete pSimple1;
	pSimple1 = nullptr;

	PrintAllocations();
	
	return 0;
}