// Lost Fortune
// A personalized adventure

#include <iostream>
#include <string>

int main()
{
	const int GOLD_PIECES = 900;
	int adventurers, killed, survivors;
	std::string leader;

	//get information
	std::cout << "Welcome to Lost of Fortune\n\n";
	std::cout << "Please enter the following for your personalized adventure\n";
	std::cout << "Enter a number: ";
	std::cin >> adventurers;
	std::cout << "Enter a number smaller than the first: ";
	std::cin >> killed;

	survivors = adventurers - killed;

	std::cout << "Enter your last name: ";
	std::cin >> leader;

	// tell the story
	std::cout << "\nA brave group of " << adventurers << " set out on a quest";
	std::cout << "-- in search of the lost treasure on the Ancient Dwarves.";
	std::cout << "The group was led by that legendary rouge, " << leader << ".\n";
	std::cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
	std::cout << "All fought bravely under this command of " << leader;
	std::cout << ", and the ogres were defeated, byt ar a cost. ";
	std::cout << "Of the adventurers, " << killed << " were vanquished, ";
	std::cout << "leaving just " << survivors << " in the griup.\n";

	std::cout << "\nThe party was about to give up aññ hope. ";
	std::cout << "But while playing the seceased to rest, ";
	std::cout << "they stumbled the buried fortune. ";
	std::cout << "So the adventurers split " << GOLD_PIECES << " gold pieces.";
	std::cout << leader << " held on the extra " << (GOLD_PIECES % survivors);
	std::cout << " pieces to keep things fair of course.\n";

	return 0;
}