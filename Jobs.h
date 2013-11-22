#ifndef JOBS_H
#define JOBS_H
#include <iostream>
#include "queue.h"
#include "AddProduct.h"
#include "CheckExpiry.h"
#include"Restock.h"
#include "sales.h"
#include"DeleteProduct.h"
#include "Search.h"
#include <fstream>
using namespace std;

class Jobs{
private:
	string code;
	string product_name;
	string product_category;
	string product_barcode;
	double product_price;
	string product_manufacturer;
	int product_stock;
	string cur_date;
	int product_sales;
	void job_add(ifstream* readFile);
	void job_delete(ifstream* readFile);
	void job_restock(ifstream* readFile);
	void job_dipose(ifstream* readFile);
	void job_sale(ifstream* readFile);
	bool exec_add(ListBase<Product>* List);
	bool exec_delete(ListBase<Product>* List);
	bool exec_restock(ListBase<Product>* List);
	bool exec_dipose(ListBase<Product>* List);
	bool exec_sale(ListBase<Product>* List);
public:
	Jobs();
	Jobs(string _code);
	string retrieveErrorMsgs();
	bool readjobDetails(ifstream * readFile);
	string getjobcode();
	bool job_exec(ListBase<Product>* List);
	
};
#endif