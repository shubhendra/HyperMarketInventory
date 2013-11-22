#ifndef PERISHABLEPRODUCT_H
#define PERISHABLEPRODUCT_H

#include "Product.h"
using namespace std;

class PerishableProduct : public Product{
protected:
	string exp_date;
	double disc_percentage;
public:
	//constructor
	PerishableProduct();
	PerishableProduct(string name, string   category, string barcode, string  manufacturer, double  price, int stock, int  sale, string expiry, double disc);
	//function methods
	//void set_exp_date();
	void set_disc_percentage(double disc);
	string get_expiry();
	double get_disc(); //get discount
	//get expiry date.
	string getalldetails();
	~PerishableProduct();
};
#endif