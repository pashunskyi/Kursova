#include "Array.h"



Array::Array()
{
}
bool Array::GetB(int i)
{
	return seat[i].GetB();
}
int Array::GetKat(int i)
{
	return seat[i].GetKat();
}
int Array::GetPlata(int i)
{
	return seat[i].GetPlata();
}
void Array::Setname(string nameoffilm)
{
	this->nameoffilm = nameoffilm;
}
string Array::Getname()
{
	return nameoffilm;
}
void Array::Edit(int i, int kat, bool b)
{
	seat[i].Edit(b, kat);
}
void Array::Abolition(int i, bool b)
{
	seat[i].Abolition(b);
}

Array::~Array()
{
}
