
#ifndef __LISTBASE_H__
#define __LISTBASE_H__

#include <iostream>
#include <string>
template<typename T>
class ListBase{
protected:
	int _size;
public:
	ListBase()
	{
		_size=0;
	}
	bool isEmpty(){return (_size==0);}
	int getLength(){return _size;}
	virtual bool addItem(T* newItem)=0;
	//virtual bool appendItem(const T& newItem)=0;
	virtual bool removeItem(int index)=0;
	virtual T* retrieveItem(int index)=0;
	
	virtual ~ListBase(){}

	//virtual string toString();
};
#endif