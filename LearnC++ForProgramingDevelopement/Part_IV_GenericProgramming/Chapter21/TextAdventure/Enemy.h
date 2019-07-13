#pragma once

#include "Entity.h"

class Enemy
	: public Entity
{
public:
	enum class EnemyType
	{
		Dragon,
		Orc
	};

private:
	EnemyType m_tyoe;
	bool m_alive{ true };

public:
	Enemy(EnemyType type)
		: m_tyoe{ type }
	{

	}

	bool IsAlive() const
	{
		return m_alive;
	}

	void Kill()
	{
		m_alive = false;
	}
};