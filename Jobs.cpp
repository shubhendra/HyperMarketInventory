#include "Jobs.h"

Jobs::Jobs(){}
Jobs::Jobs(string _code)
{
	code=_code;
}
string Jobs::getjobcode()
{
	return code;
}
bool Jobs::readjobDetails(ifstream *readFile)
{
	if( code == "ADD")
	{
			job_add(readFile);
			return true;
	}
	else if(code == "DELETE")
	{
			job_delete(readFile);
			return true;
	}
	else if(code == "RESTOCK")
	{
			job_restock(readFile);
			return true;
	}
	else if(code == "DISPOSE")
	{
			job_dipose(readFile);
			return true;
	}
	else if(code == "SALE")
	{
			job_sale(readFile);
			return true;
	}
	else
			return false;
}


void Jobs::job_add(ifstream* readFile){
	string DUMMY;
	getline(*readFile,product_name);
	getline(*readFile,product_category);
	*readFile >> product_barcode;
	getline(*readFile,DUMMY);
	*readFile >> product_price;
	getline(*readFile,DUMMY);
	getline(*readFile, product_manufacturer);
	*readFile >> product_stock;
	getline(*readFile,DUMMY);
}

void Jobs::job_delete(ifstream* readFile){

	getline(*readFile, product_barcode);

}
void Jobs::job_restock(ifstream* readFile){
	string DUMMY;
	*readFile >> product_barcode;
	getline(*readFile,DUMMY);
	*readFile >> product_stock;
	getline(*readFile,DUMMY);
}
void Jobs::job_dipose(ifstream* readFile){
	
	string DUMMY;
	*readFile >> product_barcode;
	getline(*readFile,DUMMY);
	getline(*readFile, cur_date);
}

void Jobs::job_sale(ifstream* readFile){
	string DUMMY;
	*readFile >> product_barcode;
	getline(*readFile,DUMMY);
	*readFile >> product_sales;
	getline(*readFile,DUMMY);
}
bool Jobs::job_exec(ListBase<Product>* List)
{
	if( code == "ADD")
			return exec_add(List);
		else if(code == "DELETE")
			return exec_delete(List);
		else if(code == "RESTOCK")
			return exec_restock(List);
		else if(code == "DISPOSE")
			return exec_dipose(List);
		else if(code == "SALE")
			return exec_sale(List);
		else
			return false;
}
bool Jobs::exec_add(ListBase<Product>* List)
{
	AddProduct Batch_add;
	Search Search_Barcode;
	ListBase<Product>* Result= new ListDA<Product>();
	Search_Barcode.ByBarcode(List, product_barcode, Result);
	if(!Result->isEmpty())
	{
		//cout<<"Barcode already exist!"<<endl;
		delete Result;
		return false;
	}
	else
		{	delete Result;
			return Batch_add.addProduct(List, product_name, product_category, product_barcode, product_manufacturer,  product_price, product_stock, 0);
	}
}
bool Jobs::exec_delete(ListBase<Product>* List)
{
	//string product_barcode;
	DeleteProduct Batch_delete;
	Search Search_Barcode;
	ListBase<Product>* Result= new ListDA<Product>();
//	Search_Barcode.ByBarcode(List, product_barcode, Result);
	//cout<<List->getLength();
	if(!Search_Barcode.ByBarcode(List, product_barcode, Result))
	{
		//cout<<"Barcode does not exist!"<<endl;
		delete Result;
		return false;
	}
	else
	{ 
		bool success= Batch_delete.delete_function(List, Result->retrieveItem(0));
		delete Result;
		return success;
	}
}
bool Jobs::exec_restock(ListBase<Product>* List)
{
	Restock Batch_restock;
	Search Search_Barcode;
	ListBase<Product>* Result= new ListDA<Product>();
	//Search_Barcode.ByBarcode(List, product_barcode, Result);
	if(!Search_Barcode.ByBarcode(List, product_barcode, Result))
	{
		//cout<<"Barcode does not exist!"<<endl;
		delete Result;
		return false;
	}
	else
	{
		bool success= Batch_restock.restock_function(Result, 0 , product_stock);
		delete Result;
		return success;
	}
	return true;
}
bool Jobs::exec_dipose(ListBase<Product>* List)
{
	CheckExpiry Batch_checkexpiry;
	Search Search_Barcode;
	ListBase<Product>* Result= new ListDA<Product>();
	//Search_Barcode.ByBarcode(List, product_barcode, Result);
	if(!Search_Barcode.ByBarcode(List, product_barcode, Result))
	{
		//cout<<"Barcode does not exist!"<<endl;
		delete Result;
		return false;
	}
	else
	{
		int result;
		result=Batch_checkexpiry.check_manual(Result,0,cur_date); 
		switch (result)
		{
		case 1:
			//cout<<"Product not yet expired."<<endl;
			delete Result;
			return true;
			break;
		case 0:
			{
				//cout<<"Product expired."<<endl;
				Restock Batch_restock;
				bool success= Batch_restock.restock_function(Result, 0 , -Result->retrieveItem(0)->get_stock());
				delete Result;
				return success;
				break;
			}
		case -1:
			//cout<<"Not a perishable product"<<endl;
			delete Result;
			return false;
			break;
		default:
			delete Result;
			return false;
		}
	}
}
bool Jobs::exec_sale(ListBase<Product>* List)
{
	Sales Batch_sales;
	Search Search_Barcode;
	ListBase<Product>* Result= new ListDA<Product>();
	//Search_Barcode.ByBarcode(List, product_barcode, Result);
	if(!Search_Barcode.ByBarcode(List, product_barcode, Result))
	{
		//cout<<"Barcode does not exist!"<<endl;
		delete Result;
		return false;
	}
	else
	{
		bool success= Batch_sales.sale_function(Result,0,product_sales);
		delete Result;
		return success;
	}
}
string Jobs::retrieveErrorMsgs()
{
	string status;
	status=product_barcode+" "+code+" ";
	return status;
}