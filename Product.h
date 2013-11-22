#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
#include <sstream>
using namespace std;

class Product{
protected:
	//All required attributes
	string  _name;
	string  _category;
	string  _barcode;
	string  _manufacturer;
	double _price;
	int _stock;
	int _sale;
	//bool perishable;
public:
	//constructor
	Product();
	Product(string name, string  category, string barcode, string  manufacturer, double price, int stock, int sale);
	//functionality methods
	void set_price(double px); //sets price
	void set_stock(int stock); //sets stock num
	void set_sale(int num_sold); //sets sale num
	string get_name(); //get prod name
	string  get_category(); //get category
	string  get_barcode(); //get barcode
	string  get_manufacturer(); //get manufacturer
	double get_price(); //get price
	int get_sale(); //get sale amt
	int get_stock(); //get stock amt
	virtual string getalldetails(); //return attribute string
	//virtual string storedData;
	//virtual void set_disc_percentage();
	//virtual string get_expiry();
	//virtual double get_disc();
	//bool isPerishable();
	bool operator<= ( const Product& _temp);
	bool operator>= ( const Product& _temp);
	virtual ~Product();
};

#endif