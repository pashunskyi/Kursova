#pragma once
class Seat
{
private:
	bool b;
	int kat;
	int plata;
public:
	Seat();
	void Edit(bool b, int kat);
	void Abolition(bool b);
	bool GetB();
	int GetKat();
	int GetPlata();
	~Seat();
};

