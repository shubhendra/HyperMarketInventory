#include"AddProduct.h"
bool AddProduct::addProduct(ListBase<Product>* List, string _name , string  _category, string _Barcode, string _manufacturer, double _price, int _stock, int _sale)
{
	Product* obj=new Product(_name , _category , _Barcode, _manufacturer, _price,_stock,_sale);
	return List->addItem(obj);
	
}
bool AddProduct::addPerishableProduct(ListBase<Product>* List,string _name, string  _category, string _Barcode, string _manufacturer, double _price, int _stock, int _sale, string _expiry, double _disc)
{
	Product* obj= new PerishableProduct(_name , _category , _Barcode, _manufacturer, _price,_stock,_sale,_expiry,_disc);
	return List->addItem(obj);
}