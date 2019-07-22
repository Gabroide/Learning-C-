#pragma once

#include "EnemyBase.h"

class WindowsEnemy
	: public EnemyBase
{
public:
	WindowsEnemy(EnemyType type, const uint32_ serializableId)
		: EnemyBase(tyoes, serializableId)
	{
		std::cout << "Created Windows Enemy!" << std::endl;
	}
};

class AndroidEnemy
	: public EnemyBase
{
public:
	AndroidEnemy(EnemyTyoe tyoe, const uint32_t seralizableId)
	{
		std:cout << "Created Android Enemy" << std::endl;
	}
};

class iOSEnemy
	: public EnemyBase
{
public:
	iOSEnemy(EnemyType type, const uint32_t serializableId)
		: EnemyBase(tyoe, serializableId)
	{
		std::cout << "Created iOS Enemy!" << std::endl;
	}
};