#include<iostream>
#include <iomanip>
#include<conio.h>
#include<Windows.h>
#include <string>
#include<vector>
#include"Seat.h"
#include"Array.h"
#include<istream>
#include<fstream>
using namespace std;

void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

int Menu();
void ShowMenu(int);
int Films(int, vector<Array>);
void ShowFilms(int, int, vector<Array>);
int Zal(vector<Array>, int);
void ShowZal(int, vector<Array>, int);
int Misze();
void ShowMisze(int);
int Seans();
void ShowSeans(int);
void ToFile(Array);
void FromFile();
void main()
{
	system("mode 120, 25");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<Array> list;
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
			list[size - 1].Setname(buff);

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
					ToFile(list[film]);
					list.erase(list.begin() + film);
					size--;
				}
			}
		}
		if (menu == 2)
		{
			FromFile();
		}
		if (menu == 3)
		{
			return;
		}
	}


	system("pause");
}
void FromFile()
{
	system("cls");
	char buff[255];
	ifstream in("історія.txt");
	while (!in.eof())
	{
		in.getline(buff, 255, '+');
		if (in.eof()){break;}
		cout << "Назав: " << buff << endl;
		in.getline(buff, 255, ';');
		cout << "Збори: " << buff << endl;
		cout << endl;
	}
	in.close();
	system("pause");
}
void ToFile(Array a)
{
	int p = 0;
	for (int i = 0; i < 500; i++)
	{
		p += a.GetPlata(i);
	}
	ofstream out("історія.txt", ios_base::app);
	out << a.Getname();
	out << "+";
	out << p;
	out << ";";
	out.close();
}
void ShowSeans(int ch)
{
	system("cls");
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
	ShowSeans(choice);
	while (true)
	{
		switch (_getch())
		{
		case 224:
		{
			switch (_getch())
			{
			case 72:
				choice < 1 ? choice++ : choice = 0;
				ShowSeans(choice);
				break;
			case 80:
				choice > 0 ? choice-- : choice = 1;
				ShowSeans(choice);
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

void ShowZal(int ch, vector<Array> list, int film)
{
	system("cls");
	int money = 0;
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
		money += list[film].GetPlata(i);
		if (i % 50 == 0 && i != 0)
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
	cout << endl;
	cout << endl;
	SetColor(11);
	cout << "Збори - " << money << endl;
	SetColor(7);
}
int Zal(vector<Array> list, int film)
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

void ShowFilms(int ch, int size, vector<Array> list)
{
	system("cls");
	for (int i = 0; i < size; i++)
	{
		if (ch == i)
		{
			SetColor(11);
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

int Films(int size, vector<Array> list)
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
		SetColor(11);
		cout << "Добавити сеанс" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Добавити сеанс" << endl;
	}
	if (ch == 1)
	{
		SetColor(11);
		cout << "Показати сеанси" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Показати сеанси" << endl;
	}
	if (ch == 2)
	{
		SetColor(11);
		cout << "Історія" << endl;
		SetColor(7);
	}
	else
	{
		cout << "Історія" << endl;
	}
	if (ch == 3)
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
				choice < 3 ? choice++ : choice = 0;
				ShowMenu(choice);
				break;
			case 72:
				choice >0 ? choice-- : choice = 3;
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