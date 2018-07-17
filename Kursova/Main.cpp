#include<iostream>
#include <iomanip>
#include<conio.h>
#include<Windows.h>
#include <string>
#include<deque>
#include"Seat.h"
#include"Array.h"
#include<istream>
using namespace std;

void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

int Menu();
void ShowMenu(int);
int Films(int, deque<Array>);
void ShowFilms(int, int, deque<Array>);
int Zal(deque<Array> , int);
void ShowZal(int, deque<Array>, int);
int Misze();
void ShowMisze(int);
int Seans();
void ShowSeans(int);
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	deque<Array> list;
	int size = 0;
	
	int menu;
	while (true)
	{
		menu = Menu();
		if (menu == 0)
		{
			size++;
			string buff;
			getline(cin, buff);
			list.push_back(Array());
			list[size -1].Setname(buff);
			
		}
		if (menu == 1)
		{
			int film;
			film = Films(size, list);
			if (film == size)
			{
			}
			else
			{
				int q;
				q = Seans();
				if (q == 0)
				{
					int s;
					s = Zal(list, film);
					s++;
					int q;
					q = Misze();
					if (q == 0)
					{
						list[film].Abolition(s - 1, 0);
					}
					if (q == 1)
					{
						list[film].Edit(s - 1, 13, 1);
					}
					if (q == 2)
					{
						list[film].Edit(s - 1, 10, 1);
					}
					if (q == 3)
					{
						list[film].Edit(s - 1, 14, 1);
					}
					if (q == 4)
					{
						list[film].Edit(s - 1, 12, 1);
					}
				}
				else
				{
					//зберегти у файл
				}
			}
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

void ShowSeans(int ch)
{
	if (ch == 0)
	{
		SetColor(11);
		cout << "Редагувати" << endl;
		SetColor(7);
		cout << "Завершити сеанс" << endl;
		
	}
	if (ch == 1)
	{
		SetColor(7);
		cout << "Редагувати" << endl;
		SetColor(11);
		cout << "Завершити сеанс" << endl;
	}
}
int Seans()
{
	int choice = 0;
	ShowMisze(choice);
	while (true)
	{
		switch (_getch())
		{
		case 224:
		{
			switch (_getch())
			{
			case 80:
				choice < 2 ? choice++ : choice = 0; // >
				ShowMisze(choice);
				break;
			case 72:
				choice > 0 ? choice-- : choice = 2; // <
				ShowMisze(choice);
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

void ShowMisze(int ch)
{
	system("cls");
	if (ch == 0)
	{
		SetColor(7);
		cout << " <Пусте місце>  ";
	}
	if (ch == 1)
	{
		SetColor(13);
		cout << " <дитячий квиток>  ";
	}
	if (ch == 2)
	{
		SetColor(10);
		cout << " <шкільний квиток>  ";
	}
	if (ch == 3)
	{
		SetColor(14);
		cout << " <студенський квиток>  ";
	}
	if (ch == 4)
	{
		SetColor(12);
		cout << " <дорослий квиток>  ";
	}
	SetColor(7);
}
int Misze()
{
	int choice = 0;
	ShowMisze(choice);
	while (true)
	{
		switch (_getch())
		{
		case 224:
		{
			switch (_getch())
			{
			case 77:
				choice < 5 ? choice++ : choice = 0; // >
				ShowMisze(choice);
				break;
			case 75:
				choice > 0 ? choice-- : choice = 5; // <
				ShowMisze(choice);
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

void ShowZal(int ch, deque<Array> list, int film)
{
	system("cls");
	SetColor(11);
	cout << char(111) << " - вказівник  ";
	SetColor(7);
	cout << char(111) << " - пусте місце  ";
	SetColor(13);
	cout << char(111) << " - дитячий квиток  ";
	SetColor(10);
	cout << char(111) << " - шкільний квиток  ";
	SetColor(14);
	cout << char(111) << " - студенський квиток  ";
	SetColor(12);
	cout << char(111) << " - дорослий квиток  ";
	SetColor(7);
	cout << endl;
	cout << endl;
	cout << "\t";
	for (int i = 0; i < 500; i++)
	{
		if (i%50 == 0 && i != 0)
		{
			cout << endl;
			cout << endl;
			cout << "\t";
		}
		if (ch == i)
		{
			SetColor(11);
			cout << char(111) << " ";
			SetColor(7);
		}
		else
		{
			SetColor(list[film].GetKat(i));
			cout << char(111) << " ";
			SetColor(7);
		}
	}
}
int Zal(deque<Array> list, int film)
{
	int choice = 0;
	ShowZal(choice, list, film);
	while (true)
	{
		switch (_getch())
		{
		case 224:
		{
			switch (_getch())
			{
			case 77:
				choice < 500 ? choice++ : choice = 0;
				ShowZal(choice, list, film);
				break;
			case 75:
				choice > 0 ? choice-- : choice = 500;
				ShowZal(choice, list, film);
				break;
			case 80:
				choice < 450 ? choice += 50 : choice = 0;
				ShowZal(choice, list, film);
				break;
			case 72:
				choice > 0 ? choice -= 50 : choice = 499;
				ShowZal(choice, list, film);
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

void ShowFilms(int ch, int size, deque<Array> list)
{
	system("cls");
	for (int i = 0; i < size; i++)
	{
		if (ch == i)
		{
			SetColor(4);
			cout << list[i].Getname() << endl;
			SetColor(7);
		}
		else
		{
			cout << list[i].Getname() << endl;
		}
	}
	if (ch == size)
	{
		SetColor(4);
		cout << "Вихід" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Вихід" << endl;
	}
}

int Films(int size, deque<Array> list)
{
	int choice = 0;
	ShowFilms(choice, size, list);
	while (true)
	{
		switch (_getch())
		{
		case 224:
		{
			switch (_getch())
			{
			case 80:
				choice < size ? choice++ : choice = 0;
				ShowFilms(choice, size, list);
				break;
			case 72:
				choice >0 ? choice-- : choice = size;
				ShowFilms(choice, size, list);
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

void ShowMenu(int ch)
{
	system("cls");
	if (ch == 0)
	{
		SetColor(4);
		cout << "Добавити сеанс" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Добавити сеанс" << endl;
	}
	if (ch == 1)
	{
		SetColor(4);
		cout << "Показати сеанси" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Показати сеанси" << endl;
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