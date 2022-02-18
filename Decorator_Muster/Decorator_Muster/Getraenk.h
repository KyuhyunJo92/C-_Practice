#pragma once
#ifndef GETRAENK_H

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Getaenk 
{
private:
	string beschreibung;
public:
	virtual string getBeschreibung() = 0;
	virtual int preis(int) = 0;
};

class Hausmischung : public Getaenk 
{

};


#endif
