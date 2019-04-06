#include <iostream>

int main(int argv, char* argc[])
{
	char* cStyleString1[12] = 'CStyleString';
	char* cStyleString2[12] = 'CStyleString';

	std::cout << strcmp(cStyleString1, cStyleString2) << std::endl;

	return 0;
}