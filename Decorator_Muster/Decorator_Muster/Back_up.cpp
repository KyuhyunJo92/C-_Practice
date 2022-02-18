// Decorator_Muster.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Getraenk
{
public:
	string beschreibung;
	Getraenk()
	{
		string beschreibung = "Unbekanntes Getränk";
	}

	virtual string getBeschreibung()
	{
		return beschreibung;
	}
	virtual double preis() = 0;
};

class ZutatDekorierer : public Getraenk
{
public:
	string getBeschreibung() = 0;
};

class Espresso : public Getraenk
{
public:
	Espresso()
	{
		beschreibung = "Espresso";
	}
	double preis()
	{
		return 1.99;
	}
};

class DunkleRoestung : public Getraenk
{
public:
	DunkleRoestung()
	{
		beschreibung = "DunkleRoestung";
	}
	double preis()
	{
		return 2.19;
	}
};

class Haumischung : public Getraenk
{
public:
	Haumischung()
	{
		beschreibung = "Hausmischung";
	}
	double preis()
	{
		return 0.89;
	}
};

class Schoko : public ZutatDekorierer
{
private:
	Getraenk* getraenk;

public:
	Schoko(Getraenk* getraenk)
	{
		this->getraenk = getraenk;
	}
	string getBeschreibung()
	{

		return getraenk->getBeschreibung() + " + SCHOKO ";
	}

	double preis()
	{
		return .20 + getraenk->preis();
	}

};

int main()
{
	Getraenk* getraenk = new Espresso();
	cout << getraenk->getBeschreibung() << getraenk->preis() << "euro" << endl;

	Getraenk* getraenk2 = new DunkleRoestung();//DunkleRoestung Cafe. 2.19 euro
	getraenk2 = new Schoko(getraenk2);//hinzu einmal Schoko fuegen. +0.20 euro -> 2.39 euro
	getraenk2 = new Schoko(getraenk2);//hinzu noch einmal Schoko fuegen. +0.20 euro -> 2.59 euro
	getraenk2 = new Schoko(getraenk2);//hinzu noch einmal Schoko fuegen. +0.20 euro -> 2.79 euro
	cout << getraenk2->getBeschreibung() << getraenk2->preis() << "euro" << endl;
	return 0;
}