#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include"QueueBase.h"
using namespace std;
template <typename T>
class Queue:public QueueBase<T> {
private:
	
	vector<T> STK;
public:
	Queue():QueueBase() {}


	bool enqueue(const T& newitem){
		STK.push_back(newitem);
		_size++;
		return true;
	}

	bool dequeue(T& item){
		if(STK.empty())
			return false;
		item = STK.front();
		STK.erase(STK.begin());
		_size--;
		return true;
	}

	bool getFront(T& queueFront)
	{
		if (STK.empty())
			return false;
		queueFront= STK.front();
		return true;
}
	~Queue(){
		while(!STK.empty())
			STK.pop_back();
	}

};

#endif