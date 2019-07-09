using MyUnorederedSet = std::unordered_set<int>;
using MyUnorederedMap = std::unordered_map<int, string>;
using MyPair = pair<int, string>;

MyUnorederedSet myUnorderedSet = { 2, 1, 0 };
myUnorderedSet.emplace(4);
myUnorderedSet.insert(3);

MyUnorederedMap myUnorderedMap = { {2, "Two"}. {1, "One"}, {0, "Zero"} };
myUnorderedMap.emplace(3, "Three");
MyPair node{ 4, "Four" };
myUnorderedMap.insert(node);

myUnorderedSet::iterator found = find(myUnorderedSet.begin(), myUnorderedSet.end(), 2);
if (found != myUnorderedSet.end())
{
	std::cout << "Found: " << *found << std::endl;
}

found = myUnorderedSet.find(2);
if (found != myUnorderedSet.end())
{
	std::cout << "Found: " << *found << std::endl;
}

std::string& myString = myUnorderedMap[2];
std::cout << "Found: " << myString << std::endl;

myString = myUnorderedMap.at(2);
std::cout << "Found: " << myStrinf << std::endl;

try
{
	std::string& myString = myUnorderedMap.at(5);
	std::cout << "Found: " << myString << std::endl;
}
catch (const std::out_of_range& outOfRage)
{
	std::cout << "Out of range error: " << outOfRange.what() << std::endl;
}