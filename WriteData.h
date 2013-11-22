#ifndef __WRITEDATA_H__
#define __WRITEDATA_H__
#include<iostream>
using namespace std;
#include"ListBase.h"
#include"Product.h"
#include"PerishableProduct.h"
#include<fstream>
#include <ctime>

class WriteData {
private:
public:
	WriteData(){}
	bool _write(ListBase<Product>* list);
};
#endif