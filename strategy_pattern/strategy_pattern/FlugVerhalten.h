#ifndef FLUGVERHALTEN_H
#define FLUGVERHALTEN_H
#pragma once

#include "stdafx.h"
#include <iostream>
using namespace std;

class FlugVerhalten
{
public:
	virtual void fliegen()=0;
};


class FliegtMitFluegeln : public FlugVerhalten
{
public:
	void fliegen()
	{
		cout << "Ich fliege! \n";
	}
};


class FliegtGarNicht : public FlugVerhalten
{
public:
	void fliegen()
	{
		cout << "Ich kann gar nicht fliegen.. \n";
	}
};

#endif