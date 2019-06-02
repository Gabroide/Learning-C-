// Scoping
// Demostrates scopes

#include <iostream>

void func();

int main()
{
	int var = 5; // local variable in main()
	std::cout << "In main() var is: " << var << "\n\n";

	func();
	std::cout << "Back in main() var is: " << var << "\n\n";

	{
		std::cout << "in main() in new scope var is: " << var << "\n\n";
		std::cout << "Creating new var in new scope.\n";

		int var = 10; // variable in new scope, hides otre variable named var
		std::cout << "In main() in a new scope var is: " << var << "\n\n";
	}

	std::cout << "At end of main() var created in  nes scope no loger exists.\n";
	std::cout << "At end of main() var is: " << var << "\n";

	return 0;
}

void func()
{
	int var = -5; // local variable in func()
	std::cout << "In func() var is: " << var << "\n\n";
}