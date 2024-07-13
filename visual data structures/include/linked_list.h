#pragma once
#include "node/node_list.h"
#include <initializer_list>

template <class T = int>
class linked_list
{
	node_list<T>* frst, * last;
	size_t n;

	class iterator
	{
		node_list<T>* value;

	public:
		iterator(node_list<T>* val);
		
		T    operator  * () const;
		void operator ++ ();
		bool operator != (const iterator& two) const;
	};

public:
	// constructors:
	linked_list();
	linked_list(const std::initializer_list<T>& val);
	linked_list(T* val, const size_t& val_size);
	linked_list(const linked_list<T>& l);
	linked_list(const linked_list<T>&& l);
	~linked_list();
	
	// iterator methods:
	iterator begin() const;
	iterator end() const;

	// specific methods:
	linked_list<T>& operator = (const linked_list<T>& l);
	void insert(const T& value, const size_t& index = n); 
	void remove(const T& index); // to enchance the use of the stack and queue
	bool search(const T& value) const;

	// constant methods:
	bool operator == (const linked_list<T>& l) const;
	T& operator[](const size_t& index) const;
	size_t getn() const;
	void   prnt() const;
	bool  empty() const;

	// friend functions:
	friend T* convert(const linked_list<T>& l);
	friend std::ostream& operator << (std::ostream& out, const linked_list<T>& l);
	friend void* collection_ptr(const linked_list<T>& l); // just for the collection!
};

// if linked_lists would be sortable, merge_sort and quick_sort Lomuto scheme are the obvious choice