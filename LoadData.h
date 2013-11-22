#ifndef __LOADDATA_H__
#define __LOADDATA_H__
#include<iostream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"
#include<fstream>
#include <ctime>

class LoadData {
private:
public:
	LoadData();
	bool _load(ListBase<Product>* list);
};
#endif