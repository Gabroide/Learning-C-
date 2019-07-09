using MyMap = std::map<int, string>;
using MyPair = std::pair<int, string>;

MyMap myMap = { {2, "Two"}, {1, "One"}, {0, "Zero"} };

MyPair node{ 4, "Four" };
myMap.insert(node);

myMap.emplace(3, "Three");

for (const auto& node : myMap)
{
	std::cout << "First: " << node.first << "Second: " << node.Second << std..endl;
}

MyMap::iterator found = myMap.find(2);

if (found != myMap.end())
{
	std::cout << "Found First: " << found->first << " Second: " << found->second << std::endl;
}