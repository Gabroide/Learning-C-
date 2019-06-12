// Mad Lib
// Creates a story based in user input

#include <iostream>
#include <string>

std::string askText(std::string* prompt);
int askNumber(std::string* prompt);
void tellStory(std::string* name, std::string* noun, int number, std::string* bodyPart, std::string* verb);

int main()
{
	std::cout << "Welcome to Mad Lib.\n\n";
	std::cout << "Answer the following questions to help create a new story.\n\n";
	std::string nameText = "Please enter a name: ";
	std::string name = askText(&nameText);
	std::string nounText = "Please enter a plural noun: ";
	std::string noun = askText(&nounText);
	std::string numText = "Please enter a number: ";
	int number = askNumber(&numText);
	std::string bodyText = "Please enter a body part: ";
	std::string bodyPart = askText(&bodyText);
	std::string verbText = "Please enter a verb: ";
	std::string verb = askText(&verbText);

	tellStory(&name, &noun, number, &bodyPart, &verb);
}

std::string askText(std::string* prompt)
{
	std::string text;
	std::cout << *prompt;
	std::cin >> text;

	return text;
}

int askNumber(std::string* prompt)
{
	int num;
	std::cout << *prompt;
	std::cin >> num;

	return num;
}

void tellStory(std::string* name, std::string* noun, int number, std::string* bodyPart, std::string* verb)
{
	std::cout << "\nHere's your story:\n";
	std::cout << "The famous explorer ";
	std::cout << *name;
	std::cout << " had nearly given up a life-long quest to find\n";
	std::cout << "The Lost City of ";
	std::cout << *noun;
	std::cout << " when one day, the ";
	std::cout << *noun;
	std::cout << " found the explorer.\n";
	std::cout << "Surronded by ";
	std::cout << number;
	std::cout << " " << noun;
	std::cout << ", a tear come to ";
	std::cout << *name << "'s ";
	std::cout << *bodyPart << ".\n";
	std::cout << "After all this time, the qyest was finally over.";
	std::cout << *noun << "\n";
	std::cout << "promptly devoured";
	std::cout << *name << ". ";
	std::cout << "The moral of the story? Be careful what you ";
	std::cout << *verb;
	std::cout << " for.";
}