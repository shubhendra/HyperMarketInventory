
#ifndef UI_H__
#define UI_H__

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Menus{
private:
	
	//int _command;
	HANDLE hConsole;
public:
	//void gotoxy(int x, int y);
	void MainMenu();
	//bool addProduct();
	void Header();
	int UserChoice();
	//bool callFunction(int aNum);
	//bool printAll();

	//void error();
	void gotoxy(int x,int y);
	void SubMenuAdd_Del();
	void SubMenuAdd();
	void SubMenuDelete();
	void SubMenuRestock();	
	void SubMenuSales_Reset();
	void SubMenuSales();
	void SubMenuReset();
	void SubMenuResetOne();
	void SubMenuStatistics();
	void SubMenuList();
	void SubMenuSearch();
	void SubMenuCheckExpiry();
	//void SubMenu0();
	//We need to have a menu to loaddata and print data
};
#endif
