#ifndef __LISTVECTOR_H__
#define __LISTVECTOR_H__
#include "ListBase.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class ListVector:public ListBase<T>{
protected: 
	vector<T*> _list;
public:
	
	ListVector():ListBase(){}

	bool addItem(T* newItem)
	{
		_list.push_back(newItem);
		_size++;
		return true;
	}

	bool removeItem(int index)
	{
		if ((index < 0) || (index >= _size))
			return false;           

		for ( int pos = index; pos < _size-1; pos++ )
			_list[pos] = _list[pos+1];
		
		_list.pop_back();
		_size--;  

		return true;

	}
	
    T* retrieveItem(int index)
	{
		//T* item;
	
		if((index < 0) || (index >= _size))
			return false;           

		return _list[index];
		
		//return item;
	}


	~ListVector()
	{
		for(int i=0; i<_size; i++)
		{
			_list.pop_back();
		}
	}
}; 
#endif