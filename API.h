#ifndef API_H
#define API_H
#include"Product.h"
#include"PerishableProduct.h"
#include"AddProduct.h"
#include"CheckExpiry.h"
#include"DeleteProduct.h"
#include"ResetSales.h"
#include"Restock.h"
#include"Sales.h"
#include"Search.h"
#include"Statistics.h"
#include"BatchJobs.h"
#include "ListDA.h"
#include "ListVector.h"
//#include "SortedLinkedList.h"
#include "WriteData.h"
#include"LoadData.h"
#include"PrintList.h"

class API{
public:
	bool addPerishableProduct(ListBase<Product>* List,string _name, string   _category, string _Barcode, string   _manufacturer, double  _price, int _stock, int  _sale, string _expiry, double _disc);
	bool addProduct(ListBase<Product>* List,string _name, string  _category, string _Barcode, string _manufacturer, double _price, int _stock, int _sale);
	string checkExpiryByIndex(ListBase<Product>* List, int index, int &flag);
	//bool deleteProductByIndex(ListBase<Product>* List,int index);
	string listAll(ListBase<Product>* List);
	bool loadData(ListBase<Product>* List);
	string listPerishable(ListBase<Product>* List);
	string listNormal(ListBase<Product>* List);
	bool resetProductByIndex(ListBase<Product>* List,int index);
	bool resetAll(ListBase<Product>* List); 
	bool restockProductByIndex(ListBase<Product>* List,int index, int quantity);
	//bool restockAll(ListBase<Product>* List,int num);
	bool saleProductByIndex(ListBase<Product>* List,int index, int  quantity);
	bool searchByName(ListBase<Product>* List, string _name, ListBase<Product>*Result);
	bool searchByBarcode(ListBase<Product>* List, string _barcode, ListBase<Product>*Result);
	bool searchByCategory(ListBase<Product>* List, string _category, ListBase<Product>*Result);
	bool searchByManufacturer(ListBase<Product>* List, string _manufacturer, ListBase<Product>*Result);
	bool topX(ListBase<Product>* List,int _num, ListBase<Product>* Resultlist);
	bool bestInCategory(ListBase<Product>* List,string _category, ListBase<Product>* Resultlist);
	bool bestManufacturer(ListBase<Product>* List,ListBase<Product>* Resultlist);
	//string Print(ListBase<Product>* list, vector<int>& Resultlist);
	bool writeData(ListBase<Product>*list);

//	bool searchByName(ListBase<Product>* List, string _name, vector<int>& Resultlist);
	
//	bool searchByBarcode(ListBase<Product>* List, string _barcode, vector<int>& Resultlist);
	bool deleteProduct(ListBase<Product>* List, Product* Item);
	bool checkdate(int m, int d, int y);
	bool batchProcess(ListBase<Product>* List);
};
#endif