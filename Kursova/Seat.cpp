#include "Seat.h"

Seat::Seat()
{
	b = 0;
	kat = 7;
	plata = 0;
}
bool Seat::GetB()
{
	return b;
}
int Seat::GetKat()
{
	return kat;
}
int Seat::GetPlata()
{
	return plata;
}
void Seat::Edit(bool b, int kat)
{
	this->b = b;
	if (kat == 13) { this->kat = kat; plata = 10; }
	if (kat == 10) { this->kat = kat; plata = 20; }
	if (kat == 14) { this->kat = kat; plata = 30; }
	if (kat == 12) { this->kat = kat; plata = 60; }
}
void Seat::Abolition(bool b)
{
	if (b == 0)
	{
		this->b = 0;
		kat = 0;
		plata = 0;
	}
}
Seat::~Seat()
{
}