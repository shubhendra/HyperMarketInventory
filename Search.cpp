#include"Search.h"

bool Search::ByName(ListBase<Product>* List, string _name, ListBase<Product>*Result)
{
	//clock_t startTime = clock();
	Product* Item;
	size_t found;	
	for(int i=0; i < List->getLength(); i++)
	{
		Item =List->retrieveItem(i);
		found=Item->get_name().find(_name);

		if( found!= string ::npos )
		{
			Result->addItem(Item);
		}
	}
	//cout<<Result.at(0);
	if (!Result->isEmpty())
			return true;
	else
		return false;
}
bool Search::ByBarcode(ListBase<Product>* List, string _barcode, ListBase<Product>*Result)
{
	//clock_t startTime = clock();
	Product* Item;
	
	size_t found;
	for(int i=0; i < List->getLength(); i++)
	{
		Item = List->retrieveItem(i);
		found=Item->get_barcode().find(_barcode);
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		if( found!= string ::npos )
		{
			Result->addItem(Item);
		}
	}
	if (!Result->isEmpty())
		return true;
	else
		return false;
}
bool Search::ByCategory(ListBase<Product>* List, string _category, ListBase<Product>*Result)
{
	//clock_t startTime = clock();
	Product* Item;
	size_t found;
	for(int i=0; i < List->getLength(); i++)
	{
		Item = List->retrieveItem(i);
		found=Item->get_category().find(_category);
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		if( found!= string ::npos )
		{
			Result->addItem(Item);
		}
	}
	if (!Result->isEmpty())
		return true;
	else
		return false;

}
bool Search::ByManufacturer(ListBase<Product>* List, string _manufacturer, ListBase<Product>*Result)
{
	//clock_t startTime = clock();
	Product* Item;
	size_t found;
	for(int i=0; i < List->getLength(); i++)
	{
		Item = List->retrieveItem(i);
		found=Item->get_manufacturer().find(_manufacturer);
	//	clock_t endTime = clock();
	//	cout<<"Elapsed time:";
	//	cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		if( found!= string ::npos )
		{
			Result->addItem(Item);
		}
	}
	if (!Result->isEmpty())
		return true;
	else
		return false;
}
/*
bool Search::ByName(ListBase<Product>* List, string _name, vector<int>& Result)
{
	//clock_t startTime = clock();
	Product* Item;
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
			Result.push_back(i);
		}
	}
	//cout<<Result.at(0);
	if (!Result.empty())
			return true;
	else
		return false;
}
bool Search::ByBarcode(ListBase<Product>* List, string _barcode, vector<int>& Result)
{
	//clock_t startTime = clock();
	Product* Item;
	
	size_t found;
	for(int i=0; i < List->getLength(); i++)
	{
		Item = List->retrieveItem(i);
		found=Item->get_barcode().find(_barcode);
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		if( found!= string ::npos )
		{
			Result.push_back(i);
		}
	}
	if (!Result.empty())
		return true;
	else
		return false;
}*/