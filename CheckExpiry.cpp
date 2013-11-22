#include <string>
#include <sstream>
#include <ctime>
#include "CheckExpiry.h"
#include "ListBase.h"
#include "PerishableProduct.h"
#include <ctime>


string CheckExpiry::checkExpiry_function(ListBase<Product>* List, int index, int& flag){
	//clock_t startTime = clock(); //Do this right before invoking the function
	PerishableProduct* Item;
	
	//bool success; //Checks if item can be located


	Item = dynamic_cast<PerishableProduct*>(List->retrieveItem(index));
	//cout<<typeid(List->retrieveItem(index)).name();
	//Product *item2=dynamic_cast<Product*>(List->retrieveItem(index));
	//cout<<typeid(Item).name();
	//cout<<typeid(item2).name();
	if(Item != NULL){
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	string exp= Item->get_expiry(); //If successful, a string containing the expiry date
	struct tm *timeval;
	time_t tt;
	tt = time( NULL );
	
	timeval =localtime( &tt );
	int local_m=timeval->tm_mon+1;
	int local_d=timeval->tm_mday;
	int local_y=1900+timeval->tm_year;
	int exp_m=atoi(exp.substr(2,2).c_str());
	int exp_d=atoi(exp.substr(0,2).c_str());
	int exp_y=atoi(exp.substr(4,4).c_str());

	flag= 1;
	if (exp_y<local_y) //Check year
		flag=0;
	else if(exp_y == local_y){//Exp yr matches this yr
		
		if (exp_m==local_m){ //check month for match
			if (exp_d<local_d)//chk day
				flag=0; 
			else
				flag=1;
		} 
		else if(exp_m<local_m)
			flag=0;
		else
			flag=1;
	}
	else{
		flag = 1;
	}

	
	return Item->get_expiry();
// print zero based day of week
	
	}else{
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		flag=-1;
		return "Not Applicable";
	}


}


int CheckExpiry::check_manual(ListBase<Product>* List, int index, string current)
{
		PerishableProduct* Item;
	
	//bool success; //Checks if item can be located
		int flag;

	Item = dynamic_cast<PerishableProduct*>(List->retrieveItem(index));
	
	if(Item != NULL){
		
	string exp= Item->get_expiry(); //If successful, a string containing the expiry date

	int local_m=atoi(current.substr(2,2).c_str());
	int local_d=atoi(current.substr(0,2).c_str());
	int local_y=atoi(current.substr(4,4).c_str());
	int exp_m=atoi(exp.substr(2,2).c_str());
	int exp_d=atoi(exp.substr(0,2).c_str());
	int exp_y=atoi(exp.substr(4,4).c_str());

	flag= 1;
	if (exp_y<local_y) //Check year
		flag=0;
	else if(exp_y == local_y){//Exp yr matches this yr
		
		if (exp_m==local_m){ //check month for match
			if (exp_d<local_d)//chk day
				flag=0; 
			else
				flag=1;
		} 
		else if(exp_m<local_m)
			flag=0;
		else
			flag=1;
	}
	else{
		flag = 1;
	}


// print zero based day of week
	
	}else{
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		flag= -1;
		
	}
	return flag;

}
	
