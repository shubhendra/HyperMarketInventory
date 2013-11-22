
#include "Sales.h"


bool Sales::sale_function(ListBase<Product>* List,int index, int  quantity){
	//clock_t startTime = clock(); //Do this right before invoking the function
	Product *Item;
	
	bool success; //Checks if item can be found
	Item = List->retrieveItem(index);

	if(Item != NULL && Item->get_stock()>quantity){
		Item->set_sale(Item->get_sale()+quantity);
		Item->set_stock(Item->get_stock()-quantity);
		success = true;
	}else{
		success=false;
	}

	//clock_t endTime = clock();  //Do this right after the function returns
	//cout<<"Elapsed time:";
	//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	
	return success;
}




