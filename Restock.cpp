
#include "Restock.h"

bool Restock::restock_function(ListBase<Product>* List,int index, int quantity){
	//clock_t startTime = clock(); //Do this right before invoking the function
	Product *Item;

	bool success; //Checks if item can be found
	Item = List->retrieveItem(index);

	if(Item != NULL){
		Item->set_stock(Item->get_stock()+quantity);
		success = true;
	}else{
		success=false;
	}

	

	//clock_t endTime = clock();  //Do this right after the function returns
	//cout<<"Elapsed time:";
	//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;

	return success;
}



/*bool Restock::restockAll(ListBase* List,int num){
ListBase<Product>* curr = head; //point curr to first prod in the list
if(curr = NULL)
	return false; //the inventory is empty so return false.
while (curr!= NULL){
		curr->set_stock(0); //accessing the set_sale function.
curr = curr->next; //traverse to next one if needed
}
return true;//Linked list linking & deletion

}*/
