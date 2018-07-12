#pragma once
class Seat
{
private:
	bool b;
	int kat;
	int plata;
public:
	Seat()
	{
		b = 0;
		kat = 0;
		plata = 0;
	}
	void Edit(bool b, int kat)
	{
		this->b = b;
		if (kat == 1) { plata = 10; }
		if (kat == 2) { plata = 20; }
		if (kat == 3) { plata = 30; }
		if (kat == 4) { plata = 60; }
	}
	void Abolition(bool b)
	{
		if (b == 0)
		{
			this->b = 0;
			kat = 0;
			plata = 0;
		}
	}
	~Seat() {};
};

