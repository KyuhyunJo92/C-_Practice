 #pragma once
//#include "Common.h"
#include "Address.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;

//person list
class Person
{
public:
	int persId;
	int userNum;
	string nachname;
	string vorname;
	string geburtsdatum;
	string login_id;
	string login_pw;
	typedef enum { Stuttgart = 1, Filderstadt, Frankfurt, Berlin, Unselected } STADT;
	typedef enum { male = 1, female, undefined } SEX;
	STADT stadt;
	SEX sex;
	map<address::TYPE, address*> addresses;
	map<address::TYPE, address*>:: iterator it_addr;

	//construct
	Person();
	//overloaded construct 1
	Person(int _userNum);

	//overloaded construct 2
	Person(int _persId, string _vorname, string _nachname, SEX _sex, string _geburtsdatum, STADT _stadt);

	Person(int _persId, string _vorname, string _nachname, SEX _sex, string _geburtsdatum, STADT _stadt, string _login_id, string _login_pw);


	void setUserNum(int _userNum);
	string getStrUserNum();

	void setElementToAddresses();
	address* getAdress(address::TYPE _type);
	address::TYPE selectAddrType();

	void registerAllOfMemberVariable();

	//Problem Gesclecht, Stadt Ausdruck
	void printPersonalInfo();

	//print information
	void printAllAddr();

	string getVorname();
	void setVorname(string _vorname);
	void changeVorname();

	string getNachname();
	void setNachname(string _nachname);
	void changeNachname();

	string getGeburtsdatum();
	void setGeburtsdatum(string _geburtsdatum);
	void changeGeburtsdatum();

	string getlogin_id();
	void setlogin_id(string _login_id);
	void changelogin_id();

	string getlogin_pw();
	void setlogin_pw(string _login_pw);
	void changelogin_pw();

	string getSex();
	void setSex(int i);
	void changeSex();

	string getStadt();
	void setStadt(int i);
	void changeStadt();
};