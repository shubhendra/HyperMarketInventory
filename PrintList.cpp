#include <iostream>
#include <iomanip>
#include"PrintList.h"
using namespace std;

string PrintList::printList(ListBase<Product>* List)
{
	
	//clock_t startTime = clock();
	Product* Item;
	ostringstream os;
	int *index=NULL;
	if(List->isEmpty()){
		//Alerts of error when the List is nil
		os<< "There are no items in the List." << endl;
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return false;
	}

		os<<"\n";
		os<< setw(5) << "Index" << setw(20) << "Product Name" <<  setw(8) << "Barcode" << setw(15)<<"Manufacturer"<<setw(20)<<"Category"<<setw(8)<<"Price"<<setw(8)<<"Stock"<<setw(8)<<"Sales"<<setw(12)<<"Expiry date"<<setw(12)<<"Discount %"<<endl;
		for(int j=0; j < List->getLength() ; j++)
		{
			Item = List->retrieveItem(j);
			PerishableProduct* obj;
			obj=dynamic_cast<PerishableProduct*>(Item);
			if (obj==NULL)
			os<< setw(5) << j+1 << setw(20) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<"N/A"<<setw(12)<<"N/A"<<endl;
			else
				os<< setw(5) << j+1 << setw(20) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<obj->get_expiry()<<setw(12)<<fixed<<setprecision(2)<<obj->get_disc()<<endl;

		}
	//	clock_t endTime = clock();
	//	cout<<"Elapsed time:";
	//	cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return os.str();
}

/*
string PrintList::printResultList(ListBase<Product>* List,vector<int>& Result){
//	clock_t startTime = clock();
	Product* Item;
	ostringstream os;
	int* index;
	if(Result.empty()){
		//Alerts of error when the results are nil
		os<< "There are no results." << endl;
	//	clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return false;
	}
			os<< setw(5) << "Index" << setw(15) << "Product Name" <<  setw(8) << "Barcode" << setw(15)<<"Manufacturer"<<setw(20)<<"Category"<<setw(8)<<"Price"<<setw(8)<<"Stock"<<setw(8)<<"Sales"<<setw(12)<<"Expiry date"<<setw(12)<<"Discount %"<<endl;
		for(int j=0; j < Result.size() ; j++){
			index = &Result.at(j);
			Item = List->retrieveItem(*index);
			PerishableProduct* obj;
			obj=dynamic_cast<PerishableProduct*>(Item);
			if (obj==NULL)
			os<< setw(5) << j+1 << setw(15) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<"N/A"<<setw(12)<<"N/A"<<endl;
			else
				os<< setw(5) << j+1 << setw(15) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<obj->get_expiry()<<setw(12)<<fixed<<setprecision(2)<<obj->get_disc()<<endl;		}
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return os.str();
}
*/
/*
string PrintList::printResultListProduct(ListBase<Product>* Result)
{
	//clock_t startTime = clock();
	Product* Item;
	ostringstream os;
	if(Result->isEmpty()){
		//Alerts of error when the results are nil
		os<< "There are no results." << endl;
	//	clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return false;
	}
		os<< setw(5) << "Index" << setw(15) << "Product Name" <<  setw(8) << "Barcode" << setw(15)<<"Manufacturer"<<setw(20)<<"Category"<<setw(8)<<"Price"<<setw(8)<<"Stock"<<setw(8)<<"Sales"<<setw(12)<<"Expiry date"<<setw(12)<<"Discount %"<<endl;
		for(int j=0; j < Result->getLength() ; j++){
			Item = Result->retrieveItem(j);
			PerishableProduct* obj;
			obj=dynamic_cast<PerishableProduct*>(Item);
			if (obj==NULL)
			os<< setw(5) << j+1 << setw(15) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<"N/A"<<setw(12)<<"N/A"<<endl;
			else
				os<< setw(5) << j+1 << setw(15) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<obj->get_expiry()<<setw(12)<<fixed<<setprecision(2)<<obj->get_disc()<<endl;		}
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return os.str();
}
*/
string PrintList::printAllPerishable(ListBase<Product>* List)
{
	//clock_t startTime = clock();
	Product* Item;
	ostringstream os;
	int *index=NULL;
	if(List->isEmpty())
	{
		//Alerts of error when the List is nil
		os<< "There are no items in the List." << endl;
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return false;
	}
		os<<"\n";
		os<< setw(5) << "Index" << setw(20) << "Product Name" <<  setw(8) << "Barcode" << setw(15)<<"Manufacturer"<<setw(20)<<"Category"<<setw(8)<<"Price"<<setw(8)<<"Stock"<<setw(8)<<"Sales"<<setw(12)<<"Expiry date"<<setw(12)<<"Discount %"<<endl;
		for(int j=0; j < List->getLength() ; j++)
		{
			Item = List->retrieveItem(j);
			PerishableProduct* obj;
			obj=dynamic_cast<PerishableProduct*>(Item);
			if (obj!=NULL)
			//os<< setw(5) << j+1 << setw(15) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<"N/A"<<setw(12)<<"N/A"<<endl;
			//else
				os<< setw(5) << j+1 << setw(20) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<obj->get_expiry()<<setw(12)<<fixed<<setprecision(2)<<obj->get_disc()<<endl;

		}
	//	clock_t endTime = clock();
	//	cout<<"Elapsed time:";
	//	cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return os.str();
}
string PrintList::printAllNormal(ListBase<Product>* List)
{
	//clock_t startTime = clock();
	Product* Item;
	ostringstream os;
	int *index=NULL;
	if(List->isEmpty()){
		//Alerts of error when the List is nil
		os<< "There are no items in the List." << endl;
		//clock_t endTime = clock();
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return false;
	}
	os<<"\n";
		os<< setw(5) << "Index" << setw(20) << "Product Name" <<  setw(8) << "Barcode" << setw(15)<<"Manufacturer"<<setw(20)<<"Category"<<setw(8)<<"Price"<<setw(8)<<"Stock"<<setw(8)<<"Sales"<<setw(12)<<"Expiry date"<<setw(12)<<"Discount %"<<endl;
		for(int j=0; j < List->getLength() ; j++)
		{
			Item = List->retrieveItem(j);
			PerishableProduct* obj;
			obj=dynamic_cast<PerishableProduct*>(Item);
			if (obj==NULL)
				os<< setw(5) << j+1 << setw(20) << Item->get_name() << setw(8) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(20)<<Item->get_category()<<setw(8)<<fixed<<setprecision(2)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<"N/A"<<setw(12)<<"N/A"<<endl;
			//else
				//os<< setw(5) << j+1 << setw(20) << Item->get_name() << setw(15) << Item->get_barcode() << setw(15)<<Item->get_manufacturer()<<setw(15)<<Item->get_category()<<setw(8)<<Item->get_price()<<setw(8)<<Item->get_stock()<<setw(8)<<Item->get_sale()<<setw(12)<<obj->get_expiry()<<setw(12)<<obj->get_disc()<<endl;

		}
	//	clock_t endTime = clock();
	//	cout<<"Elapsed time:";
	//	cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		return os.str();
}
