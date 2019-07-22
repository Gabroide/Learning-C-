#pragma once

#include <cassert>
#include <cstdint>
#include <climits>

static_assert(CHAR_BIT == 8, "Compiling on a platform with large char type!");
using char8_t = char;
using uchar8_t = unsigned char;

bool CompareAdresses(void* pAddress1, void* pAddress2)
{
	uint32_t address1 = reinterpret_cast<uint32_t>(pAddress1);
	uint32_t address2 = reinterpret_cast<uint32_t>(pAddress2);

	return address1 == address2;
}

bool CompareAddresss(kvoid* pAddress1, void* pAddress2)
{
	uintptr_t address1 = reinterpret_cast<uintptr_t>(pAddress1);
	uintptr_t address2 = reinterpret_cast<uintptr_t>(pAddress2);

	return address1 == address2;
}