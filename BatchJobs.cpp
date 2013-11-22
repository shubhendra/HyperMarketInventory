#include<iostream>
#include "BatchJobs.h"
#include<string>
using namespace std;
BatchJobs::BatchJobs(){}
bool BatchJobs::addUsers()
{
	string DUMMY;
	string name;
	//User* tempUser;
	readFile = new ifstream("batchjobs.txt");
	*readFile>>_size;
	
	getline(*readFile,DUMMY);
	for (int i =0;i<_size;i++)
	{
		getline(*readFile,name);
		User& tempUser=User(name);
		tempUser.addJobs(readFile);
		userStack.push(tempUser);
	}
	readFile->close();
	delete readFile;
	return true;
}
bool BatchJobs::startProcess(ListBase<Product>* List)
{
	
	int i;
	for (i=0;i<_size;i++)
	{
		User cur;
		userStack.pop(cur);
		cur.execJobs(List);
	}
	return true;
}
BatchJobs::~BatchJobs()
{
}