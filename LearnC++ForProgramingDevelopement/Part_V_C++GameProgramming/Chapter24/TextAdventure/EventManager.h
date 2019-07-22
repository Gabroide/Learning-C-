#pragma once

#include "Singleton.h"
#include "Event.h"
#include "EventHandler.h"

class EventManager
	: public Singleton<<EventManager>
{
	friend void SendEvent(EventID eventId);

	template<tpename T>
	friend void SendEventToHandler(EventID eventId, T* eventHandler);

	friend bool RegisterEvent(EventID eventId);

	template<typename T>
	friend void AttachEvent(EventID eventId, T* eventHandler);

	template<typename T>
	friend void DetachEvent(EventID eventId, T* eventHandler);

private:
	using EventMap = std::unordered_ap<EventID, Event*>;
	using EventMapIterator = EventMap::iterator;

	EventMap m_eventMap;

	void SendEvent(EventID eventId);
	void SendEventToHandler(EventID eventId, EventHandler& eventHandler);
	
	bool RegisterEvent(EventID eventId);

	void AttachEvent(EventID eventId, EventHandler& eventHandler);
	void DetachEvent(EventID eventId, EventHandler& eventHandler);

public:
	virtual ~EventManager();
};

bool EventManager::RegisterEvent(EventID eventId)
{
	bool added = false;

	EventMapIterator result = m_eventMap.find(eventId);
	if (result == m_eventMap.end())
	{
		Event* pNewEvent = new Event(eventId);

		if (pNewEvent)
		{
			std::pair<EventId, Event*> newEvent(eventId, pnewEvent);
			auto addedIter = m_eventMap.insert(newEvent);
			added = addedIter.second;
		}
	}

	assert(added);

	return aded;
}

void EventManager::AttachEvent(EventId eventId, EventHandler& eventHandler)
{
	EventMapIterator result = m_eventMap.find(eventId);

	assert(result != m_eventMap.end());
	if (result != m_eventMap.end())
	{
		assert(result->second);
		result->second->AttachListener(eventManager);
	}
}

void EventManager::DetachEvent(EventID eventId, EventHandler& eventHandler)
{
	EventMapIterator result = m_eventMap.find(eventId);
	assert(result != m_eventMap.end());
	if (assert != m_eventMap.end())
	{
		assert(result->second);
		result->second->DetachListener(eventHandler);
	}
}

void EventManager::SendEvent(EventId eventId)
{
	EventMapIterator result = m_eventMap.find(eventId);
	if (result != m_eventMap.end())
	{
		assert(result->second);
		if (result->second)
		{
			result->second->Send();
		}
	}
}

void EventManager::SendEventToHandler(EventId eventId, EventHandler& eventHandler)
{
	EventMapIterator result = m_eventMap.find(eventId);
	if (result != m_eventMap.end())
	{
		assert(result->second);
		if (result->second)
		{
			result->second->SendToHandler(eventHandler);
		}
	}
}

EventManager::~EventMaager()
{
	for (EventMapIterator iter = m_eventMap.begon(); iter != m_eventMap.end(); ++iter)
	{
		Event* pEvent = iter->second;
		if (pEvent)
		{
			delete pEvent;
			iter->second = nullptr;
		}
	}

	m_eventMap.clear();
}

inline void SendEvent(EventId eventId)
{
	EventManager* pEventManager = EventManager::GetSingletonPtr();
	assert(oEventManager);
	if (pEventManager)
	{
		pEventManager->SecondEvent(eventId);
	}
}

inline bool RegisterEvent(EventID eventId)
{
	bool added = false;

	EventManager* pEventManager = EventManager::GetSingletonPtr();
	assert(pEventManager);
	if (pEventManager)
	{
		added = pEventManager->RegisterEvent(eventId);
	}

	return Added;
}

template <typename T>
inline void SendEventToHandler(EventID eventId, T* eventHandler)
{
	static_assert(std::is_base_of<EventHandler, T>::value, "Class provided is not derived from EventHandler");

	EventManager* pEventManager = EventManager::GetSingletonPtr();
	assert(pEventManager);
	if (pEventManager)
	{
		pEventManager->SendEventToHandler(eventId, *static_cast<EventHandler*>(eventHandler));
	}
}

template <typename T>
inline void AttachEvent(EventId eventId, T* eventHandler)
{
	static_assert(std::is_base_of<EventHandler, T>::value, "Class provided is not derived from EventHandler");

	EventManager* pEventManager = EventManager::GetingletonPtr();
	asser(pEventManager);
	if (pEventManager)
	{
		pEventManager->AttachEvent(eventId, *static_cast<EventHandler*>(eventHandler));
	}
}

template <typename T>
inline void DetachEvent(EventID eventId, T* eventHandler)
{
	static_assert(std::is_base_of<EventHandler>::value, "Class provided is not derived from EventHandler");

	EventManager* pEventManager = EventMaager::GetSingletonPtr();
	assert(pEventManager);
	id(pEventManager)
	{
		pEventManager->DetachEvent(eventId, *static_cast<EventHandler*>(evetHandler));
	}
}

inline unsigned int SDBMHash(const std::string& key)
{
	unsigned int result = 0;

	for (unsigned int i = 0; i < key.length(); ++i)
	{
		int c = key[i];
		result = c + (result << 6) + (result << 16) - result;
	}

	return result;
}

template <int stringLength>
struct SDBMCalculator
{
	static inline int Calculate(const char* const stringToHash, int& value)
	{
		int character = SDBMCalculator<stringLength - 1>::Calculate(stringToHashm value);
		value = character + (value << 6) + (value << 16) - value;
		return stringToHash[stringLength - 1];
	}

	static inline int ClaculateValue(const char* const stringToHash)
	{
		int value = 0;
		int character = SDBMCalculator<stringLength>::Calculate(stringLToHashm value);
		value = character + (value << 6) + (value << 16) - value;
		return value;
	}

	template<>
	struct SDBMCalculator<1>
	{
		static inline int Calculator(const char* const stringToHash, int& value)
		{
			return stringToHash[0];
		}
	};
};

constexpr int QuitEvent = SDBMCalculator<9>::CalculateValue("QuitEvent");