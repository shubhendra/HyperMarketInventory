#ifndef RESTOCK_H
#define RESTOCK_H
#include<iostream>
using namespace std;
#include"Product.h"
#include"PerishableProduct.h"
#include"ListBase.h"

#include "ListDA.h"
#include "ListVector.h"
//#include "SortedLinkedList.h"
#include <ctime>

class Restock{
public:
	
	bool restock_function(ListBase<Product>* List,int index, int quantity);
	//bool restockAll(ListBase<Product>* List,int num); //restock all prod

};

#endif