#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

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