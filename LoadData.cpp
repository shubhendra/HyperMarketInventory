#include "LoadData.h"

using namespace std;


LoadData::LoadData()
{
}
bool LoadData::_load(ListBase<Product>* list)
{
	ifstream readFile("data.txt");
	double price, discpercentage;
	int sales, quantity;
	char perishable;
	bool isPerishable=false;
	string name, category, barcode, manufacturer, expirydate;
	string DUMMY;
	int number;
	readFile >> number;
	cout<<"Loading data..."<<endl;
	Product* newProduct;
	for(int i=0; i<number; i++)
	{
		readFile >> perishable;
		if(perishable == 'y')
			isPerishable=true;
		else
			isPerishable=false;
		getline(readFile,DUMMY);
		getline(readFile, name);
		getline(readFile, category);
		getline(readFile,barcode);
		readFile >> price;
		getline(readFile,DUMMY);
		getline(readFile,manufacturer);
		readFile >> quantity;
		getline(readFile,DUMMY);
		readFile>>sales;
		getline(readFile,DUMMY);
		if(isPerishable)
		{
			getline(readFile,expirydate);
			readFile >> discpercentage;
		}
		if(isPerishable)
		{
			//PerishableProduct(string name, string   category, string barcode, string  manufacturer, double  price, int stock, int  sale, string expiry, double disc);
			newProduct= new PerishableProduct(name,category,barcode,manufacturer,price,quantity,sales,expirydate,discpercentage);
			list->addItem(newProduct);
		}
		else
		{
			newProduct= new Product(name,category,barcode,manufacturer,price,quantity,sales);
			list->addItem(newProduct);
		}
		
	}
	
	
	readFile.close();
	return true;
}


