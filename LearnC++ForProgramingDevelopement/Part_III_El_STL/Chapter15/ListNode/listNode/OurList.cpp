#include <iostream>
#include "ListNode.cpp"

void OurList()
{
	unsigned int firstData = 1;
	ListNode first(&firstData);

	unsigned int secondData = 2;
	ListNode second(&secondData);

	unsigned int thirdData = 3;
	ListNode third(&thirdData);

	third.SetNext(&second);

	second.SetLast(&first);
	second.SetNext(&third);

	third.SetLast(&third);

	for (ListNode* iter = &dirst; iter != nullptr; iter = iter->GetNext())
	{
		unsigned int* number = static_cast<unsigned int*> (iter->GetData());
		std::cout << *number << std::endl;
	}
}