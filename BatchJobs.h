#ifndef __BATCHJOBS_H__
#define __BATCHJOBS_H__
#include"API.h"
#include"Queue.h"
#include"Stack.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Product.h"
#include"PerishableProduct.h"
using namespace std;
#include"Jobs.h"
#include"User.h"
class BatchJobs{
private:
	ifstream* readFile;
	int _size;
	Stack<User> userStack;
public:
	BatchJobs();
	bool addUsers();
	bool startProcess(ListBase<Product> *List);
	~BatchJobs();
};
#endif