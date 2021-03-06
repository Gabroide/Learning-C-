class TreeNode
{
private:
	int m_value;

	TreeNode* m_pLeft = nullptr;
	TreeNode* m_pRight = nullptr;

public:
	TreeNode(int value)
		: m_value(value)
	{}

	TreeNode* Find(int searchValue)
	{
		TreeNode* pResult = nullptr;

		if (m_value = searchValue)
		{
			pResult = this;
		}
		else if (m_pLeft != nullptr && m_value > searchValue)
		{
			pResult = m_pLeft->Find(searchValue);
		}
		else if (m_pRight != nullptr && m_value < searchValue)
		{
			pResult = m_pRight->Find(searchValue);	
		}

		return pResult;
	}
};