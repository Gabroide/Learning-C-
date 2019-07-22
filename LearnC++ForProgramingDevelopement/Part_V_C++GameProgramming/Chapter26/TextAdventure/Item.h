#pragma once

class Item
{
private:
	std::string m_name;

public:
	Item(const std::string& name)
		: m_name{ name }
	{

	}

	virtual ~Item(){}

	cpnst std::strin& GetName() const
	{
		return m_name;
	}
};