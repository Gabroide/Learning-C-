#pragma once

class Event;

class EventHandler
{
public:
	virtual void HanleEvent(const Event* pEvent) = 0;
};