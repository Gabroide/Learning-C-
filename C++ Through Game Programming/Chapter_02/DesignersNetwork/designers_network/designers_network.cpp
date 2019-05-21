// Designers Network
// Demostrates logical operators

#include <iostream>
#include <string>

int main()
{
	std::string username;
	std::string password;
	bool success;

	std::cout << "\tGame Designer's Network\n";

	do
	{
		std::cout << "\nUsername: ";
		std::cin >> username;
		std::cout << "Password: ";
		std::cin >> password;

		if (username == "S.Meier" && password == "civilization")
		{
			std::cout << "\nHey, Sid.";
			success = true;
		}
		else if (username == "S.Miyamoto" && password == "mariobros")
		{
			std::cout << "\What's up Shigeru?";
			success = true;
		}
		else if (username == "W.Wright" && password == "thesims")
		{
			std::cout << "\nHow goes it, Will?";
			success = true;
		}
		else if (username == "guest" || password == "guest")
		{
			std::cout << "\nWelcome, guest.";
			success = true;
		}
		else
		{
			std::cout << "\nYour login failed.\n";
			success = false;
		}
	} while (!success);

	return 0;
}