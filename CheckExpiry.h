
#ifndef CHECKEXPIRY_H
#define CHECKEXPIRY_H

#include<iostream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"
//#include "SortedLinkedList.h"
#include <ctime>

class CheckExpiry{


public:

	string checkExpiry_function(ListBase<Product>* List, int index, int& flag);
	int check_manual(ListBase<Product>* List, int index, string current);
	
};

#endif