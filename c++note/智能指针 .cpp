//unique_ptr
template<class T>
class UniquePtr
{
private:
	T* _ptr;
public:
	UniquePtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~UniquePtr()
	{
		if (_ptr)
			delete _ptr;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	UniquePtr(UniquePtr<T>&) = delete;
	UniquePtr<T>& operator=(UniquePtr<T>&) = delete;
};


//shared_ptr
template<class T>
class SharedPtr
{
private:
	T* _ptr;
	int* _count;
private:
	void Release()
	{
		if (_ptr && ((*_count--) == 0))
		{
			delete _ptr;
			delete _count;
		}
	}
	void AddCount(SharedPtr<T>& sp)
	{
		_ptr = sp._ptr;
		_count = sp._count;
		if (_ptr)
			(*_count)++;
	}
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		, _count(nullptr)
	{
		if (_ptr)
			_count = new int(1);
	}
	SharedPtr(SharedPtr<T>& sp)
	{
		AddCount(sp);
	}
	SharedPtr<T>& operator=(SharedPtr<T>& sp)
	{
		if (this != &sp)
		//优化：if(_ptr != sp._ptr)
		{
			Release();
			AddCount(sp);
		}
		return *this;
	}
	~SharedPtr()
	{
		Release();
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	int Use_count()
	{
		return *_count;
	}
};


//循环引用实例：
struct ListNode
{
	int _data;
	SharedPtr<ListNode> _prev;
	SharedPtr<ListNode> _next;
	
	~ListNode()
	{
		cout<<"~ListNode()"<<endl;
	}
};
int main()
{
	SharedPtr<ListNode> node1(new ListNode);
	SharedPtr<ListNode> node2(new ListNode);
	cout << node1.Use_count() << endl;
	cout << node2.Use_count() << endl;
	node1->_next = node2;
	node2->_prev = node1;
	cout << node1.Use_count() << endl;
	cout << node2.Use_count() << endl;
	
	return 0;
}
//运行结果：
1
1
2
2
