#ifndef __PRINTLIST_H__
#define __PRINTLIST_H__

#include<iostream>
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"
//#include "SortedLinkedList.h"
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

class PrintList{
public:
	string printList(ListBase<Product>* List);
	//string printResultList(ListBase<Product>* List,vector<int>& Result);
	//string printResultListProduct(ListBase<Product>* Result);
	string printAllNormal(ListBase<Product>* List);
	string printAllPerishable(ListBase<Product>* List);

};

#endif