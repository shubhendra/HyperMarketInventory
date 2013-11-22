#include"User.h"
User::User(){}
User::User(string Name)
{
	_name=Name;
}
void User::addJobs(ifstream* readFile)
{
	string DUMMY;
	
	*readFile>>no_of_jobs;
	for(int j=0; j<no_of_jobs; j++)
	{
		//Jobs _temp;
		
		string code;
		string DUMMY;
		*readFile>>code;
		getline(*readFile,DUMMY);
		Jobs& _temp = Jobs(code);
		_temp.readjobDetails(readFile);
		Jobs_Queue.enqueue(_temp);
		
	}
}
void User::execJobs(ListBase<Product>* List)
{
	vector<string> errMsgs;
	
	for (int i=0;i<no_of_jobs;i++)
	{
		Jobs temp;
		Jobs_Queue.dequeue(temp);
		if(!temp.job_exec(List))
		{
			errMsgs.push_back(temp.retrieveErrorMsgs());
		}
	}
	userLog(errMsgs);	
}

string User::getUser()
{
	return _name;
}

int User::getNumJobs()
{
	return no_of_jobs;
}

void User::userLog(vector<string> errMsgs)
{
	ofstream writeError("log.txt",ios::app);
	for(unsigned int i=0;i<errMsgs.size();i++)
	{
		writeError<<errMsgs[i]<<_name<<endl;
	}
	writeError.close();
}