#ifndef STACK_H
#define STACK_H
#include"StackBase.h"
#include <vector>
using namespace std;
template <typename T>

class Stack:public StackBase<T>{
private:
	
	vector<T> STACKVEC;
	//T stackTop;
public:
	Stack():StackBase()
	{
		
	}

	//bool isEmpty(){
		//return STACKVEC.empty();
	//}

//	int get_size(){
	//	return STACKVEC.size();
	//}

	bool push(const T& newitem){
		STACKVEC.push_back(newitem);
		_size++;
		return true;
	}

	bool pop(T& item){
		if(STACKVEC.empty())
			return false;
		item =STACKVEC.back();
		STACKVEC.pop_back();
		_size--;
		return true;
	}

	bool getTop( T& stackTop )
	{
		if(STACKVEC.empty())
			return false;
		stackTop=STACKVEC.back();
		return true;
	}
		
	~Stack(){
		while(!STACKVEC.empty())
			STACKVEC.pop_back();
	}

};

#endif