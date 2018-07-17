#pragma once
#include<iostream>
#include"Seat.h"
#include <string>
using namespace std;
class Array
{
private:
	Seat seat[500];
	string nameoffilm;
public:
	Array();
	void Setname(string nameoffilm);
	string Getname();
	void Edit(int i, int kat, bool b);
	void Abolition(int i, bool b);
	bool GetB(int i);
	int GetKat(int i);
	int GetPlata(int i);
	~Array();
};

