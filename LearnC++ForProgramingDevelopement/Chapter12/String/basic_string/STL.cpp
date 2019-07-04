void StringIterators()
{
	using myString{ "This is my string!" };
	for (std::string::iterator iter = myString.bego(); iter != myStrin.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	for (std::string::iterator iter = myString.end() - 1; iter != myString.begin(); --iter)
	{
		std::cout << *iter << std::endl;
	}

	for (std::string::reverse_iterator iter = myString.rbegin(); iter != myString.rend(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	for (std::string::iterator iter = myString.begin(); iter != myString.end(); ++iter)
	{
		*iter = 'a';
		std::coout << *iter << std::endl;
	}

	for (char &letter : myString)
	{
		std::cout << letter << std::endl;
	}

	for (const char &letter : myString)
	{
		std::cout << letter << std::endl;
	}

	for (auto char &letter : myString)
	{
		letter = 'a';
		std::cout << letter << std::endl;
	}

	for (const auto char &letter : myString)
	{
		std::cout << letter << std::endl;
	}

	for (auto iter = myString.begin(); iter != myString.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	for (auto iter = myString.cbegin(); iter != myString.cend(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

std::string myString{ "This is my string!" };

void FindString(std::string myString)
{
	size_t found = myString.find("is");
	if (found != std::string::npos)
	{
		std::cout << "\" is\" found at position:: " << found << std::endl;
	}

	found = myString.find("is", found + 1);
	if (found != std::string::npos)
	{
		std::cout << "is found at position: " << found << std::endl;
	}

	found = myStrig.find_first_of("msg");
	if (found != std::string::npos)
	{
		std::cout << "is found at position: " << found << std::endl;
	}
}

