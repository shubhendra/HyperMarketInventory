
//#include <Windows.h>
#include"Menus.h"
#include"InterfaceIO.h"
#include"ListBase.h"
#include "Product.h"
#include "PerishableProduct.h"

#include "ListDA.h"
#include "ListVector.h"
#include "SortedLinkedList.h"

using namespace std;


int main()

{
	HANDLE hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = {5, 5,120, 50};
	COORD buffer={120,1500};
	SetConsoleScreenBufferSize(hconsole,buffer);
	SetConsoleWindowInfo(hconsole, TRUE, &windowSize);
	Menus UserInterface;
	interfaceIO* Interface=new interfaceIO();
	ListBase<Product>* Inventory= new ListDA<Product>();//or any other type of list
	int choice;
	//int flag;
	int flag_main;
	int flag_sub;
	int flag_sub_sub;
	API* Process=new API();
	Interface->loadData(Inventory);
	do{	
	
	UserInterface.MainMenu();
	choice=UserInterface.UserChoice();
	switch(choice)
	{
	case 1:
		do{
			flag_main=0;
			UserInterface.SubMenuAdd_Del();
			
			switch(UserInterface.UserChoice())
			{
			case 1: 
				do{
					flag_sub=0;
					UserInterface.SubMenuAdd();

					switch(UserInterface.UserChoice())
					{
					case 1:
						Interface->addPerishable(Inventory);
						break;
					case 2:
						Interface->addNormal(Inventory);
						break;
					case 3:
						flag_main=1;
						break;					
					case 0:
						break;
					default:
						Interface->error();
						cin.clear();
						system("pause");
						flag_sub=1;
						break;
					}
				}while(flag_sub==1);
				break;				
			case 2:
				do{
					flag_sub=0;
					UserInterface.SubMenuDelete();
					switch(UserInterface.UserChoice())
					{
					case 1:
						Interface->deleteProductByName(Inventory);
						break;
					case 2:
						Interface->deleteProductByBarcode(Inventory);
						break;
					case 3:
						flag_main=1;
						break;
					case 0:
						break;
					default:Interface->error();
						cin.clear();
						system("pause");
						flag_sub=1;
						break;
					}
				}while(flag_sub==1);
				break;
			case 0:
				break;
			default:
				Interface->error();
				cin.clear();
				system("pause");
				flag_main=1;
				break;
			}
		}while(flag_main==1);
		break;
	
	case 2:
		do{
			flag_main=0;
			UserInterface.SubMenuSales_Reset();
			
			switch(UserInterface.UserChoice())
			{
			case 1: 
				do{
					flag_sub=0;
					UserInterface.SubMenuSales();

					switch(UserInterface.UserChoice())
					{
					case 1:
						Interface->salesByName(Inventory);
						break;
					case 2:
						Interface->salesByBarcode(Inventory);
						break;
					case 3:
						flag_main=1;
						break;
					case 0:
						break;
					default:
						Interface->error();
						cin.clear();
						system("pause");
						flag_sub=1;
						break;
					}
				}while(flag_sub==1);
				break;				
			case 2:
				do{
					flag_sub=0;
					UserInterface.SubMenuReset();
					switch(UserInterface.UserChoice())
					{
					case 1:
						Interface->resetSalesAll(Inventory);
						break;
					case 2:
						do{
							flag_sub_sub=0;
							UserInterface.SubMenuResetOne();
							switch(UserInterface.UserChoice())
							{
							case 1:
								Interface->resetSalesOneProductByName(Inventory);
								break;
							case 2:		
								Interface->resetSalesOneProductByBarcode(Inventory);
								break;
							case 3:
								flag_sub=1;
								break;
							case 0:
								break;
							default:
								Interface->error();
								cin.clear();
								system("pause");
								flag_sub_sub=1;
								break;
							}
						}while(flag_sub_sub==1);
						break;

					case 3:
						flag_main=1;
						break;
					case 0:
						break;
					default:
						Interface->error();
						cin.clear();
						system("pause");
						flag_sub=1;
						break;
					}
				}while(flag_sub==1);
				break;
			case 0:
				break;
			default:
				Interface->error();
				cin.clear();
				system("pause");
				flag_main=1;
				break;
			}
		}while(flag_main==1);
		break;
	
	case 3:
		do{
			flag_main=0;
			
			UserInterface.SubMenuRestock();
			
			switch(UserInterface.UserChoice())
			{
			case 1: 
				Interface->restockByName(Inventory);
				break;				
			case 2:
				Interface->restockByBarcode(Inventory);
				break;
			case 0:
				break;
			default:Interface->error();
					cin.clear();
					system("pause");
					flag_main=1;
					break;
			}
		}while(flag_main==1);
		break;
	case 4:
		do{
			flag_main=0;
			UserInterface.SubMenuStatistics();
			
			switch(UserInterface.UserChoice())
			{
			case 1: 
				Interface->topXProducts(Inventory);
				break;				
			case 2:
				Interface->topProductInCategory(Inventory);
				break;
			case 3:
				Interface->topManufacturer(Inventory);
				break;
			case 0:break;
			default:
				Interface->error();
				system("pause");
				flag_main=1;
				break;
			}
		}while(flag_main==1);
		break;
	case 5:
		do{
			flag_main=0;
			UserInterface.SubMenuList();
			
			switch(UserInterface.UserChoice())
			{
			case 1: 
				Interface->listAllPerishable(Inventory);
				break;				
			case 2:
				Interface->listAllNormal(Inventory);
				break;
			case 3:
				Interface->listAll(Inventory);
				break;
			case 0:break;
			default:
				Interface->error();
				cin.clear();
				system("pause");
				flag_main=1;
				break;
			}
		}while(flag_main==1);
		break;
	case 6:
		do{
			flag_main=0;
			UserInterface.SubMenuSearch();
			
			switch(UserInterface.UserChoice())
			{
			case 1: 
				Interface->searchByName(Inventory);
				break;				
			case 2:
				Interface->searchByCategory(Inventory);
				break;
			case 3:
				Interface->searchByManufacturer(Inventory);
				break;
			case 4:
				Interface->searchByBarcode(Inventory);
				break;
			case 0:break;
			default:
				Interface->error();
				cin.clear();
				system("pause");
				flag_main=1;
				break;
			}
		}while(flag_main==1);
		break;
	case 7:
		do{
			flag_main=0;
			UserInterface.SubMenuCheckExpiry();
			
			switch(UserInterface.UserChoice())
			{
			case 1: 
				Interface->checkExpiryByName(Inventory);
				break;				
			case 2:
				Interface->checkExpiryByBarcode(Inventory);
				break;
			case 0:break;
			default:
				Interface->error();
				cin.clear();
				system("pause");
				flag_main=1;
				break;
			}
		}while(flag_main==1);
		break;
	case 8:
		Interface->saveData(Inventory);
		break;
	case 9: 
		Interface->BatchProcessing(Inventory);
		break;
	case 0:
		Interface->Quit(Inventory);
		break;
	default:
		Interface->error();
		cin.clear();
		system("pause");
		break;
	}
	}while(choice!=0);
	//if (Process->writeData(Inventory))
		//cout<<"Data Written";
	//else
		//cout<<"Data not written";
	getchar();getchar();
	delete Process;
	for(int i=0;i<Inventory->getLength();i++)
	{
		delete Inventory->retrieveItem(i);
	}
	delete Inventory;
	delete Interface;
	
	return 0;
}