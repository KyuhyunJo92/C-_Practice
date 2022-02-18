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
public :
	DunkleRoestung()
	{
		beschreibung = "DunkleRoestung";
	}
	double preis()
	{
		return 2.19;
	}
};

class Hausmischung : public Getraenk
{
public :
	Hausmischung()
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
		return getraenk->getBeschreibung() + " + SCHOKO " ;
	}
	double preis()
	{
		return getraenk->preis() + .20  ;
	}

};

class Milch : public ZutatDekorierer
{
private:
	Getraenk* getraenk;
public:
	Milch(Getraenk* getraenk)
	{
		this->getraenk = getraenk;
	}
	string getBeschreibung()
	{
		return getraenk->getBeschreibung() + " + Milch ";//where is exactly getraenk pointing to? 
														 //this-> construct,  
	}

	double preis()
	{
		return getraenk->preis() + .21 ;
	}
};

int main()
{
	Getraenk* getraenk = new Espresso();
	cout << getraenk->getBeschreibung() << getraenk->preis() << "euro"<<endl;

	Getraenk* getraenk2 = new DunkleRoestung();//DunkleRoestung Cafe. 2.19 euro

	getraenk2 = new Schoko(getraenk2);
	getraenk2 = new Milch(getraenk2);
	getraenk2 = new Schoko(getraenk2);
	getraenk2 = new Milch(getraenk2);//fuegen einmal Schoko hinzu. +0.20 euro -> 2.59 euro

	cout << getraenk2->getBeschreibung() << getraenk2->preis() << "euro" << endl;
	/*Getraenk* getraenk3 = nullptr;
	Getraenk* getraenk4 = nullptr;
	Getraenk* getraenk5 = nullptr;*/
	//
	//getraenk3 = new Schoko(getraenk2);//
	//getraenk4 = new Schoko(getraenk3);//fuegen einmal Schoko hinzu. +0.20 euro -> 2.59 euro
	//getraenk5 = new Schoko(getraenk4);//fuegen einmal Schoko hinzu. +0.20 euro -> 2.79 euro
	////getraenk2 = new Milch(getraenk2);
	//cout << getraenk2->getBeschreibung() << getraenk2->preis() << "euro" << endl;
	//
	/*cout << "getraenk 2's Addresse : " << getraenk2 << " getraenk 2's Wert : " << getraenk2->getBeschreibung() << endl;
	cout << "getraenk 3's Addresse : " << getraenk3 << " getraenk 3's Wert : " << getraenk3->getBeschreibung() << endl;
	cout << "getraenk 4's Addresse : " << getraenk4 << " getraenk 4's Wert : " << getraenk4->getBeschreibung() << endl;
	cout << "getraenk 5's Addresse : " << getraenk5 << " getraenk 5's Wert : " << getraenk5->getBeschreibung() << endl;
	
	cout << getraenk5->getBeschreibung() << getraenk5->preis() << "euro" << endl;
*/
	return 0;
}