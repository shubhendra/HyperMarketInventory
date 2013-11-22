	#include"API.h"
	bool API::addPerishableProduct(ListBase<Product>* List,string _name, string   _category, string _Barcode, string   _manufacturer, double  _price, int _stock, int  _sale, string _expiry, double _disc)
	{
		AddProduct add;		
		return add.addPerishableProduct(List,_name,_category,_Barcode,_manufacturer,_price,_stock,_sale,_expiry,_disc);
	}
	bool API::addProduct(ListBase<Product>* List,string _name, string  _category, string _Barcode, string _manufacturer, double _price, int _stock, int _sale)
	{
		AddProduct add;		
		return add.addProduct(List,_name,_category,_Barcode,_manufacturer,_price,_stock,_sale);
	}
	string API::checkExpiryByIndex(ListBase<Product>* List, int index, int& flag)
	{
		CheckExpiry check;
		return check.checkExpiry_function(List,index,flag);
	}
	/*
	bool API::deleteProductByIndex(ListBase<Product>* List,int index)
	{
		DeleteProduct deleteProcess;
		return	deleteProcess.delete_function(List, index);
		//return true;
	}*/
	bool API::loadData(ListBase<Product>* List)
	{
		LoadData _data;
		return _data._load(List);
	}
	string API::listAll(ListBase<Product>* List)
	{
		PrintList printProcess;
		return printProcess.printList(List);

		
		//return true;
	}
	string API::listPerishable(ListBase<Product>* List)
	{
		PrintList printProcess;
		return printProcess.printAllPerishable(List);
		//return true;
	}
	string API::listNormal(ListBase<Product>* List)
	{
		PrintList printProcess;
		return printProcess.printAllNormal(List);
		//return true;
	}
	bool API::resetProductByIndex(ListBase<Product>* List,int index)
	{
		ResetSales resetProcess;
		return resetProcess.reset_function(List, index);
		//return true;
	}
	bool API::resetAll(ListBase<Product>* List)
	{
		ResetSales resetProcess;
		return resetProcess.resetAll(List);
		//return true;
	}
	bool API::restockProductByIndex(ListBase<Product>* List,int index, int quantity)
	{
		Restock restockProcess;
		return restockProcess.restock_function(List, index, quantity);
		//return true;
	};
	//bool API::restockAll(ListBase<Product>* List,int num){return true;}
	bool API::saleProductByIndex(ListBase<Product>* List,int index, int  quantity)
	{
		Sales salesProcess;
		return	salesProcess.sale_function(List, index, quantity);
		//return true;
	}
	bool API::searchByName(ListBase<Product>* List, string _name, ListBase<Product>*Result)
	{
		Search searchProcess;
		return searchProcess.ByName(List, _name, Result);
		//cout<<Resultlist.at(0);
		//return true;
	}
	bool API::searchByBarcode(ListBase<Product>* List, string _barcode, ListBase<Product>*Result)
	{
		Search searchProcess;
		return searchProcess.ByBarcode(List, _barcode, Result);
		//return true;
	}
	bool API::searchByCategory(ListBase<Product>* List, string _category, ListBase<Product>*Result)
	{
		Search searchProcess;
		return searchProcess.ByCategory(List, _category, Result);
	//	return true;
	}
	bool API::searchByManufacturer(ListBase<Product>* List, string _manufacturer,  ListBase<Product>*Result)
	{
		Search searchProcess;
		return searchProcess.ByManufacturer(List, _manufacturer, Result);
		//return true;
	}
	bool API::topX(ListBase<Product>* List,int _num, ListBase<Product>* Resultlist)
	{
		Statistics statisticsProcess;
		return statisticsProcess.topX(List, _num, Resultlist);

		//for(int i=0;i<Resultlist->getLength();i++)
	//{
		//cout<<Resultlist->retrieveItem(i)->get_name();
	//}
	//	PrintList printProcess;
		//printProcess.printResultListProduct(Resultlist);
		//return true;
	}
	bool API::bestInCategory(ListBase<Product>* List,string _category, ListBase<Product>* Resultlist)
	{
		Statistics statisticsProcess;
		return statisticsProcess.bestInCategory(List, _category, Resultlist);
		//PrintList printProcess;
		//printProcess.printResultListProduct(Resultlist);
		//return true;
	}
	bool API::bestManufacturer(ListBase<Product>* List, ListBase<Product>* Resultlist)
	{
		Statistics statisticsProcess;
		return statisticsProcess.bestManufacturer(List,Resultlist);
		//PrintList printProcess;
		//printProcess.printResultListProduct(Resultlist);
		//return true;
	}

/*	string API :: Print(ListBase<Product>* List, vector<int>& Resultlist)
	{
		PrintList _toPrint;
		return _toPrint.printResultList(List,Resultlist);
	}
*/
	bool API::writeData(ListBase<Product>* List)
	{
		WriteData write;
		return write._write(List);
	}

	/*bool API::searchByName(ListBase<Product>* List, string _name, vector<int>& Resultlist)
	{
		Search searchProcess;
		return searchProcess.ByName(List, _name, Resultlist);
		//cout<<Resultlist.at(0);
		//return true;
	}
	bool API::searchByBarcode(ListBase<Product>* List, string _barcode, vector<int>& Resultlist)
	{
		Search searchProcess;
		return searchProcess.ByBarcode(List, _barcode, Resultlist);
		//return true;
	}*/
	bool API::deleteProduct(ListBase<Product>* List, Product* Item)
	{
		DeleteProduct deletepdt;
		return deletepdt.delete_function(List,Item);
	
	}
	
	bool API::batchProcess(ListBase<Product>* List)
	{
		//WriteData toWrite;
		
		//ListBase<Product>*List=new ListDA<Product>();
		
		BatchJobs newBatch;
		if(newBatch.addUsers())
		{
			if(newBatch.startProcess(List))
			{
				return true;
			}
			else
				return false;
		}
		else
			return false;
		//toWrite._write(List);
	
		return true;
	}

	bool API::checkdate(int m, int d, int y)
	{
	
		
  //gregorian dates started in 1582 
  if (! (1582<= y )  )//comment these 2 lines out if it bothers you
     return false;
  if (! (1<= m && m<=12) )
     return false;
  if (! (1<= d && d<=31) )
     return false;
  if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
     return false;
  if ( (d==30) && (m==2) )
     return false;
  if ( (m==2) && (d==29) && (y%4!=0) )
     return false;
  if ( (m==2) && (d==29) && (y%400==0) )
     return true;
  if ( (m==2) && (d==29) && (y%100==0) )
     return false;
  if ( (m==2) && (d==29) && (y%4==0)  )
     return true;

  return true;

	}