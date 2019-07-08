class ListNode
{
private:
	void* m_Data = nullptr;
	ListNode* m_Last = nullptr;
	ListNode* m_Next = nullptr;

public:
	ListNode(void* data)
		: m_Data(data)
	{}

	void* GetData()
	{
		return m_Data;
	}

	void SetLast(ListNode* last)
	{
		m_Last = last;
	}

	ListNode* GetNode()

	{
		return m_Last;
	}

	void SetNext(ListNode* next)
	{
		m_Next = next;
	}

	ListNode* GetNext()
	{
		return m_Next;
	}
};