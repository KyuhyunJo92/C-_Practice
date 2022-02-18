#ifndef QUAKVERHALTEN_H
#define QUAKVERHALTEN_H
#pragma once

#include "stdafx.h"
#include <iostream>
using namespace std;


class QuakVerhalten
{
public:
	virtual void quaken()=0;
};


class Quaken : public QuakVerhalten
{
public:
	void quaken()
	{
		cout << "richtige Quaken!! \n";
	}
};


class StummesQuaken : public QuakVerhalten
{
	void quaken()
	{
		cout << "Ein Quaken, das kein Geraeusch macht. \n";
	}

};
class Quietschen : public QuakVerhalten
{
public:
	void quaken()
	{
		cout << "Ein Quaken, das quietsch. \n";
	}
};

#endif