#pragma once

#include <vector>

using EventID = int;

class EventHandler;

class Event
{
private:
	using EventHandlerList = std::vector<EventHandler*>;
	using EventHandlerListIterator = EventHandlerList::iterator;

	EventHandlerList m_listeners;
	EventID m_id;

public:
	explicit Event(EventID eventID);

	void Send();
	void SendToHandler(EventHandler& eventHandler);
	void AttachListener(EventHandler& eventHandler);
	void DetachListener(EventHandler& eventHandler);

	EventID GetID() const 
	{ 
		return m_id; 
	}
};

void Event::AttachListener(EventHandler& eventHandler)
{
	m_listeners.push_back(&EventHandler);
}

void Event::DetachListener(EventHandler& eventHandler)
{
	for (EventHandlerListIterator iter = m_listeners.begin(); iter != m_listeners.end(); ++iter)
	{
		if (&eventHandler == *iter)
		{
			m_listeners.erase(iter);
			break;
		}
	}
}

void Event::Send()
{
	for (auto& listener : m_listeners)
	{
		if (listener != nullptr)
		{
			listener->HandlerEvent(this);
		}
	}
}

void Event::SendToHandler(EventHandler& eventHandler)
{
	auto found = std::find(m_listeners.begin(), m_listeners.end(), &eventHandler);
	if (found != m_listeners.end())
	{
		(*found)->HandleEvent(this);
	}
}