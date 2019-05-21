#ifndef __Player_h__
#define __Player_h__

#include <string>

class Player
{
public:
	void SetName(const std::string& name)
	{
		m_name = name;
	}

	const std::string& GetName() const
	{
		return m_name;
	}

private:
	std::string m_name;
};

#endif // __Player_h__
