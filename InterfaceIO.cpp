#include"InterfaceIO.h"

interfaceIO::interfaceIO()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//Result=new ListDA<int>();
	//TempList=new ListDA<Product>();
	
}

void interfaceIO::Header()
{
	system("CLS");
	
	cout<<"\n";
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	cout<<"                            ___                       ___           ___           ___                               "<<endl;
	cout<<"                           /\\__\\                     /\\__\\         /\\  \\         /\\__\\                              "<<endl;
	cout<<"                          /:/  /        ___         /:/  /        |::\\  \\       /:/ _/_                             "<<endl;
	cout<<"                         /:/  /        /\\__\\       /:/  /         |:|:\\  \\     /:/ /\\  \\                            "<<endl;
	cout<<"                        /:/  /  ___   /:/__/      /:/  /  ___   __|:|\\:\\  \\   /:/ /::\\  \\                           "<<endl;
	cout<<"                       /:/__/  /\\__\\ /::\\  \\     /:/__/  /\\__\\ /::::|_\\:\\__\\ /:/_/:/\\:\\__\\                          "<<endl;
	cout<<"                       \\:\\  \\ /:/  / \\/\\:\\  \\__  \\:\\  \\ /:/  / \\:\\~~\\  \\/__/ \\:\\/:/ /:/  /                          "<<endl;
	cout<<"                        \\:\\  /:/  /   ~~\\:\\/\\__\\  \\:\\  /:/  /   \\:\\  \\        \\::/ /:/  /                           "<<endl;
	cout<<"                         \\:\\/:/  /       \\::/  /   \\:\\/:/  /     \\:\\  \\        \\/_/:/  /                            "<<endl;
	cout<<"                          \\::/  /        /:/  /     \\::/  /       \\:\\__\\         /:/  /                             "<<endl;
	cout<<"                           \\/__/         \\/__/       \\/__/         \\/__/         \\/__/                              "<<endl;
	cout<<"                                                                                                                    "<<endl;
	//system("color 0F");
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED |15 );
	cout<<"\n--------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|                       CEG  Hypermarket  Inventory  Control  and  Monitoring  System                              |"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void interfaceIO::error()
{
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
	cout << "\n\aIncorrect Input!! Please Enter Again.\n";
	SetConsoleTextAttribute(hConsole, 15);
	//system("pause");
}
void interfaceIO :: gotoxy(int x, int y) //goes to x,y console
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void interfaceIO:: deleteProductByName(ListBase<Product>* list)
{
	string _toDelete;
	bool isPossible;
	Header();
	//vector<int> Result;
	ListBase<Product>* TempList=new ListDA<Product>();
	//system("color 4F");
	cout<<"\n                       ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(43,18);
	cout<<"----------------------------"<<endl;
	gotoxy(43,19);
	cout<<"| DELETING PRODUCT BY NAME |"<<endl;
	gotoxy(43,20);
	cout<<"----------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cin.ignore(10,'\n');
	cout<<"\nEnter the name of product you want to delete: ";
	getline(cin, _toDelete);
	API*  Process= new API();
	isPossible=Process->searchByName(list,_toDelete,TempList);
	//call delete function from the operation class delete function
	if (isPossible)
	{
		int index;
		string ch;
		
				cout<<Process->listAll(TempList);
				cout<<"Enter the index of the product you want to delete: [Numbers only]";
				int flag=0;
				do{
					flag=0;
					//gotoxy(42,25);
					//cin.ignore(1,'\n');
					cin>>index;
					index--;
					if (cin.fail()||index>=TempList->getLength())
					{
						//gotoxy(0,29);
						error();
						cin.clear();
						cin.ignore(10,'\n');
						flag=1;
					}
					else
					{
						//gotoxy(0,30);
						cout<<"                                                         "<<endl;
					}
				}while(flag==1);

			

				do{
					//gotoxy(0,32);
					cout<<TempList->retrieveItem(index)->getalldetails();
					cout << "\nDo You Want To Delete This Product? (Y/N) ";
					cin >> ch;
					if(ch=="Y" || ch=="y")
					{
						//int _itemIndex;
						//_itemIndex=Result.at(index);
						Product * item=TempList->retrieveItem(index);
						//clock_t startTime = clock(); //Do this right before invoking the function
						if(Process->deleteProduct(list,item))
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							////cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 10);
							cout << "\nProduct Deleted Successfully\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
						else
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							////cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 12);
							cout << "\n\aUnable to Delete Product\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
					}
					else if(ch=="n" || ch=="N")
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << "\n\aProduct Not Deleted\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
					else
						error();
				}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
		
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	system("pause");
	//delete Result;
	delete TempList;
	delete Process;
}
void interfaceIO:: deleteProductByBarcode(ListBase<Product>* list)
{
	string _toDelete;
	Header();
	bool isPossible;
	ListBase<Product>* TempList=new ListDA<Product>();
	//vector<int> Result;
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(42,18);
	cout<<"-----------------------------"<<endl;
	gotoxy(42,19);
	cout<<"|DELETING PRODUCT BY BARCODE|"<<endl;
	gotoxy(42,20);
	cout<<"-----------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the barcode of product you want to delete: ";
	cin>> _toDelete;
	string ch;
	API* Process= new API();
	isPossible=Process->searchByBarcode(list,_toDelete,TempList);
	//call delete function from the operation class delete function
	if(isPossible)
	{
		int index;
		string ch;
				cout<<Process->listAll(TempList);
				cout<<"Enter the index of the product you want to delete: [Numbers only]";
				int flag=0;
				do{
					flag=0;
					//gotoxy(42,25);
					cin>>index;
					index--;
					if (cin.fail()||index>=TempList->getLength())
					{
						//gotoxy(0,29);
						error();
						cin.clear();
						cin.ignore(10,'\n');
						flag=1;
					}
					else
					{
						//gotoxy(0,30);
						cout<<"                                                         "<<endl;
					}
				}while(flag==1);

			

				do{
					//gotoxy(0,32);
					cout<<TempList->retrieveItem(index)->getalldetails();
					cout << "\nDo You Want To Delete This Product? (Y/N) ";
					cin >> ch;
					if(ch=="Y" || ch=="y")
					{
						//int _itemIndex;
					//_itemIndex=Result.at(index);//=Result->retrieveItem(index);
					//clock_t startTime = clock(); //Do this right before invoking the function
					if(Process->deleteProduct(list,TempList->retrieveItem(index)))
						{
						//	clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							////cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 10);
							cout << "\nProduct Deleted\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
						else
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							////cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 12);
							cout << "\n\aUnable to Delete Product\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
					}
					else if(ch=="n" || ch=="N")
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << "\n\aProduct Not Deleted\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
					else
						error();
				}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
		
	}
	else
		{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	//call delete function from the operation class delete function
	//delete Result;
	delete Process;
	delete TempList;
system("pause");
}

void interfaceIO:: resetSalesOneProductByName(ListBase<Product>* list)
{
	string _toResetSales;
	Header();
	bool isPossible;
	 
	ListBase<Product>* TempList=new ListDA<Product>();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(39,18);
	cout<<"-----------------------------------"<<endl;
	gotoxy(39,19);
	cout<<"| RESETTING PRODUCT SALES BY NAME |"<<endl;
	gotoxy(39,20);
	cout<<"-----------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the name of product you want to reset: ";
	cin>> _toResetSales;
	//call reset function from the operation class reset function
	string ch;
	API* Process = new API();
	isPossible=Process->searchByName(list,_toResetSales,TempList);
	if(isPossible)
	{
		int index;
		string ch;
		
		
				cout<<Process->listAll(TempList);
				cout<<"\nEnter the index of the product you want to reset: [Numbers only]";
				int flag=0;
				do{
					flag=0;
					//gotoxy(42,25);
					cin>>index;
					index--;
					if (cin.fail()||index>=TempList->getLength())
					{
						//gotoxy(0,29);
						error();
						cin.clear();
						cin.ignore(10,'\n');
						flag=1;
					}
					else
					{
						//gotoxy(0,30);
						cout<<"                                                         "<<endl;
					}
				}while(flag==1);

			

				do{
					//gotoxy(0,32);
					cout << "\nDo You Want To Reset the Sale Of This Product? (Y/N) ";
					cin >> ch;
					if(ch=="Y" || ch=="y")
					{
						//int _itemIndex;
						//_itemIndex=Result.at(index);
						//clock_t startTime = clock(); //Do this right before invoking the function
						if(Process->resetProductByIndex(TempList,index))
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 10);
							cout << "\nProduct Sales Reset\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
						else
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 12);
							cout << "\n\aUnable to Reset Product\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
					}
					else if(ch=="n" || ch=="N")
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << "\n\aProduct Not Modified\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
					else
						error();
				}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
		
	}
	else
		{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	system("pause");
	//delete Result;
	delete Process;
	delete TempList;
}
void interfaceIO:: resetSalesOneProductByBarcode(ListBase<Product>* list)
{
	string _toResetSales;
	Header();
	bool isPossible;
	 
	ListBase<Product>* TempList=new ListDA<Product>();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(37,18);
	cout<<"--------------------------------------"<<endl;
	gotoxy(37,19);
	cout<<"| RESETTING PRODUCT SALES BY BARCODE |"<<endl;
	gotoxy(37,20);
	cout<<"--------------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the barcode of product you want to reset: ";
	cin>> _toResetSales;
	string ch;
		API* Process = new API();
	isPossible=Process->searchByBarcode(list,_toResetSales,TempList);
	if(isPossible)
	{
		int index;
		string ch;
	
				cout<<Process->listAll(TempList);
				cout<<"Enter the index of the product you want to reset: [Numbers only]";
				int flag=0;
				do{
					flag=0;
					//gotoxy(42,25);
					cin>>index;
					index--;
					if (cin.fail()||index>=TempList->getLength())
					{
						//gotoxy(0,29);
						error();
						cin.clear();
						cin.ignore(10,'\n');
						flag=1;
					}
					else
					{
						//gotoxy(0,30);
						cout<<"                                                         "<<endl;
					}
				}while(flag==1);

			

				do{
					//gotoxy(0,32);
					cout << "\nDo You Want To Reset the Sale Of This Product? (Y/N) ";
					cin >> ch;
					if(ch=="Y" || ch=="y")
					{
						//int _itemIndex;
						//_itemIndex=Result.at(index);
						
						//clock_t startTime = clock(); //Do this right before invoking the function
						if(Process->resetProductByIndex(TempList,index))
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 10);
							cout << "\nProduct Sales Reset\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
						else
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 12);
							cout << "\n\aUnable to Reset Product\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
					}
					else if(ch=="n" || ch=="N")
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << "\n\aProduct Not Modified\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
					else
						error();
				}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
		
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	//call reset function from the operation class reset function
	system("pause");
	//delete Result;
	delete Process;
	delete TempList;
}

void interfaceIO::resetSalesAll(ListBase<Product>* list)
{
	Header();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(41,18);
	cout<<"-------------------------------"<<endl;
	gotoxy(41,19);
	cout<<"| RESETTING ALL SALES RECORDS |"<<endl;
	gotoxy(41,20);
	cout<<"-------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	string ch;
	API*  Process= new API();
	do{
		//gotoxy(0,32);
		cout << "\nDo you want to rest the sales of all product? (Y/N) ";
		cin >> ch;
		if(ch=="Y" || ch=="y")
		{
			//clock_t startTime = clock(); //Do this right before invoking the function
			if(Process->resetAll(list))
			{
				//clock_t endTime = clock();  //Do this right after the function returns
				//cout<<"Elapsed time:";
				//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "\nAll Product Sales Resetted to 0. \n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				//clock_t endTime = clock();  //Do this right after the function returns
				//cout<<"Elapsed time:";
				//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;	
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\aUnable to Reset Product sales\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			
		}
		else if(ch=="n" || ch=="N")
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\aProduct Sales Remain unchanged\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
			error();
	}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
	system("pause");
	delete Process;
	

}
void interfaceIO :: restockByName(ListBase<Product>* list)
{
	string _toRestock;
	int _quantity;
	bool isPossible;
	 
	ListBase<Product>* TempList=new ListDA<Product>();
	Header();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(41,18);
	cout<<"-------------------------------"<<endl;
	gotoxy(41,19);
	cout<<"| RESTOCKING PRODUCTS BY NAME |"<<endl;
	gotoxy(41,20);
	cout<<"-------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the name of product you want to restock: ";
	cin>> _toRestock;
	API* Process = new API();
	isPossible=Process->searchByName(list,_toRestock,TempList);
	if(isPossible)
	{
		int index;
		string ch;
		
				cout<<Process->listAll(TempList);
				cout<<"Enter the index of the product you want to restock [Numbers only]: ";
				int flag=0;
				do{
					flag=0;
					//gotoxy(42,25);
					cin>>index;
					index--;
					if (cin.fail()||index>=TempList->getLength())
					{
						//gotoxy(0,29);
						error();
						cin.clear();
						cin.ignore(10,'\n');
						flag=1;
					}
					else
					{
						//gotoxy(0,30);
						cout<<"                                                         "<<endl;
					}
				}while(flag==1);

				do{
							flag=0;
							cout<<"\nEnter the quantity you want to restock: ";
							cin>> _quantity;		if (cin.fail())
							{
							//	gotoxy(0,31);
								error();
								cin.clear();
								cin.ignore(10,'\n');
								flag=1;
							}
						}while(flag==1);
			

				do{
					//gotoxy(0,32);
					cout << "\nDo You Want To Restock This Product? (Y/N) ";
					cin >> ch;
					if(ch=="Y" || ch=="y")
					{
						//int _itemIndex;
						
						//_itemIndex=Result.at(index);
						//clock_t startTime = clock(); //Do this right before invoking the function
						if(Process->restockProductByIndex(TempList,index,_quantity))
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 10);
							cout << "\nProduct Quantity Restocked to"<<_quantity<<"\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
						else
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 12);
							cout << "\n\aUnable to Restock Product\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
					}
					else if(ch=="n" || ch=="N")
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << "\n\aProduct Not Modified\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
					else
						error();
				}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
		
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	//call restock function from the operation class restock function
	system("pause");
//	delete Result;
	delete Process;
	delete TempList;
	cin.ignore(10,'\n');

}
void interfaceIO :: restockByBarcode(ListBase<Product>* list)
{
	 
	string _toRestock;
	ListBase<Product>* TempList=new ListDA<Product>();
	int _quantity;
	bool isPossible;
	Header();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(39,18);
	cout<<"----------------------------------"<<endl;
	gotoxy(39,19);
	cout<<"| RESTOCKING PRODUCTS BY BARCODE |"<<endl;
	gotoxy(39,20);
	cout<<"----------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the barcode of product you want to restock: ";
	cin>> _toRestock;
	API* Process = new API();
	isPossible=Process->searchByBarcode(list,_toRestock,TempList);
	if(isPossible)
	{
		int index;
		string ch;
	
				cout<<Process->listAll(TempList);
				cout<<"Enter the index of the product you want to restock: [Numbers only]";
				int flag=0;
				do{
					flag=0;
					//gotoxy(42,25);
					cin>>index;
					index--;
					if (cin.fail()||index>=TempList->getLength())
					{
						//gotoxy(0,29);
						error();
						cin.clear();
						cin.ignore(10,'\n');
						flag=1;
					}
					else
					{
						//gotoxy(0,30);
						cout<<"                                                         "<<endl;
					}
				}while(flag==1);

			do{
							flag=0;
							cout<<"\nEnter the quantity you want to restock: ";
							cin>> _quantity;		if (cin.fail())
							{
							//	gotoxy(0,31);
								error();
								cin.clear();
								cin.ignore(10,'\n');
								flag=1;
							}
						}while(flag==1);

				do{
					//gotoxy(0,32);
					cout << "\nDo You Want To Restock This Product? (Y/N) ";
					cin >> ch;
					if(ch=="Y" || ch=="y")
					{
						//int _itemIndex;
						
						//_itemIndex=Result.at(index);
						
						//clock_t startTime = clock(); //Do this right before invoking the function
						if(Process->restockProductByIndex(TempList,index,_quantity))
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 10);
							cout << "\nProduct Quantity Restocked to"<<_quantity<<".\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
						else
						{
							//clock_t endTime = clock();  //Do this right after the function returns
							//cout<<"Elapsed time:";
							//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
							SetConsoleTextAttribute(hConsole, 12);
							cout << "\n\aUnable to Restock Product\n";
							SetConsoleTextAttribute(hConsole, 15);
						}
					}
					else if(ch=="n" || ch=="N")
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << "\n\aProduct Not Modified\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
					else
						error();
				}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
		
	}
	else
		{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	//call restock function from the operation class restock function
	system("pause");
	//delete Result;
	delete TempList;
	delete Process;
	cin.ignore(10,'\n');
}
void interfaceIO :: salesByName(ListBase<Product>* list)
{
	string _toSell;
	int _quantity;
	Header();
	ListBase<Product>* TempList=new ListDA<Product>();
	bool isPossible;
	 
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(39,18);
	cout<<"---------------------------------"<<endl;
	gotoxy(39,19);
	cout<<"| UPDATING SALES RECORD BY NAME |"<<endl;
	gotoxy(39,20);
	cout<<"---------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the name of product you want to sell: ";
	cin>> _toSell;
	API* Process = new API();
	isPossible=Process->searchByName(list,_toSell,TempList);
	if(isPossible)
	{
		int index;
		string ch;
		cout<<Process->listAll(TempList);
		cout<<"Enter the index of the product you want to sell: [Numbers only]";
		int flag=0;
		do{
					flag=0;
					//gotoxy(42,25);
					cin>>index;
					index--;
					if (cin.fail()||index>=TempList->getLength())
					{
						//gotoxy(0,29);
						error();
						cin.clear();
						cin.ignore(10,'\n');
						flag=1;
					}
					else
					{
						//gotoxy(0,30);
						cout<<"                                                         "<<endl;
					}
				}while(flag==1);

		do{
					flag=0;
					cout<<"\nEnter the quantity you want to sell: ";
					cin>> _quantity;		
					if (cin.fail())
					{
					//	gotoxy(0,31);
						error();
						cin.clear();
						cin.ignore(10,'\n');
						flag=1;
					}
			}while(flag==1);

		do{
					//gotoxy(0,32);
				cout << "\nDo You Want To amend Sales of this Product? (Y/N) ";
				cin >> ch;

				if(ch=="Y" || ch=="y")
				{
						//int _itemIndex;
						
						//_itemIndex=Result.at(index);
					

					//clock_t startTime = clock(); //Do this right before invoking the function
					if(Process->saleProductByIndex(TempList,index,_quantity))
					{
						//clock_t endTime = clock();  //Do this right after the function returns
						//cout<<"Elapsed time:";
						//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
						SetConsoleTextAttribute(hConsole, 10);
						cout << "\nProduct Sales Updated.\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
					else
					{
						//clock_t endTime = clock();  //Do this right after the function returns
						//cout<<"Elapsed time:";
						//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
						SetConsoleTextAttribute(hConsole, 12);
						cout << "\n\aUnable to Update Sale of Product. The quantity of products sold is more than that in stock.\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
				}
				else if(ch=="n" || ch=="N")
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "\n\aProduct Sales Not Modified.\n";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else
					error();
		}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
		
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	//call sell function from the operation class sell function
	system("pause");
	//delete Result;
	delete Process;
	delete TempList;
	cin.ignore(10,'\n');
}
void interfaceIO :: salesByBarcode(ListBase<Product>* list)
{
	int _quantity;
	string _toSell;
	Header();
	bool isPossible;
	ListBase<Product>* TempList=new ListDA<Product>();
	 
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(39,18);
	cout<<"----------------------------------"<<endl;
	gotoxy(39,19);
	cout<<"|UPDATING SALES RECORD BY BARCODE|"<<endl;
	gotoxy(39,20);
	cout<<"----------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the barcode of product you want to sell: ";
	cin>> _toSell;
			API* Process = new API();
	isPossible=Process->searchByBarcode(list,_toSell,TempList);
	if(isPossible)
	{
		int index;
		string ch;
		cout<<Process->listAll(TempList);
		cout<<"Enter the index of the product you want to sell: [Numbers only]";
		int flag=0;
		do{
			flag=0;
			//gotoxy(42,25);
			cin>>index;
			index--;
			if (cin.fail()||index>=TempList->getLength())
			{
					//gotoxy(0,29);
				error();
				cin.clear();
				cin.ignore(10,'\n');
				flag=1;
			}
			else
			{
				//gotoxy(0,30);
				cout<<"                                                         "<<endl;
			}
		}while(flag==1);
		do{
				flag=0;
				cout<<"\nEnter the quantity you want to sell: ";
				cin>> _quantity;		if (cin.fail())
				{
				//	gotoxy(0,31);
					error();
					cin.clear();
					cin.ignore(10,'\n');
					flag=1;
				}
			}while(flag==1);
		

		do{
					//gotoxy(0,32);
				cout << "\nDo you want To amend sales of this product? (Y/N) ";
				cin >> ch;
				if(ch=="Y" || ch=="y")
				{
						//int _itemIndex;
						
						//_itemIndex=Result.at(index);
					//clock_t startTime = clock(); //Do this right before invoking the function
					if(Process->saleProductByIndex(TempList,index,_quantity))
					{
						//clock_t endTime = clock();  //Do this right after the function returns
						//cout<<"Elapsed time:";
						//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
						SetConsoleTextAttribute(hConsole, 10);
						cout << "\nProduct Sales Updated.\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
					else
					{
						//clock_t endTime = clock();  //Do this right after the function returns
						//cout<<"Elapsed time:";
						//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
						SetConsoleTextAttribute(hConsole, 12);
						cout << "\n\aUnable to update Sales of Product. The quantity of products sold is more than that in stock.\n";
						SetConsoleTextAttribute(hConsole, 15);
					}
				}
				else if(ch=="n" || ch=="N")
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "\n\aProduct Sales Not Modified.\n";
					SetConsoleTextAttribute(hConsole, 15);
				}
				else
					error();
		}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
		
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	//call sell function from the operation class sell function
	system("pause");
//	delete Result;
	delete Process;
	cin.ignore(10,'\n');
	delete TempList;
}
void interfaceIO :: topXProducts(ListBase<Product>* list)
{
	int _X;
	string output;
	Header();
	ListBase<Product>* TempList= new ListDA<Product>();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(41,18);
	cout<<"-----------------------------"<<endl;
	gotoxy(41,19);
	cout<<"| GENERATING TOP X PRODUCTS |"<<endl;
	gotoxy(41,20);
	cout<<"-----------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	int flag=0;
	do{
		flag=0;
		cout<<"\nEnter the value of X: ";
		cin>> _X;
		if (cin.fail()|| _X>list->getLength())
		{
		//	gotoxy(0,31);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
	}while(flag==1);

		
	API*  Process= new API();
	//clock_t startTime = clock(); //Do this right before invoking the function
	if(Process->topX(list, _X,TempList))
	{
		//bool success;
		SetConsoleTextAttribute(hConsole, 10);
		cout<<"Top X Products are:"<<endl;
			

		SetConsoleTextAttribute(hConsole, 15);
		cout<<Process->listAll(TempList);

		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		
	}
	else
	{
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"This Statistics cannot be displayed"<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	delete Process;
	delete TempList;
	//Draw chart function*/
	system("pause");
	
	cin.ignore(10,'\n');
}
void interfaceIO ::topProductInCategory(ListBase<Product>* list)
{
	string _category, output;
	Header();
//	bool isPossible;
	ListBase<Product>* TempList=new ListDA<Product>();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(35,18);
	cout<<"----------------------------------------"<<endl;
	gotoxy(35,19);
	cout<<"| GENERATING TOP PRODUCT IN A CATEGORY |"<<endl;
	gotoxy(35,20);
	cout<<"----------------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cin.ignore(10,'\n');
	cout<<"\nEnter the category whose top product you want: ";
	getline(cin,_category);
	API*  Process= new API();
	//clock_t startTime = clock(); //Do this right before invoking the function
	if(Process->bestInCategory(list, _category,TempList))
	{
		SetConsoleTextAttribute(hConsole, 10);
		cout<<"Best Product in "<<_category<<" is: ";
		
		SetConsoleTextAttribute(hConsole, 15);
		cout<<TempList->retrieveItem(0)->get_name()<<".";
		cout<<"\n";
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		//cout<<Process->listAll(TempList);
	}
	else
	{
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"This Statistics is not available for the category you entered.\n"<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	delete TempList;
	delete Process;
	system("pause");
}
void interfaceIO ::topManufacturer(ListBase<Product>* list)
{
	string _manufacturer, output;
	Header();
	ListBase<Product>* TempList= new ListDA<Product>();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(40,18);
	cout<<"-------------------------------"<<endl;
	gotoxy(40,19);
	cout<<"| GENERATING TOP MANUFACTURER |"<<endl;
	gotoxy(40,20);
	cout<<"-------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	API*  Process= new API();
	//clock_t startTime = clock(); //Do this right before invoking the function
	if(Process->bestManufacturer(list, TempList))
	{

		SetConsoleTextAttribute(hConsole, 10);
		cout<<"Top Manufacturer is:"<<TempList->retrieveItem(0)->get_manufacturer()<<endl;
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		//cout<<Process->listAll(TempList);
	}
	else
	{
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"This Statistics is not available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	
	delete TempList;
	delete Process;
	system("pause");
}

void interfaceIO :: loadData(ListBase<Product>* List)
{
	bool success;
	system("CLS");
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED |15 );
	cout<<"\n--------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|                       CEG  Hypermarket  Inventory  Control  and  Monitoring  System                              |"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	API* Process= new API();
	//clock_t startTime = clock(); 
	success=Process->loadData(List);
	//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	if (success)
		cout<<"Data successfuly loaded."<<endl;
	else
		cout<<"Unable to load data from file."<<endl;
	delete Process;
	system("pause");
}
void interfaceIO :: checkExpiryByName(ListBase<Product>* list)
{

	string _toCheck;
	Header();
	bool isPossible;
	 

	ListBase<Product>* TempList=new ListDA<Product>();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(30,18);
	cout<<"---------------------------------------------------"<<endl;
	gotoxy(30,19);
	cout<<"| CHECK EXPIRY DATE OF PERISHABLE PRODUCT BY NAME |"<<endl;
	gotoxy(30,20);
	cout<<"---------------------------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the name of product you want to check expiry of: ";
	cin>>_toCheck;
	API*  Process= new API();
	isPossible=Process->searchByName(list,_toCheck,TempList);
	if (isPossible)
	{
		int index;
		string ch;
		
				//for (int i=0;i<Result.size();i++)
					//cout<<Result.at(i);
		cout<<Process->listAll(TempList);
		cin.ignore(10,'\n');
		cout<<"Enter the index of the product you want to check: [Numbers only]";
		int flag=0;
		do{
				flag=0;
					//gotoxy(42,25);
				cin>>index;
				index=index-1;
				if (cin.fail()||index>TempList->getLength())
				{
					//gotoxy(0,29);
					error();
					cin.clear();
					cin.ignore(10,'\n');
					flag=1;
				}
				else
				{
					//gotoxy(0,30);
					cout<<"                                                         "<<endl;
				}
		}while(flag==1);
				//int _itemIndex;
				//IMPORTANTTTTTT
				//_itemIndex =Result.at(index);
				//int abc=Result.at(5);
				//if(_itemIndex!=NULL)
		int flag2;
		//clock_t startTime = clock(); //Do this right before invoking the function
		cout<<"The expiry date of "<<TempList->retrieveItem(index)->get_name()<<" product is: "<<Process->checkExpiryByIndex(TempList,index,flag2)<<endl;
		if (flag2==0)
		{
			//clock_t endTime = clock();  //Do this right after the function returns
			//cout<<"Elapsed time:";
			//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
			SetConsoleTextAttribute(hConsole, 12);
			cout<<"\nThe product has already expired."<<endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
		else if(flag2==1)
		{
			//clock_t endTime = clock();  //Do this right after the function returns
			//cout<<"Elapsed time:";
			//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
			SetConsoleTextAttribute(hConsole, 10);
			cout<<"\nThe product has not expired yet."<<endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
					
				//else
					//error();
		
	}
	else
	{
			
			SetConsoleTextAttribute(hConsole, 12);
			cout<<"Product is not found."<<endl;
			SetConsoleTextAttribute(hConsole, 15);
		
	}
	//delete Result;
	delete Process;
	delete TempList;
	system("pause");
}
void interfaceIO :: checkExpiryByBarcode(ListBase<Product>* list)
{
	string _toCheck;
	Header();
	bool isPossible;
	 
	ListBase<Product>* TempList=new ListDA<Product>();
	//system("color 4F");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(29,18);
	cout<<"------------------------------------------------------"<<endl;
	gotoxy(29,19);
	cout<<"| CHECK EXPIRY DATE OF PERISHABLE PRODUCT BY BARCODE |"<<endl;
	gotoxy(29,20);
	cout<<"------------------------------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\nEnter the Barcode of product you want to check expiry of: ";
	cin>>_toCheck;
	//call check function
		API*  Process= new API();
	isPossible=Process->searchByBarcode(list,_toCheck,TempList);
	if (isPossible)
	{
		int index;
		string ch;
		
		cout<<Process->listAll(TempList);
		cin.ignore(10,'\n');
		cout<<"Enter the index of the product you want to check: [Numbers only]";
		int flag=0;
		do{
			flag=0;
				//gotoxy(42,25);
			cin>>index;
			index=index-1;
			if (cin.fail()||index>=TempList->getLength())
			{
				//gotoxy(0,29);
				error();
				cin.clear();
				cin.ignore(10,'\n');
				flag=1;
			}
			else
			{
				//gotoxy(0,30);
				cout<<"                                                         "<<endl;
			}
		}while(flag==1);
			//	int _itemIndex;
				//_itemIndex=Result.at(index);
		int flag2;
		//clock_t startTime = clock(); //Do this right before invoking the function
		cout<<"The expiry date of "<<TempList->retrieveItem(index)->get_name()<<" product is: "<<Process->checkExpiryByIndex(TempList,index,flag2)<<endl;
		if (flag2==0)
		{
			//clock_t endTime = clock();  //Do this right after the function returns
			//cout<<"Elapsed time:";
			//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
			SetConsoleTextAttribute(hConsole, 12);
			cout<<"\nThe product has already expired."<<endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
		else if(flag2==1)
		{
			//clock_t endTime = clock();  //Do this right after the function returns
			//cout<<"Elapsed time:";
			//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
			SetConsoleTextAttribute(hConsole, 10);
			cout<<"\nThe product has not expired yet."<<endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
			//	else
				//	error();
		
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"Product is not found."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	delete TempList;
//	delete Result;
	delete Process;
	system("pause");
}
void interfaceIO :: addNormal(ListBase<Product>* list)
{
	int _stock,_sold;
	double _tempPrice;
	string _tempName, _tempBarcode, _tempManufacturer,_tempCategory;
	Header();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(36,18);
	cout<<"---------------------------"<<endl;
	gotoxy(36,19);
	cout<<"| ADDING A NORMAL PRODUCT |"<<endl;
	gotoxy(36,20);
	cout<<"---------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\n1. Enter Product name: "<<endl;
	cout<<"2. Enter Product category: "<<endl;
	cout<<"3. Enter Product barcode: "<<endl;
	cout<<"4. Enter Product price: "<<endl;
	cout<<"5. Enter Product manufacturer: "<<endl;
	cout<<"6. Enter the number of stock available: "<<endl;
	cout<<"7. Enter the number of sales per month: "<<endl;
	gotoxy(42,22);
	getchar();
	getline(cin,_tempName);
	gotoxy(42,23);
	//getchar();//inputbuffer
	getline(cin,_tempCategory);
	int flag2=0;
	do{
		flag2=0;
	gotoxy(42,24);
	//getchar();
	getline(cin,_tempBarcode);
	API* Process=new API();
	ListBase<Product>* Result=new ListDA<Product>();
	Process->searchByBarcode(list,_tempBarcode,Result);
	if (!Result->isEmpty())
	{
		gotoxy(0,29);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
	
		cout<<"\n\aBarcode already exists. Please enter a different barcode."<<endl;

		SetConsoleTextAttribute(hConsole, 15);
		flag2=1;
	}
	else 
	{
		gotoxy(0,30);
			cout<<"                                                         "<<endl;
	}
	delete Process;
	delete Result;
	}while(flag2==1);
	
	int flag=0;
	do{
		flag=0;
		gotoxy(42,25);
		cin>>_tempPrice;
		if (cin.fail())
		{
			gotoxy(0,29);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,30);
			cout<<"                                                         "<<endl;
			}
	}while(flag==1);
	gotoxy(42,26);
	getchar();
	getline(cin,_tempManufacturer);
	do{
		flag=0;
		gotoxy(42,27);
		cin>>_stock;
		if (cin.fail())
		{
			gotoxy(0,29);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,30);
			cout<<"                                                         "<<endl;
		}
	}while(flag==1);
	
	do{
		flag=0;
		gotoxy(42,28);
		cin>>_sold;
		if (cin.fail())
		{
			gotoxy(0,29);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,30);
			cout<<"                                                         "<<endl;
		}
		
	}while(flag==1);
	//call constructor function from functionality class and return whether the data transfer successful or not
	string ch;
	do{
			//gotoxy(0,32);
		cout<<"Name         :"<<_tempName<<endl;
		cout<<"Category     :"<<_tempCategory<<endl;
		cout<<"Barcode      :"<<_tempBarcode<<endl;
		cout<<"Price        :"<<_tempPrice<<endl;
		cout<<"Manufacturer :"<<_tempManufacturer<<endl;
		cout<<"Stock        :"<<_stock<<endl;
		cout<<"Sales        :"<<_sold<<endl;
	

		cout << "\nDo You Want To Add This Product? (Y/N) ";
		cin >> ch;
		if(ch=="Y" || ch=="y")
		{
			API * Process= new API();
			//clock_t startTime = clock(); //Do this right before invoking the function	
			if(Process->addProduct(list,_tempName, _tempCategory,_tempBarcode,_tempManufacturer, _tempPrice,_stock,_sold))
			{
				//clock_t endTime = clock();  //Do this right after the function returns
				//cout<<"Elapsed time:";
				//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
				 SetConsoleTextAttribute(hConsole, 10);
				 cout << "\nProduct Added\n";
				 SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				//clock_t endTime = clock();  //Do this right after the function returns
				//cout<<"Elapsed time:";
				//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\aUnable to Add Product\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			delete Process;
		}
		else if(ch=="n" || ch=="N")
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\aProduct Not Added\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
			error();
	}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
	
	system("pause");
}
void interfaceIO:: listAllPerishable(ListBase<Product>* list)
{
	string output;
	Header();
	 
//	Result= new CircularDoubleLinkedList<int>;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(40,18);
	cout<<"-----------------------------------"<<endl;
	gotoxy(40,19);
	cout<<"| LISTING ALL PERSHIABLE PRODUCTS |"<<endl;
	gotoxy(40,20);
	cout<<"-----------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	API*  Process= new API();
	cout<<Process->listPerishable(list);/*
	if(Process->listPerishable(list))
	{	
		SetConsoleTextAttribute(hConsole, 10);
		cout<<"There are results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"There are no results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}*/
	//delete Result;
	delete Process;
	system("pause");
}
void interfaceIO::listAll(ListBase<Product>* list)
{
	string output;
	Header();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(44,18);
	cout<<"------------------------"<<endl;
	gotoxy(44,19);
	cout<<"| LISTING ALL PRODUCTS |"<<endl;
	gotoxy(44,20);
	cout<<"------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	API*  Process= new API();
	cout<<Process->listAll(list);
	/*if(Process->listAll(list))
	{	
		SetConsoleTextAttribute(hConsole, 10);
		cout<<"There are results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"There are no results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}*/

	delete Process;
	system("pause");
}

void interfaceIO::listAllNormal(ListBase<Product>* list)
{
	string output;
	Header();
	 
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(42,18);
	cout<<"-------------------------------"<<endl;
	gotoxy(42,19);
	cout<<"| LISTING ALL NORMAL PRODUCTS |"<<endl;
	gotoxy(42,20);
	cout<<"-------------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	API*  Process= new API();
	cout <<Process->listNormal(list);
	/*if(Process->listNormal(list))
	{	
		SetConsoleTextAttribute(hConsole, 10);
		cout<<"There are results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"There are no results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}*/
	//delete Result;
	delete Process;
	system("pause");
}
void interfaceIO:: addPerishable(ListBase<Product>* list)
{
	int _stock,_sold;
	double _tempPrice,_discount;
	string _tempName, _tempBarcode, _tempManufacturer,_tempCategory,_tempExpiry;
	Header();
	API* Process=new API();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(42,18);
	cout<<"-----------------------------"<<endl;
	gotoxy(42,19);
	cout<<"| ADDING PERISHABLE PRODUCT |"<<endl;
	gotoxy(42,20);
	cout<<"-----------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout<<"\n1. Enter Product name: "<<endl;
	cout<<"2. Enter Product category: "<<endl;
	cout<<"3. Enter Product barcode: "<<endl;
	cout<<"4. Enter Product price: "<<endl;
	cout<<"5. Enter Product manufacturer: "<<endl;
	cout<<"6. Enter the number of stock available: "<<endl;
	cout<<"7. Enter the number of sales per month: "<<endl;
	cout<<"8. Enter the expiry date: [DDMMYYYY]"<<endl;
	cout<<"9. Enter the product discount rate: "<<endl;
	gotoxy(42,22);
	getchar();
	getline(cin,_tempName);
	gotoxy(42,23);
	//getchar();//inputbuffer
	getline(cin,_tempCategory);
	//gotoxy(42,24);
	//getchar();
	int flag2=0;
	do{
		flag2=0;
	gotoxy(42,24);
	//getchar();
	getline(cin,_tempBarcode);
	
	ListBase<Product>* Result=new ListDA<Product>();
	Process->searchByBarcode(list,_tempBarcode,Result);
	if (!Result->isEmpty())
	{
		gotoxy(0,31);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
	
		cout<<"\n\aBarcode already exists. Please enter a different barcode."<<endl;

		SetConsoleTextAttribute(hConsole, 15);
		flag2=1;
	}
	else 
	{
		gotoxy(0,32);
			cout<<"                                                         "<<endl;
	}
	
	delete Result;
	}while(flag2==1);
	int flag=0;
	do{
		flag=0;
		gotoxy(42,25);
		cin>>_tempPrice;
		if (cin.fail())
		{
			gotoxy(0,31);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,32);
			cout<<"                                                         "<<endl;
			}
	}while(flag==1);
	gotoxy(42,26);
	getchar();
	getline(cin,_tempManufacturer);
	do{
		flag=0;
		gotoxy(42,27);
		cin>>_stock;
		if (cin.fail())
		{
			gotoxy(0,31);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,32);
			cout<<"                                                         "<<endl;
		}
	}while(flag==1);
	
	do{
		flag=0;
		gotoxy(42,28);
		cin>>_sold;
		if (cin.fail())
		{
			gotoxy(0,31);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,32);
			cout<<"                                                         "<<endl;
		
		}
	}while(flag==1);
	
	
	int counter=0;
	do{
		flag=0;
	gotoxy(42,29);
	if (counter==0)
		getchar();
	counter++;
	//cin.ignore(1);
	_tempExpiry="";
	getline(cin,_tempExpiry);
	
	if (_tempExpiry.length()!=8)
		{
			gotoxy(0,31);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,32);
			cout<<"                                                         "<<endl;
			
		
	int m = atoi(_tempExpiry.substr(2,2).c_str());
	int d = atoi(_tempExpiry.substr(0,2).c_str());
	int y = atoi(_tempExpiry.substr(4,4).c_str());
	if (!Process->checkdate(m,d,y))
		{
			gotoxy(0,31);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,32);
			cout<<"                                                         "<<endl;
			
	}
	}
	}while(flag==1);
	
	
	
	do{
		flag=0;
		gotoxy(42,30);
		cin>>_discount;
		if (cin.fail()||_discount>100)
		{
			gotoxy(0,31);
			error();
			cin.clear();
			cin.ignore(10,'\n');
			flag=1;
		}
		else
		{
			gotoxy(0,32);
			cout<<"                                                         "<<endl;
		
		}
	}while(flag==1);
	string ch;
	do{
		//gotoxy(0,32);
		cout<<"Name         :"<<_tempName<<endl;
		cout<<"Category     :"<<_tempCategory<<endl;
		cout<<"Barcode      :"<<_tempBarcode<<endl;
		cout<<"Price        :"<<_tempPrice<<endl;
		cout<<"Manufacturer :"<<_tempManufacturer<<endl;
		cout<<"Stock        :"<<_stock<<endl;
		cout<<"Sales        :"<<_sold<<endl;
		cout<<"ExpiryDate   :"<<_tempExpiry<<endl;
		cout<<"Discount %   :"<<_discount<<endl;


		cout << "\nDo You Want To Add This Product? (Y/N) ";
		cin >> ch;
		if(ch=="Y" || ch=="y")
		{
			
			//clock_t startTime = clock(); //Do this right before invoking the function
			if(Process->addPerishableProduct(list,_tempName, _tempCategory,_tempBarcode,_tempManufacturer, _tempPrice,_stock,_sold,_tempExpiry,_discount))
			{
				//clock_t endTime = clock();  //Do this right after the function returns
				//cout<<"Elapsed time:";
				//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "\nProduct Added\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				//clock_t endTime = clock();  //Do this right after the function returns
				//cout<<"Elapsed time:";
				//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\aUnable to Add Product\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		else if(ch=="n" || ch=="N")
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\aProduct Not Added\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
			error();
	}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
system("Pause");
delete Process;
}


void interfaceIO:: searchByName(ListBase<Product>* list)
{
	string _toSearch;
	Header();
	bool isPossible;
	 
	ListBase<Product>* TempList=new ListDA<Product>();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(47,18);
	cout<<"------------------"<<endl;
	gotoxy(47,19);
	cout<<"| SEARCH BY NAME |"<<endl;
	gotoxy(47,20);
	cout<<"------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//system("color 4F");

	cout<<"\nEnter the name of product you want to search: ";
	cin>> _toSearch;
	API*  Process= new API();
	//clock_t startTime = clock(); //Do this right before invoking the function
	isPossible=Process->searchByName(list, _toSearch,TempList);
	if(isPossible)
	{
		
			SetConsoleTextAttribute(hConsole, 15);
			
			//clock_t endTime = clock();  //Do this right after the function returns
			//cout<<"Elapsed time:";
			//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
			cout<<Process->listAll(TempList);
		}
		else
		{
			//clock_t endTime = clock();  //Do this right after the function returns
			//cout<<"Elapsed time:";
			//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
			SetConsoleTextAttribute(hConsole, 12);
			cout<<"There are no results available."<<endl;
			SetConsoleTextAttribute(hConsole, 15);
		}
	
	//call reset function from the operation class reset function
	//delete Result;
	delete Process;

	system("pause");
	delete TempList;
}
void interfaceIO:: searchByCategory(ListBase<Product>*list)
{
	string _toSearch;
	Header();
	bool isPossible;
	 
	ListBase<Product>* TempList=new ListDA<Product>();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(45,18);
	cout<<"----------------------"<<endl;
	gotoxy(45,19);
	cout<<"| SEARCH BY CATEGORY |"<<endl;
	gotoxy(45,20);
	cout<<"----------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//system("color 4F");
	cout<<"\nEnter the category of products you want to search: ";
	cin>> _toSearch;
	//call reset function from the operation class reset function
	API*  Process= new API();
	//clock_t startTime = clock(); //Do this right before invoking the function
	isPossible=Process->searchByCategory(list, _toSearch,TempList);
	if(isPossible)
	{
		SetConsoleTextAttribute(hConsole, 15);
		
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		cout<<Process->listAll(TempList);
	}
	else
	{
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"There are no results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	delete Process;
	delete TempList;
	system("pause");
}
void interfaceIO:: searchByBarcode(ListBase<Product>* list)
{
	string _toSearch,output;
	Header();
	bool isPossible;
	 
	ListBase<Product>* TempList=new ListDA<Product>();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(45,18);
	cout<<"---------------------"<<endl;
	gotoxy(45,19);
	cout<<"| SEARCH BY BARCODE |"<<endl;
	gotoxy(45,20);
	cout<<"---------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//system("color 4F");
	cout<<"\nEnter the barcode of product you want to search: ";
	cin>> _toSearch;
	API*  Process= new API();
	//clock_t startTime = clock(); //Do this right before invoking the function
	isPossible=Process->searchByBarcode(list, _toSearch,TempList);
	if(isPossible)
	{
		SetConsoleTextAttribute(hConsole, 15);
		
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		cout<<Process->listAll(TempList);
	}
	else
	{
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		//cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"There are no results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	
	//call reset function from the operation class reset function
	delete Process;
	delete TempList;
	system("pause");
}
void interfaceIO:: searchByManufacturer(ListBase<Product>* list)
{
	string _toSearch,output;
	Header();
//	bool isPossible;
	 
	ListBase<Product>* TempList=new ListDA<Product>();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(43,18);
	cout<<"--------------------------"<<endl;
	gotoxy(43,19);
	cout<<"| SEARCH BY MANUFACTURER |"<<endl;
	gotoxy(43,20);
	cout<<"--------------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//system("color 4F");
	cout<<"\nEnter the manufacturer of products you want to search: ";
	cin>> _toSearch;
	API*  Process= new API();
	////clock_t startTime = clock(); //Do this right before invoking the function
	if(Process->searchByManufacturer(list, _toSearch,TempList))
	{
		SetConsoleTextAttribute(hConsole, 15);
		
		//clock_t endTime = clock();  //Do this right after the function returns
		////cout<<"Elapsed time:";
		////cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		cout<<Process->listAll(TempList);
	}
	else
	{
		//clock_t endTime = clock();  //Do this right after the function returns
		//cout<<"Elapsed time:";
		////cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout<<"There are no results available."<<endl;
		SetConsoleTextAttribute(hConsole, 15);
	}
	//call reset function from the operation class reset function
	system("pause");
	delete Process;
	delete TempList;
	//delete Result;
}


void interfaceIO::saveData(ListBase<Product>* list)
{
	
	Header();
		 
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(46,18);
	cout<<"-------------"<<endl;
	gotoxy(46,19);
	cout<<"| SAVE DATA |"<<endl;
	gotoxy(46,20);
	cout<<"-------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//system("color 4F");
	string ch;	
	cout << "\nDo You Want To Save the Inventory to a file? (Y/N) ";
		
	do{
		cin >> ch;
		if(ch=="Y" || ch=="y")
		{
			API* Process=new API();
			//clock_t startTime = clock(); //Do this right before invoking the function
			if(Process->writeData(list))
			{
				//clock_t endTime = clock();  //Do this right after the function returns
				//cout<<"Elapsed time:";
				////cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "\nData Saved to File succesfully.\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				//clock_t endTime = clock();  //Do this right after the function returns
				//cout<<"Elapsed time:";
				////cout<<((double)(endTime-startTime))/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\aUnable to Save data to File.\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			delete Process;
		}
		else if(ch=="n" || ch=="N")
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\aSaving data to file cancelled.\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
			error();
		
	}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");
	

	//call reset function from the operation class reset function
	system("pause");
	
	//delete Result;
}

void interfaceIO::Quit(ListBase<Product>* list)
{
	
	Header();
		 
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(46,18);
	cout<<"------------"<<endl;
	gotoxy(46,19);
	cout<<"| Quitting |"<<endl;
	gotoxy(46,20);
	cout<<"------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//system("color 4F");
	string ch;

	cout << "\nDo You Want To Save the Inventory to a file before quitting? (Y/N) ";
	
	do{
		cin.clear();
		cin>>ch;
		if(ch=="Y" || ch=="y")
		{
			API* Process=new API();
			if(Process->writeData(list))
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << "\nData Saved to File succesfully.\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\aUnable to Save data to File.\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			delete Process;
		}
		else if(ch=="n" || ch=="N")
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\aSaving data to file cancelled.\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
			error();
	}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");

	//call reset function from the operation class reset function
	//system("pause");
	
	//delete Result;
}

void interfaceIO::BatchProcessing(ListBase<Product>* list)
{
	
	Header();
		 
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(40,18);
	cout<<"-------------------"<<endl;
	gotoxy(40,19);
	cout<<"| Batch Processing |"<<endl;
	gotoxy(40,20);
	cout<<"--------------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//system("color 4F");
	string ch;

	cout << "\nDo You Want To Process the Batch Jobs? (Y/N) ";
	
	do{
		cin.clear();
		cin>>ch;
		if(ch=="Y" || ch=="y")
		{
			API* Process=new API();
			if(Process->batchProcess(list))
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << "\nBatch of Jobs processed successfully. Visit the error log for errors.\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\aUnable to process Batch of Jobs data to File.\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			delete Process;
		}
		else if(ch=="n" || ch=="N")
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\aBatch Processing Cancelled.\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
			error();
	}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");

	//call reset function from the operation class reset function
	system("pause");
	
	//delete Result;
}

/*
void interfaceIO::loadData(ListBase<Product>* list)
{
	
	Header();
		 
	
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	gotoxy(43,18);
	cout<<"-------------"<<endl;
	gotoxy(43,19);
	cout<<"| LOAD DATA |"<<endl;
	gotoxy(43,20);
	cout<<"-------------"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//system("color 4F");
	string ch;	
	cout << "\nDo You Want To load the Inventory from file? (Y/N) ";
		cin >> ch;
		do{
	if(ch=="Y" || ch=="y")
		{
			API* Process=new API();
			if(Process->loadData(list))
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << "\nData Saved to File succesfully.\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "\n\aUnable to Save data to File.\n";
				SetConsoleTextAttribute(hConsole, 15);
			}
		}
		else if(ch=="n" || ch=="N")
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\n\aSaving data to file cancelled.\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else
			error();
	}while(ch!="y" && ch!="Y" && ch!="n" && ch!="N");

	//call reset function from the operation class reset function
	//system("pause");
	
	//delete Result;
}*/