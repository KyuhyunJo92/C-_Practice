#pragma once
#include "Common.h"

class address
{
private:
	string city;
public:
	enum class TYPE { home, work, shipping } type;
	string street;
	string no;
	string zip;

	//construct
	address() {};
	address(TYPE type, const string &street, const string &no, const string &zip, const string &city)
		:type(type), street(street), no(no), zip(zip), city(city) {}

	void setCity(const std::string _city)
	{
		city = _city;
	}

	std::string getCity()
	{
		return city;
	}


};
