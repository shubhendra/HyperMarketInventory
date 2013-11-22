#ifndef DELETEPRODUCT_H
#define DELETEPRODUCT_H
#include<iostream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"


class DeleteProduct{
public:

	bool delete_function(ListBase<Product>* List,int index);
	bool delete_function(ListBase<Product>* List, Product* Item);
	
};

#endif