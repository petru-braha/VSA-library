#pragma once
#include "special_binary_tree.h"
#include <initializer_list>

template <class T = int>
class minheap : public special_binary_tree<T, node_bint<T>>
{
	typedef node_bint<T>* ptr;
	typedef const T& type;

	class iterator 
	{
		static size_t n;
		size_t index;
		T bfs_nodes;
	public:
		iterator(const minheap<T>& h);
		iterator(void* ptr = nullptr);
		~iterator();

		T		operator * () const;
		void	operator ++();
		bool	operator !=(const iterator& two) const;
	};

	void heapify(ptr& node);
	void arrange(ptr& node = root);
public:
	bool (*f)(type, type);
	// constructors:
	minheap(const T& value = NULL);
	minheap(const std::initializer_list<T>& val, bool (*f)(type, type) = nullptr);
	minheap(T* val, const size_t& val_size, bool (*f)(type, type) = nullptr);
	minheap(const minheap<T>& h);
	minheap(const minheap<T> && h);
	~minheap();
	
	// iterator methods:
	iterator begin() const;
	iterator end() const;

	// specific methods:
	minheap<T>& operator = (const minheap<T>& h);
	void insert(const T& value);
	void extrct(); 
	bool search(const T& value) const;

	// constant methods:
	bool operator == (const minheap<T>& h) const;
	size_t getn() const;
	void   prnt() const;
	bool  empty() const;

	// friend functions:
	friend T* convert(const minheap<T>& h);
	friend std::ostream& operator << (std::ostream& out, const minheap<T>& h);
};

template<class T>
size_t minheap<T>::iterator::n = 0;
