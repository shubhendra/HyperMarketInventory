#ifndef __INTERFACEIO_H__
#define __INTERFACEIO_H__
#include<iostream>
#include<string>
#include<Windows.h>
#include"API.h"

using namespace std;

class interfaceIO{
private:
	//vector<int> Result;
	//ListBase<Product>* TempList;
	HANDLE hConsole;
public:
	interfaceIO();
	//bool checkdate(int,int,int);
	void Header();
	void error();
	void gotoxy(int x,int y);
	void addNormal(ListBase<Product>* list);
	void addPerishable(ListBase<Product>* list);
	void deleteProductByName(ListBase<Product>* list);
	void deleteProductByBarcode(ListBase<Product>* list);
	void resetSalesAll(ListBase<Product>* list);
	void resetSalesOneProductByName(ListBase<Product>* list);
	void resetSalesOneProductByBarcode(ListBase<Product>* list);
	void salesByName(ListBase<Product>* list);
	void salesByBarcode(ListBase<Product>* list);
	void restockByName(ListBase<Product>* list);
	void restockByBarcode(ListBase<Product>* list);
	void topXProducts(ListBase<Product>* list);
	void topProductInCategory(ListBase<Product>* list);
	void topManufacturer(ListBase<Product>* list);
	void loadData(ListBase<Product>* list);
	void listAllPerishable(ListBase<Product>* list);
	void listAll(ListBase<Product>* list);
	//void printAll();
	void listAllNormal(ListBase<Product>* list);
	//void loadData();
	void checkExpiryByName(ListBase<Product>* list);
	void checkExpiryByBarcode(ListBase<Product>* list);
	void searchByName(ListBase<Product>* list);
	void searchByCategory(ListBase<Product>*list);
	void searchByBarcode(ListBase<Product>* list);
	void searchByManufacturer(ListBase<Product>* list);
	void saveData(ListBase<Product>* list);
	//void loadData(ListBase<Product>* list);
	void Quit(ListBase<Product>* list);
	void BatchProcessing(ListBase<Product>* list);
};
#endif