

#include "Menus.h"


void Menus::Header()
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
int Menus::UserChoice()
{
	int choice;
	//cin.ignore(10,'\n');
	cout<<endl;

	cout<<"Please choose an option by entering a number: ";
	cin>>choice;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(10,'\n');
		return -1;

	}

	return choice;
}
/*
void interfaceIO::error()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "\n\aWrong Input!! Please Enter Again.\n\n";
		SetConsoleTextAttribute(hConsole, 15);
	}*/
void Menus :: gotoxy(int x, int y) //goes to x,y console
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Menus::MainMenu()

{
	Header();
	SetConsoleTextAttribute(hConsole, 15);
	
	gotoxy(48,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"*******************"<<endl;
	gotoxy(48,19);
	cout<<"|    MAIN MENU    |"<< endl;
	gotoxy(48,20);
	cout<<"*******************"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	
	gotoxy(32,22);
	cout<<" 1. Add/Delete product "<<endl;
	gotoxy(58,22);
	cout<<" 2. Manage Sales       "<<endl;
	gotoxy(32,24);
	cout<<" 3. Restock products   "<<endl;
	gotoxy(58,24);
	cout<<" 4. Generate Statistics"<<endl;
	gotoxy(32,26);
	cout<<" 5. List All Products  "<<endl;
	gotoxy(58,26);
	cout<<" 6. Search Products    "<<endl;
	gotoxy(32,28);
	cout<<" 7. Check Expiry Date  "<<endl;
	//cout<<"8. Load data"<<endl;
	//cout<<"9. Check product expiry date"<<endl;
	gotoxy(58,28);
	cout<<" 8. Save Data          "<<endl;
	
	gotoxy(32,30);
	cout<<" 9. Batch Processing   "<<endl;
	gotoxy(58,30);
	cout<<" 0. Quit               "<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	
	
}

void Menus:: SubMenuAdd_Del()
{
	Header();
	gotoxy(42,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"**********************************"<<endl;
	gotoxy(42,19);
	cout<<"|    ADD/ DELETE PRODUCT MENU    |"<< endl;
	gotoxy(42,20);
	cout<<"**********************************"<<endl;
	
		//cout<<"ADD/ DELETE PRODUCT MENU"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);

	gotoxy(20,22);
	cout<<" 1. Add Product        "<<endl;
	gotoxy(45,22);
	cout<<" 2. Delete Product     "<<endl;
	gotoxy(70,22);
	cout<<" 0. Return to Main Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void Menus:: SubMenuAdd()
{
	Header();
	gotoxy(46,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"**************************"<<endl;
	gotoxy(46,19);
	cout<<"|    ADDING A PRODUCT    |"<< endl;
	gotoxy(46,20);
	cout<<"**************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
		//cout<<"ADDING A PRODUCT"<<endl;
	cout<<"\nChoose Product type to Add:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(32,24);
	cout<<" 1. Perishable Products    "<<endl;
	gotoxy(60,24);
	cout<<" 2. Non-Perishable Products"<<endl;
	gotoxy(32,26);
	cout<<" 3. Previous Menu          "<<endl;
	gotoxy(60,26);
	cout<<" 0. Return to Main Menu    "<<endl;
	SetConsoleTextAttribute(hConsole, 15);

}

void Menus:: SubMenuDelete()
{
	Header();
	gotoxy(45,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"****************************"<<endl;
	gotoxy(45,19);
	cout<<"|    DELETING A PRODUCT    |"<< endl;
	gotoxy(45,20);
	cout<<"****************************"<<endl;
	//cout<<""<<endl;
	SetConsoleTextAttribute(hConsole,15);
	cout<<"\nChoose how do you want to search product to delete:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(32,24);
	cout<<" 1. Search by name      "<<endl;
	gotoxy(60,24);
	cout<<" 2. Search by barcode   "<<endl;
	gotoxy(32,26);
	cout<<" 3. Previous Menu       "<<endl;
	gotoxy(60,26);
	cout<<" 0. Return to Main Menu "<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
	
void Menus:: SubMenuRestock()
{
	Header();
	gotoxy(46,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"***************************"<<endl;
	gotoxy(46,19);
	cout<<"|    RESTOCK A PRODUCT    |"<< endl;
	gotoxy(46,20);
	cout<<"***************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//	cout<<""<<endl;
	cout<<"\nChoose how do you want to search products to restock:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(20,24);
	cout<<" 1. Search by name     "<<endl;
	gotoxy(45,24);
	cout<<" 2. Search by barcode  "<<endl;
		//cout<<"3. Previous"<<endl;
	gotoxy(70,24);
	cout<<" 0. Return to Main Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void Menus:: SubMenuSales_Reset()
{
	Header();
	gotoxy(47,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"************************"<<endl;
	gotoxy(47,19);
	cout<<"|    MANAGING SALES    |"<< endl;
	gotoxy(47,20);
	cout<<"************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
		//cout<<""<<endl;
	cout<<"\nChoose whether you want update sales or reset them:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(20,24);
	cout<<" 1. Update Sales       "<<endl;
	gotoxy(45,24);
	cout<<" 2. Reset Sales        "<<endl;
	gotoxy(70,24);
	cout<<" 0. Return to Main Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
void Menus:: SubMenuSales()
{
	Header();
	gotoxy(44,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"*******************************"<<endl;
	gotoxy(44,19);
	cout<<"|    UPDATING SALES RECORD    |"<< endl;
	gotoxy(44,20);
	cout<<"*******************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
		//cout<<""<<endl;
	cout<<"\nChoose how do you want to search product to update sales:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(35,24);
	cout<<" 1. Search by name     "<<endl;
	gotoxy(60,24);
	cout<<" 2. Search by barcode  "<<endl;
	gotoxy(35,26);
	cout<<" 3. Previous Menu      "<<endl;
	gotoxy(60,26);
	cout<<" 0. Return to Main Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
void Menus:: SubMenuReset()
{
	Header();
	gotoxy(44,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"*************************"<<endl;
	gotoxy(44,19);
	cout<<"|    RESETTING SALES    |"<< endl;
	gotoxy(44,20);
	cout<<"*************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
		//cout<<""<<endl;
	cout<<"\nChoose whether you want to reset sales of all products or one of them:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(33,24);
	cout<<" 1. Reset All          "<<endl;
	gotoxy(58,24);
	cout<<" 2. Reset One Product  "<<endl;
	gotoxy(33,26);
	cout<<" 3. Previous Menu      "<<endl;
	gotoxy(58,26);
	cout<<" 0. Return to Main Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
void Menus:: SubMenuResetOne()
{
	Header();
	gotoxy(40,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"**************************************"<<endl;
	gotoxy(40,19);
	cout<<"|    RESETTING SALES OF A PRODUCT    |"<< endl;
	gotoxy(40,20);
	cout<<"**************************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
		//cout<<""<<endl;
	cout<<"\nChoose how do you want to search product to reset sales:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(35,24);
	cout<<" 1. Search by name      "<<endl;
	gotoxy(60,24);
	cout<<" 2. Search by barcode   "<<endl;
	gotoxy(35,26);
	cout<<" 3. Previous Menu       "<<endl;
	gotoxy(60,26);
	cout<<" 0. Return to Main Menu "<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}

void Menus:: SubMenuStatistics()
{
	Header();
	gotoxy(44,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"*******************************"<<endl;
	gotoxy(44,19);
	cout<<"|    GENERATING STATISTICS    |"<< endl;
	gotoxy(44,20);
	cout<<"*******************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//	cout<<""<<endl;
	cout<<"\nChoose what statistics you want to generate:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(21,24);
	cout<<" 1. Top X Selling Product        "<<endl;
	gotoxy(56,24);
	cout<<" 2. Top Selling Product in a Category"<<endl;
	gotoxy(21,26);
	cout<<" 3. Top Selling Manufacturer     "<<endl;
	gotoxy(56,26);
	cout<<" 0. Return to Main Menu              "<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
void Menus:: SubMenuList()
{
	Header();
	gotoxy(47,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"***********************"<<endl;
	gotoxy(47,19);
	cout<<"|    LIST PRODUCTS    |"<< endl;
	gotoxy(47,20);
	cout<<"***********************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
	//	cout<<""<<endl;
	cout<<"\nChoose which list do you want:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(25,24);
	cout<<" 1. All Perishable products "<<endl;
	gotoxy(55,24);
	cout<<" 2. All Non-Perishable Products"<<endl;
	gotoxy(25,26);
	cout<<" 3. ALL products            "<<endl;
	gotoxy(55,26);
	cout<<" 0. Return to Main Menu        "<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
void Menus:: SubMenuSearch()
{
	Header();
	gotoxy(46,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"*************************"<<endl;
	gotoxy(46,19);
	cout<<"|    SEARCH PRODUCTS    |"<< endl;
	gotoxy(46,20);
	cout<<"*************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
		//cout<<""<<endl;
	cout<<"\nChoose how do you want to search products:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(30,24);
	cout<<" 1. Search by name        "<<endl;
	gotoxy(60,24);
	cout<<" 2. Search by category    "<<endl;
	gotoxy(30,26);
	cout<<" 3. Search by manufacturer"<<endl;
	gotoxy(60,26);
	cout<<" 4. Search by barcode     "<<endl;
	gotoxy(45,28);
	cout<<" 0. Return to Main Menu   "<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
void Menus::SubMenuCheckExpiry()
{
	Header();
	gotoxy(46,18);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_INTENSITY);
	cout<<"***************************"<<endl;
	gotoxy(46,19);
	cout<<"|    CHECK EXPIRY DATE    |"<< endl;
	gotoxy(46,20);
	cout<<"***************************"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
		//cout<<""<<endl;
	cout<<"\nChoose how do you want to search perishable product to check expiry date:"<<endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY|FOREGROUND_BLUE|BACKGROUND_GREEN);
	gotoxy(20,24);
	cout<<" 1. Search by name     "<<endl;
	gotoxy(45,24);
	cout<<" 2. Search by barcode  "<<endl;
	gotoxy(70,24);
	cout<<" 0. Return to Main Menu"<<endl;
	SetConsoleTextAttribute(hConsole, 15);
}
void SubMenu0(){};
