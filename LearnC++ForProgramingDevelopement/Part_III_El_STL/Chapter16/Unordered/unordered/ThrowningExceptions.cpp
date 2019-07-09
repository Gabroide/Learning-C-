void ExceptionExample()
{
	if (true)
	{
		throw - 1;
	}
}

try
{
	ExceptionExample();
}
catch (int errorValue)
{
	std::cout << "Error: " << errorValue << std::endl;
}