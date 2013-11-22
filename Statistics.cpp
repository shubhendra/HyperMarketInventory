#include "Statistics.h"

void Statistics::sort(vector<Product>& ProdList, int n){
	int i,j; //Sorting algorithm according to CG1101
	Product Item;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if((ProdList[j].get_sale()*ProdList[j].get_price()) > (ProdList[i].get_sale()*ProdList[i].get_price()) ){
				Item = ProdList[i];
				ProdList[i] = ProdList[j];
				ProdList[j] = Item; 
			}
		}
	}
}

/*

code for printing the topx products but it will print only if the last product has a revenue same as the one after that.

void Statistics::sortX(ListBase<Product>* List,ListBase<Product>* List2,int x)
{
	double maxrevenue=0;
	Product* item;
	Product * curr=NULL;
	int index=-1;
	ListBase<Product>* List1=new ListVector<Product>();
	int y=x;
	//int counter_distinct_revenue=0;
//	ListBase<int>* List2;
	for(int i=0;i<List->getLength();i++)
	{
		//int* add=new int();
		//*add=*List->retrieveItem(i);
		List1->addItem(List->retrieveItem(i));
	}

	for(int j=0;j<x+1 && j<List->getLength();j++)
	{
		maxrevenue=0;
	for(int i=0;i<List1->getLength();i++)
	{
		item=List1->retrieveItem(i);
		//int j=*List1->retrieveItem(i);
		double revenue=item->get_price()*item->get_sale();
		if ((revenue)>=maxrevenue)
			{curr=item;
		index=i;
		maxrevenue=revenue;
		}
	}

	if (index!=-1){
	if (j==0 && x!=0)
	{
		List2->addItem(curr);
		//counter_distinct_revenue++;
	}
	if (j>0)
	{
		Product* Item1=curr;
		Product* Item2=List2->retrieveItem(j-1);
		double revenue1=Item1->get_sale()*Item1->get_price();
		double revenue2=Item2->get_sale()*Item2->get_price();
		if ((revenue1)==revenue2)
		{
			
		List2->addItem(curr);
			if(j==x)
				x++;

		}
		else if(j<x && j<y)
		{
			List2->addItem(curr);
			
		}

	}
	List1->removeItem(index);}
	}




}*/

void Statistics::sortX(ListBase<Product>* List,ListBase<Product>* List2,int x)
{
	double maxrevenue=0;
	Product* item;
	Product * curr=NULL;
	int index=-1;
	ListBase<Product>* List1=new ListVector<Product>();
	int y=x;
	int counter_distinct_revenue=0;
//	ListBase<int>* List2;
	for(int i=0;i<List->getLength();i++)
	{
		//int* add=new int();
		//*add=*List->retrieveItem(i);
		List1->addItem(List->retrieveItem(i));
	}

	for(int j=0;j<x+1 && j<List->getLength();j++)
	{
		maxrevenue=0;
	for(int i=0;i<List1->getLength();i++)
	{
		item=List1->retrieveItem(i);
		//int j=*List1->retrieveItem(i);
		double revenue=item->get_price()*item->get_sale();
		if ((revenue)>=maxrevenue)
			{curr=item;
		index=i;
		maxrevenue=revenue;
		}
	}

	if (index!=-1){
	if (j==0 && x!=0)
	{
		List2->addItem(curr);
		counter_distinct_revenue++;
	}
	if (j>0)
	{
		Product* Item1=curr;
		Product* Item2=List2->retrieveItem(j-1);
		double revenue1=Item1->get_sale()*Item1->get_price();
		double revenue2=Item2->get_sale()*Item2->get_price();
		if ((revenue1)==revenue2)
		{
			
		List2->addItem(curr);
			x++;

		}
		else if(j<x && counter_distinct_revenue<=y)
		{
			List2->addItem(curr);
			counter_distinct_revenue++;	
		}

	}
	List1->removeItem(index);}
	}




}


bool Statistics::topX(ListBase<Product>* List,int _num, ListBase<Product>* Result){
	if(List->isEmpty()||_num==0)
		return false;
	//ListBase<Product>* Result=new ListDA<Product>();
	sortX(List,Result,_num);
	/*
	if (Sorted->isEmpty())
		return false;
	double revenue1,revenue2;
	for(int i=0;i<_num && i<Sorted->getLength();i++)
	{
		if(i<((Sorted->getLength())-1))
		{
		revenue1=Sorted->retrieveItem(i)->get_sale()*Sorted->retrieveItem(i)->get_price();
		revenue2=Sorted->retrieveItem(i+1)->get_sale()*Sorted->retrieveItem(i+1)->get_price();
		if (revenue1==revenue2)
			_num++;}
		Result->addItem(Sorted->retrieveItem(i));	
	}*/
	if (Result->isEmpty())
		return false;
	/*vector<Product> ListSort;
	for(int d=0; d<List->getLength(); d++){
		Item=List->retrieveItem(d);
		ListSort.push_back(*Item);
	}

	sort(ListSort, List->getLength());

	for(int i=0;i<_num;i++)
		{Item=&ListSort[i];
	Result->addItem(Item);}*/
	//for(int k=0; k<_num; k++){
	//	Result->appendItem(ListSort[k]);
	/*}*/
	return true;
}

bool Statistics::bestInCategory(ListBase<Product>* List, string _category, ListBase<Product>* Result){
if(List->isEmpty())
		return false;
	Product* Item=NULL;
	double maximum=0; //set initial maximum to zero
	Product* Best=NULL;
	string found;	
	/*
	size_t found;	
	for(int i=0; i < List->getLength(); i++)
	{
		Item = List->retrieveItem(i);
		found=Item->get_name().find(_name);
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		if( found!= string ::npos )
		{
			Result->addItem(Item);
		}*/
	for(int prod_num=0; prod_num < List->getLength(); prod_num++)
	{
		Item=List->retrieveItem(prod_num);
		found=Item->get_category();
		if((Item->get_sale()*Item->get_price()) >= maximum && found==_category)
		{
			Best=Item;
			
			maximum = Item->get_sale()*Item->get_price();
		}		
	}
	if (Best==NULL)
		return false;
	Result->addItem(Best);
	return true;
}

bool Statistics::bestManufacturer(ListBase<Product>* List, ListBase<Product>* Result)
{
	//int max_sales;
	//Product* Item;
	if(List->isEmpty())
		return false;
	Product* Item1=NULL;
	double manu_revenue=0;
	double maximum=0;
	//set initial maximum to zero
	Product* Best=NULL;
	Product* Item2;
	string best_manu;
	ListBase<Product>* List1=new ListDA<Product>();
	for(int i=0;i<List->getLength();i++)
	{
		//int* add=new int();
		//*add=*List->retrieveItem(i);
		List1->addItem(List->retrieveItem(i));
	}
	
	while (!List1->isEmpty()){
		Item1=List1->retrieveItem(0);
		manu_revenue=Item1->get_price()*Item1->get_sale();
		for (int j=1;j<List1->getLength();j++)
		{
			Item2=List1->retrieveItem(j);
			if (Item1->get_manufacturer()==Item2->get_manufacturer())
				{
					manu_revenue+=Item2->get_price()*Item2->get_sale();
					List1->removeItem(j);
				}
		}
		
		if(manu_revenue >= maximum)
		{
			best_manu=Item1->get_manufacturer();
			
			maximum = manu_revenue;
		}
		List1->removeItem(0);
	}

	for (int i=0;i<List->getLength();i++)
		if (List->retrieveItem(i)->get_manufacturer()==best_manu)
			Result->addItem(List->retrieveItem(i));

	if (Result->getLength()==0)
		return false;
	//Result->addItem(Best);
	return true;
	/*ListBase<Product>* Manufacturer;

	for(int i=0; i<List->getLength(); i++)
	{
		Item = List->retrieveItem(i);
		if(Item->get_manufacturer()==_manuf)
			Manufacturer->addItem(Item);
	}

	Manufacturer->retrieveItem(0);
	max_sales=Item->get_sale();
	//searching for the max_sales in the given maufacturer
	for(int i=1; i<Manufacturer->getLength(); i++)
	{
		Item = Manufacturer->retrieveItem(i);
		if(Item->get_sale()>max_sales)
			max_sales=Item->get_sale();
	}

	for(int i=1; i<Manufacturer->getLength(); i++)
	{
		Manufacturer->retrieveItem(i);
		if(Item->get_sale()==max_sales)
		{
			Result->addItem(Item);
		}
	}

	if (Result->getLength()!=0)
		return true;
	else
		return false;*/
}
	