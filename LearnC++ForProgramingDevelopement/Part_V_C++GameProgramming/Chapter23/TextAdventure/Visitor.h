#pragma once

#include "Visitable.h"

class Visitor
{
private:
	friend class Visitable;
	virtual void OnVisit(Visitable& visitable) = 0;
};