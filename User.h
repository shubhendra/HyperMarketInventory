#ifndef __USER_H__
#define __USER_H__
#include<iostream>
#include<fstream>
#include<string>
#include"Jobs.h"
using namespace std;
class User{
private:
	string _name;
	int no_of_jobs;
	Queue<Jobs> Jobs_Queue;
public:
	User();
	User(string name);
	void addJobs(ifstream* readFile);
	void execJobs(ListBase<Product> * List);
	void userLog(vector<string> errMsgs);
	string getUser();
	int getNumJobs();

};
#endif