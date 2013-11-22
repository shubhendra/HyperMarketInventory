#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
using namespace std;
	Product::Product(){};
	Product::Product(string name, string category, string barcode, string manufacturer, double price, int stock, int sale){
		_name = name;
		_category = category;
		_barcode = barcode;
		_manufacturer = manufacturer;
		_price = price;
		_stock = stock;
		_sale = sale;
		//perishable=false;
	}

		void Product::set_price(double px){
			_price = px;
		}

	void Product::set_stock(int stock){
		_stock = stock;
	}//sets stock num

	void Product::set_sale(int num_sold){
		_sale = num_sold;
	} //sets sale num

	string Product::get_name(){
		return _name;
	} //get prod name

	string Product:: get_category(){
		return _category;
	} //get category

	string Product:: get_barcode(){
		return _barcode;
	} //get barcode

	string Product:: get_manufacturer(){
		return _manufacturer;
	} //get manufacturer

	double Product::get_price(){
		return _price;
	} //get price

	int Product::get_sale(){
		return _sale;
	} //get sale amt

	int Product::get_stock(){
		return _stock;
	} //get stock amt
	string Product:: getalldetails(){
		ostringstream os;
		string output;
		os << "Name: " << _name << endl <<
			"Category: " << _category << endl <<
			"Barcode: " << _barcode << endl <<
			"Manufacturer: " << _manufacturer << endl <<
			"Price: " << _price << endl << 
			"Stock: " << _stock << endl <<
			"Sale: " << _sale << endl;
		output = os.str();
		return output;
	} //return attribute string
	bool Product ::operator>=( const Product& _temp)
	{
		if (_name>=_temp._name)
			return true;
		else
			return false;
	}
	bool Product :: operator<= ( const Product& _temp)
	{
		if (_name<=_temp._name)
			return true;
		else
			return false;
	}
/*	void Product :: set_disc_percentage()
	{
		cout<< "This product is not a perishable product."<<endl;
	}
	string Product :: get_expiry()
	{
		return "This product is not a perishable product.\n";
		
	}
	double Product :: get_disc()
	{
		cout<< "This product is not a perishable product."<<endl;
		return 0;
	}
	bool Product :: isPerishable()
	{
		return perishable;
	}*/
	Product::~Product()
	{
	}
