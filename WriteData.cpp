#include"WriteData.h"

bool WriteData::_write(ListBase<Product>* List)
{
	ofstream out("data.txt");
	int _numOfItems,i;
	Product* curr;
	bool isProduct,isPerishable;
	_numOfItems=List->getLength();
	out<<_numOfItems<<endl;
	for (i=0;i<_numOfItems;i++)
	{
		PerishableProduct *obj;
		curr=List->retrieveItem(i);
		obj=dynamic_cast<PerishableProduct*>(curr);
		//isPerishable=curr->isPerishable();
		if (obj!=NULL)
		{
			out<<"y"<<endl;
		}
		else
		{
			out<<"n"<<endl;
		}
		
		out<<curr->get_name()<<endl;
		out<<curr->get_category()<<endl;
		out<<curr->get_barcode()<<endl;
		out<<curr->get_price()<<endl;
		out<<curr->get_manufacturer()<<endl;
		out<<curr->get_stock()<<endl;
		out<<curr->get_sale()<<endl;
		if (obj!=NULL)
		{
			//PerishableProduct* curr1;
			//curr1=dynamic_cast<PerishableProduct*>(curr);
			out<<obj->get_expiry()<<endl;
			out<<obj->get_disc()<<endl;
		}
	}
	out.close();
	return true;
}