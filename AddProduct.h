#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H
#include<iostream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include "PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"
//#include "SortedLinkedList.h"
#include <ctime>

class AddProduct{
public:
	//AddProduct(); //default constructor
	//add normal product
	bool addProduct(ListBase<Product>* List,string _name, string  _category, string _Barcode, string _manufacturer, double _price, int _stock, int _sale);
	//add perishable product
	bool addPerishableProduct(ListBase<Product>* List,string _name, string   _category, string _Barcode, string   _manufacturer, double  _price, int _stock, int  _sale, string _expiry, double _disc);
};
#endif