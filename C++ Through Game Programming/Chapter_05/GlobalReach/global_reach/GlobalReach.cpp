// Global Reach
// Demostrates global variable

#include <iostream>

int glob = 10; // global variable

void access_global();
void hide_global();
void change_global();

int main()
{
	std::cout << "In main() glob is: " << glob << "\n\n";
	access_global();

	hide_global();
	std::cout << "In main() glob is: " << glob << "\n\n";

	change_global();
	std::cout << "In main() glob is: " << glob << "\n\n";

	return 0;
}

void access_global()
{
	std::cout << "In access_global() glob is: " << glob << "\n\n";
}

void hide_global()
{
	int glob = 0; //  hide global variable glob
	std::cout << "In hide_global() glob is: " << glob << "\n\n";
}

void change_global()
{
	glob = -10; // change global variable glob
	std::cout << "In access_global() glob is: " << glob << "\n\n";
}