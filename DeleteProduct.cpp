#include <string>
#include <sstream>
#include <ctime>
#include "ListBase.h"
#include "Product.h"
#include "PerishableProduct.h"
#include "DeleteProduct.h"

bool DeleteProduct::delete_function(ListBase<Product>* List,int index){
	//clock_t startTime = clock(); //Do this right before invoking the function

	

	return List->removeItem(index);
	//clock_t endTime = clock();  //Do this right after the function returns
	//cout<<"Elapsed time:";
	//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
}

bool DeleteProduct::delete_function(ListBase<Product>* List, Product* Item)
{
	int index=-1;
	for(int i=0; i<List->getLength();i++)
	{
		if (List->retrieveItem(i)==Item)
		{index=i;break;}
	
	}
	if (index!=-1)
		return List->removeItem(index);
	else
		return false;

}
