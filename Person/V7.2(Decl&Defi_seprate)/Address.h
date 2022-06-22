#pragma once
//#include "Common.h"
#include <string>

class address
{
public:
	typedef enum { home = 1, work, shipping } address:: TYPE;
	address::TYPE type;
	std::string stadt;
	std::string strasse;
	std::string hnr;
	std::string plz;

	//construct
	address();

	//overloaded construct1
	address(address::TYPE _type);

	//overloaded construct2
	/*address(TYPE type, const string &strasse, const string &hnr, const string &plz, const string &stadt)
	:type(type), strasse(strasse), hnr(hnr), plz(plz), stadt(stadt) {}*/

	void setType();
	std::string getStringType();
	address::TYPE getType();

	void setStadt(const std::string _stadt);
	void writeStadt();
	std::string getStadt();

	void setStrasse(const std::string _strasse);
	void writeStrasse();
	std::string getStrasse();

	void setHnr(const std::string _hnr);
	void writeHnr();
	std::string getHnr();

	void setPlz(const std::string _plz);
	void writePlz();
	std::string getPlz();

	void printAddresse();
};
