#include<iostream>
#include <iomanip>
#include<conio.h>
#include<Windows.h>
#include <string>
#include<deque>
#include"Seat.h"
using namespace std;

void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

int Menu();
void ShowMenu(int);

void main()
{
	deque<Seat> list;
	string nof[10];
	int size = 0;


	int menu;
	while (true)
	{
		menu = Menu();
		if (menu == 0)
		{
			size++;
			cin >> nof[size - 1];
			list.resize(23);
		}
		if (menu == 1)
		{
			for (int i = 0; i < size; i++)
			{
				cout << nof[i] << endl;
			}
			system("pause");
		}
		if (menu == 2)
		{
			
		}
		if (menu == 3)
		{
			
		}
		if (menu == 4)
		{
			
		}
		if (menu == 5)
		{
			return;
		}
	}
	
	
	system("pause");
}

void ShowMenu(int ch)
{
	system("cls");
	if (ch == 0)
	{
		SetColor(4);
		cout << "Add session" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Add session" << endl;
	}
	if (ch == 1)
	{
		SetColor(4);
		cout << "Show sessions" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Show sessions" << endl;
	}
	if (ch == 2)
	{
		SetColor(4);
		cout << "Edit student" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Edit student" << endl;
	}
	if (ch == 3)
	{
		SetColor(4);
		cout << "Delete student" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Delete student" << endl;
	}
	if (ch == 4)
	{
		SetColor(4);
		cout << "Find student" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Find student" << endl;
	}
	if (ch == 5)
	{
		SetColor(4);
		cout << "Exit" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Exit" << endl;
	}
}

int Menu()
{
	int choice = 0;
	ShowMenu(choice);
	while (true)
	{
		switch (_getch())
		{
		case 224:
		{
			switch (_getch())
			{
			case 80:
				choice < 5 ? choice++ : choice = 0;
				ShowMenu(choice);
				break;
			case 72:
				choice >0 ? choice-- : choice = 5;
				ShowMenu(choice);
				break;
			}
			break;
		}
		case 13:
		{
			return choice;
		}
		}
	}
}