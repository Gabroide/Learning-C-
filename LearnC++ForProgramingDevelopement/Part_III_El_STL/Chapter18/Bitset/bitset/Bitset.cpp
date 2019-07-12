#include <bitset>

namespace
{
	const unsigned int NUMBER_OF_BITS = 5;
}

using MyBitset = std::bitset<NUMBER_OF_BITS>;

MyBitset defaultConstructor;
MyBitset unsignedLongConstructor{ 0x17 };
MyBitset stringConstructor{ string{"11011"} };

std::cout << boolalpha;

std::cout << "Size of the bitset: " << stringConstructor.size() << std::endl;
std::cout << "Number of set bits: " << stringConstructor.count() << std::endl;

std::cout << "Is any bit set? " << stringConstructor.any() << std::endl;
std::cout << "Are all bit set? " << stringConstructor.all() << std::endl;
std::cout << "Are no bit set? " << stringConstructor.none() << std::endl;

for (unsigned int i = 0; i < stringConstructor.size(); ++i)
{
	std::cout << "Bit " << i << " value: " << stringConstructor[i] << std::endl;
	std::cout << "Bit " << i << " test: " << stringConstructor.test(i) << std::endl;

	stringConstructor.set(1, false);
	stringConstructor.set(1);
	stringConstructor();

	stringConstructor.reset(0);
	stringConstructor.reset();

	stringConstructor.flip(4);
	stringConstructor.flip();
}