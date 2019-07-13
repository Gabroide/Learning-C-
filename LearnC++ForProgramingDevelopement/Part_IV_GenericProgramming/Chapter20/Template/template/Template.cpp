class Template
{
private:
	T* m_ptr;

public:
	Template(T* ptr)
		: m_ptr(ptr)
	{

	}

	int value = 1;
	Template<int> pointer(&value);
};