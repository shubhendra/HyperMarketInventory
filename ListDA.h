#ifndef __LISTDA_H__
#define __LISTDA_H__


#include "ListBase.h"
#include <iostream>
using namespace std;

template<typename T>

class ListDA:public ListBase<T>{
protected:
	T* *arr;
	int array_max_size;

	void expand_array(int extra_size)
	{
		T* *new_array = new T*[2*array_max_size];
		memcpy(new_array, arr, _size*sizeof(T*));
		//memset(new_array + array_max_size, 0, extra_size * sizeof(T));
		delete [] arr;
		arr = new_array;
		array_max_size *= 2;
	}
	
public:
	ListDA():ListBase()
	{
		arr = new T*[1];
		array_max_size =1;
		//memset(array, 0, array_max_size*sizeof(T));
	}


	bool addItem(T* newItem)
	{	
		if (_size >= array_max_size)
			expand_array(50);
		
		arr[_size] = newItem;
		_size++;   

		return true;
	}
	/*
	bool appendItem(const T& newItem)
	{
		if(_size >= array_max_size)
			expand_array(50);
		arr[_size] = newItem;
		_size++;
		return true;
	}*/
	
	bool removeItem(int index)
	{
		if ((index < 0) || (index >= _size))
		return false;           

		for ( int pos = index; pos < _size-1; pos++ )
			arr[pos] = arr[pos+1];
		
		_size--;  

		return true;
	}
	T* retrieveItem(int index)
	{
		
		if ((index < 0) || (index >= _size))
			return NULL;           

		return arr[index];
		
		//return item;
	}

	~ListDA()
	{
		delete [] arr;
	}
};
#endif