#pragma once

class Visitable
{
public:
	virtual ~Visitable();

	void Visit(Visitor& visitor)
	{
		visitor.OnVisit(*this);
	}
};