#ifndef SEARCH_H
#define SEARCH_H
#include<iostream>
#include<sstream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"
//#include "SortedLinkedList.h"
#include <ctime>

class Search{
//ListBase<int>* ResultList;
public:
/*	bool ByName(ListBase<Product>* List, string _name, vector<int>& Result);
	bool ByBarcode(ListBase<Product>* List, string _barcode, vector<int>& Result);
	bool ByCategory(ListBase<Product>* List, string _category, vector<int>& Result);
	bool ByManufacturer(ListBase<Product>* List, string _manufacturer, vector<int>& Result);
	*/

	bool ByName(ListBase<Product>* List, string _name, ListBase<Product>*Result);
	bool ByBarcode(ListBase<Product>* List, string _barcode, ListBase<Product>*Result);
	bool ByCategory(ListBase<Product>* List, string _category,ListBase<Product>*Result);
	bool ByManufacturer(ListBase<Product>* List, string _manufacturer, ListBase<Product>*Result);
	
};

#endif