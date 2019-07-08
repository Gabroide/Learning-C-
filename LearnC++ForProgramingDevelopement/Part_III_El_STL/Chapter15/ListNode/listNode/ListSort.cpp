bool Descending(int first, int second)
{
	return first < second;
}

void SortList()
{
	MyList myList = { 0, 1, 2 3, 4};
	myList.sort(Descending);
	for (auto& value : myList)
	{
		std::cout << value << std::endl;
	}

	std::cout << std::endl;

	myList.sort();
	for (auto& value : myList)
	{
		std::cout << value << std::endl;
	}
}