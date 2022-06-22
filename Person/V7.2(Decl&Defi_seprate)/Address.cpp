#include "stdafx.h"
#include "Address.h"
#include <iostream>

address::address() {}

address::address(address::TYPE _type)
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

void address::setType()
{
	//this->type=selectType();

	int dummyType;

	std::cout << "1. Home  2. Work 3.Shipping" << std::endl;
	std::cout << "Welche Addresse moechten sie einstellen?" << std::endl;
	std::cin >> dummyType;

	switch (dummyType)
	{
	case 1: this->type = TYPE::home; break;
	case 2: this->type = TYPE::work; break;
	case 3:	this->type = TYPE::shipping; break;
	}
}
std::string address::getStringType()
{
	std::string _type;

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
address::TYPE address::getType()
{
	return type;
}

void address::setStadt(const std::string _stadt)
{
	stadt = _stadt;
}
void address::writeStadt()
{
	std::cout << "\nStadt : ";
	std::string _stadt;
	std::cin >> _stadt;
	stadt = _stadt;
}
std::string address::getStadt()
{
	return stadt;
}

void address::setStrasse(const std::string _strasse)
{
	strasse = _strasse;
}
void address::writeStrasse()
{
	std::cout << "\nStrasse : ";
	std::string _strasse;
	std::cin >> _strasse;
	strasse = _strasse;
}
std::string address::getStrasse()
{
	return strasse;
}

void address::setHnr(const std::string _hnr)
{
	hnr = _hnr;
}
void address::writeHnr()
{
	std::cout << "\nHaus Nr : ";
	std::string _hnr;
	std::cin >> _hnr;
	hnr = _hnr;
}
std::string address::getHnr()
{
	return hnr;
}

void address::setPlz(const std::string _plz)
{

}
void address::writePlz()
{
	std::cout << "\nPLZ : ";
	std::string _plz;
	std::cin >> _plz;
	plz = _plz;
}
std::string address::getPlz()
{
	return plz;
}

void address::printAddresse()
{
	std::cout <<
		"\nStadt : " + getStadt() +
		"\nStrasse : " + getStrasse() +
		"\nHnr : " + getHnr() +
		"\nPlz : " + getPlz() +
		"\n======================";
}