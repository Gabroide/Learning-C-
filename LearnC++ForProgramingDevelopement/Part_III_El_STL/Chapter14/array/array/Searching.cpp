using MyArray = std::array<int, ARRAY_SIZE>;
void FindInArray(MyArray myArray)
{
	for (unsigned int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (myArray[i] == 2)
		{
			std::cout << "Found: " << myArray[i] << " at position: " << i << std::endl;
		}
	}

	for (auto iter = myArray.begint(); iter != myArray.end(); ++iter)
	{
		if (*iter == 2)
		{
			std::cout << "Found: " << *iter << std::endl;
		}
	}

	for (auto& number : myArray)
	{
		if (number == 2)
		{
			std::cout << "Found: " << number << std:endl;
		}
	}

	MyArray::iterator found = find(myArray.begin(), myArray.end(), 2);
	if (found != myArray.end())
	{
		std::cout << "Found: " << *found << std::endl;
	}
}