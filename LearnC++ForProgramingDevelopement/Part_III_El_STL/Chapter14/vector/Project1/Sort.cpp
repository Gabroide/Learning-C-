bool Descending(int first, int second)
{
	return first < second;
}

void SortVector()
{
	MyVector myVector = { 0, 1, 2, 3, 4 };

	sort(myVector.begin(), myVector.end(), Descending);
	for (auto& value : myVector)
	{
		std::cout << value << std::endl;
	}

	sort(myVector.begin(), myVector.end());
	for (auto& value : myVector)
	{
		std::cout << value << std::endl;
	}
}