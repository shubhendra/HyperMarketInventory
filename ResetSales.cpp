

#include "ResetSales.h"


bool ResetSales::reset_function(ListBase<Product>* List,int index){

	Product *Item;

	bool success; //bool to check if item can be found
		Item = List->retrieveItem(index);

	if(Item != NULL){
		Item->set_sale(0);
		success = true;
	}else{
		success=false;
	}


		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;

		return success;

}


	

bool ResetSales::resetAll(ListBase<Product>* List){
	//clock_t startTime = clock(); //Do this right before invoking the function
	Product *Item;
	if(List->isEmpty()){
			//clock_t endTime = clock();  //Do this right after the function returns
			//cout<<"Elapsed time:";
			//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return false;
	}

		
	for(int i=0; i < List->getLength(); i++){
			Item = List->retrieveItem(i);
			Item->set_sale(0);
			//	clock_t endTime = clock();  //Do this right after the function returns
			//	cout<<"Elapsed time:";
			//	cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
				
		
	}
		return true;
}
