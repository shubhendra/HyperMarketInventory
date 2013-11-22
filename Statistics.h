#ifndef STATISTICS_H
#define STATISTICS_H

#include<iostream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"
#include "ListCDL.h"
//#include "SortedLinkedList.h"
#include <vector>
#include <ctime>

class Statistics{
private:
	void sort(vector<Product>& ProdList, int n);
	void sortX(ListBase<Product>* List, ListBase<Product>* List2,int x);
	
public:
	bool topX(ListBase<Product>* List,int _num, ListBase<Product>* Result);
	bool bestInCategory(ListBase<Product>* List,string _category,  ListBase<Product>* Result);
	
	bool bestManufacturer(ListBase<Product>* List, ListBase<Product>* Result);
};

#endif