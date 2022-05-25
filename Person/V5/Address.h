#pragma once
#include "Common.h"

using namespace std;

class address
{
public:
	enum class TYPE { home = 1, work, shipping } type;
	string stadt;
	string strasse;
	string hnr;
	string plz;

	//construct
	address() {};

	//overloaded construct1
	address(address::TYPE _type)
	{
		type = _type;
		/*
		string _stadt;
		cin >> _stadt;
		stadt = _stadt;

		string _strasse;
		cin >> _strasse;
		strasse = _strasse;

		string _hnr;
		cin >> _hnr;
		hnr = _hnr;

		string _plz;
		cin >> _plz;
		plz = _plz;*/
	}

	//overloaded construct2
	/*address(TYPE type, const string &strasse, const string &hnr, const string &plz, const string &stadt)
		:type(type), strasse(strasse), hnr(hnr), plz(plz), stadt(stadt) {}*/

	void setType()
	{
		//this->type=selectType();

		int dummyType;

		cout << "1. Home  2. Work 3.Shipping" << endl;
		cout << "Welche Addresse moechten sie einstellen?" << endl;
		cin >> dummyType;

		switch (dummyType)
		{
		case 1: this->type = TYPE::home; break;
		case 2: this->type = TYPE::work; break;
		case 3:	this->type = TYPE::shipping; break;
		}
	}
	string getStringType()
	{
		string _type;

		switch (type)
		{
		case address::TYPE::home:
			_type = "home"; break;

		case address::TYPE::shipping:
			_type = "shipping"; break;

		case address::TYPE::work:
			_type = "work"; break;
		}
		return _type;
	}
	TYPE getType()
	{
		return type;
	}

	void setStadt(const string _stadt)
	{
		stadt = _stadt;
	}
	void writeStadt()
	{
		cout << "\nStadt : ";
		string _stadt;
		cin >> _stadt;
		stadt = _stadt;
	}
	string getStadt()
	{
		return stadt;
	}

	void setStrasse(const string _strasse)
	{
		strasse = _strasse;
	}
	void writeStrasse()
	{
		cout << "\nStrasse : ";
		string _strasse;
		cin >> _strasse;
		strasse = _strasse;
	}
	string getStrasse()
	{
		return strasse;
	}

	void setHnr(const string _hnr)
	{
		hnr = _hnr;
	}
	void writeHnr()
	{
		cout << "\nHaus Nr : ";
		string _hnr;
		cin >> _hnr;
		hnr = _hnr;
	}
	string getHnr()
	{
		return hnr;
	}

	void setPlz(const string _plz)
	{

	}
	void writePlz()
	{
		cout << "\nPLZ : ";
		string _plz;
		cin >> _plz;
		plz = _plz;
	}
	string getPlz()
	{
		return plz;
	}

	void printAddresse()
	{
		cout <<
			"\nStadt : " + getStadt() +
			"\nStrasse : " + getStrasse() +
			"\nHnr : " + getHnr() +
			"\nPlz : " + getPlz() +
			"\n======================";
	}
};