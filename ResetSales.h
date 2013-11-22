#ifndef RESETSALES_H
#define RESETSALES_H
#include<iostream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"


//#include "SortedLinkedList.h"
#include <ctime>

class ResetSales{
public:
	
	bool reset_function(ListBase<Product>* List,int index);
	bool resetAll(ListBase<Product>* List); //reset all prod

};
#endif