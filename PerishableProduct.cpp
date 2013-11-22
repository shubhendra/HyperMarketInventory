#include <string>
#include <sstream>
#include "Product.h"
#include "PerishableProduct.h"
using namespace std;
PerishableProduct::PerishableProduct():Product(){}
PerishableProduct::PerishableProduct(string _name, string  _category, string _Barcode, string   _manufacturer, double  _price, int _stock, int  _sale, string _expiry, double _disc)
	:Product(_name, _category, _Barcode, _manufacturer, _price, _stock, _sale){
		exp_date = _expiry;
		disc_percentage = _disc;
		//perishable=true;
		//cout<<this->get_expiry();
}
		void PerishableProduct::set_disc_percentage(double disc){
			disc_percentage=disc;
			//set discount
			}//get expiry date.
		string PerishableProduct::get_expiry(){
			return exp_date;
			}
		double PerishableProduct::get_disc(){
			return disc_percentage;
			} //get discount
			
		string PerishableProduct:: getalldetails(){
			ostringstream os;
			string output;
			os << "Name: " << _name << endl <<
			"Category: " << _category << endl <<
			"Barcode: " << _barcode << endl <<
			"Manufacturer: " << _manufacturer << endl <<
			"Price: " << _price << endl << 
			"Stock: " << _stock << endl <<
			"Sale: " << _sale << endl <<
			"Expiry: " << exp_date << endl <<
			"Discount Percentage: " << disc_percentage << endl;
			output = os.str();
			return output;
		}
		PerishableProduct::~PerishableProduct()
		{
		}