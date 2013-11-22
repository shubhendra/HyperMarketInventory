#ifndef SALES_H
#define SALES_H
#include<iostream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"
//#include "SortedLinkedList.h"
#include <ctime>


class Sales{
public:
	bool sale_function(ListBase<Product>* List,int index, int  quantity);
	
	//set sale method
};
#endif