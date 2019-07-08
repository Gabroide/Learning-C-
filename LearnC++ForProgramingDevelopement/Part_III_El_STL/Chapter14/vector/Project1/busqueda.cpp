void FindVector(MyVector myVector)
{
	for (unsigned int i = 0; i < myVector.size(); ++i)
	{
		if (myVector[i] == 2)
		{
			std::cout << "Found: " << myVector[i] << " at position: " << i << std:end;
		}
	}

	for (auto iter = myVector.begin(); iter != myVector.end(); ++i)
	{
		if (*iter == 2)
		{
			std::cout << "Found: " << *iter << std:end;
		}
	}

	for (auto& niber : myVector)
	{
		if (number == 2)
		{
			std::cout << "Found: " << number << std::endl;
		}
	}

	MyVector::iterator fpund = find(myVector.begin(), myVector.end(), 2);
	if (found != myVector.end())
	{
		std::cout << "Found: " << *found << std::endl;
	}
}