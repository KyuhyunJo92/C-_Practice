#ifndef ENTE_H
#define ENTE_H
#pragma once

#include "stdafx.h"
#include "QuakVerhalten.h"
#include "FlugVerhalten.h"
#include <iostream>
using namespace std;

class Ente
{
public:
	QuakVerhalten *quakVerhaleten;
	FlugVerhalten *flugVerhalten;


	//void quaken();
	void schwimmen() 
	{
		cout << "Ich schwimme.\n";
	}
	virtual void anzeigen()=0;
	//jede Ente sicht sich aus verschiede,
	//deswegen die anzeigen method emplementieren muss.
};


class StockEnte : public Ente
{
public:
	StockEnte()
	{
		cout << "Ich bin eine Stockente.\n";
		quakVerhaleten = new Quaken();
		flugVerhalten = new FliegtMitFluegeln();
	}
	~StockEnte()
	{
		delete quakVerhaleten;
		delete flugVerhalten;
	}
	
	void anzeigen() 
	{
		cout << "sieht wie eine StockEnte aus \n";
	}	
};


class GummiEnte : public Ente
{
public:
	GummiEnte()
	{
		cout << "Ich bin eine Gummiente.\n";
		flugVerhalten = new FliegtGarNicht();
		quakVerhaleten = new StummesQuaken();
	}
	~GummiEnte()
	{
		delete flugVerhalten;
		delete quakVerhaleten;
	}
	void anzeigen()
	{
		cout << "sieht wie eine GummiEnte aus \n";
	}

};
class MoorEnte : public Ente
{
	void anzeigen()
	{
		cout << "sieht wie eine MoorEnte aus \n";
	}
};





#endif
