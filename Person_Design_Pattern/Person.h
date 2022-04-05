#pragma once
#include "Common.h"
#include "Address.h"

//person list
class Person
{
private:
	int userNum;
	string nachname;
	string vorname;
	string geburtsdatum;

public:
	typedef enum { Stuttgart = 1, Filderstadt, Frankfurt, Berlin, Unselected } STADT;
	typedef enum { male = 1, female, undefined } SEX;
	STADT stadt;
	SEX sex;
	map<address::TYPE, address> addresses;

	//construct
	Person()
	{
		nachname = "default";
		vorname = "default";
		geburtsdatum = "TTMMYYYY";
		stadt = STADT::Unselected;
		sex = SEX::undefined;
	};
	Person(string _vorname, string _nachname, SEX _sex, int _geburtsdatum, STADT _stadt)
	{
		vorname = _vorname;
		nachname = _nachname;
		geburtsdatum = _geburtsdatum;
		sex = _sex;
		stadt = _stadt;
	}

	void setAdress(address::TYPE _type, const std::string &_street, const std::string &_no, const std::string &_zip, const std::string &_city)
	{
		addresses[_type].type = _type;
		addresses[_type].street = _street;
		addresses[_type].no = _no;
		addresses[_type].zip = _zip;
		addresses[_type].setCity(_city);
	}
	address& getAdress(address::TYPE _type)
	{
		return addresses[_type];
	}

	void regesterAllOfMemberVariable()
	{
		changeVorname();
		changeNachname();
		changeSex();
		changeGeburtsdatum();
		changeStadt();
	}
	//Problem Gesclecht, Stadt Ausdruck
	void printPersonalInfo()
	{
		cout << "\n======================" <<
			"\nNachname : " + nachname +
			"\nVorname : " + vorname +
			"\nGeburtsdatum : " + geburtsdatum +
			"\nGeschlecht : " + getSex() +
			"\nStadt : " + getStadt() <<
			"\n======================\n" << endl;
	}

	string getVorname()
	{
		return vorname;
	}
	void setVorname(string _vorname)
	{
		vorname = _vorname;
	}
	void changeVorname()
	{
		cout << "Schreiben Sie neue Vorname : ";
		cin >> vorname;
	}

	string getNachname()
	{
		return nachname;
	}
	void setNachname(string _nachname)
	{
		nachname = _nachname;
	}
	void changeNachname()
	{
		cout << "Schreiben Sie neue Nachname : ";
		cin >> nachname;
	}

	string getGeburtsdatum()
	{
		return geburtsdatum;
	}
	void setGeburtsdatum(string _geburtsdatum)
	{
		geburtsdatum = _geburtsdatum;
	}
	void changeGeburtsdatum()
	{
		cout << "TTMMYYYY" << endl;
		cout << "Schreiben Sie neuen Geburtsdatum.";
		cin >> geburtsdatum;
	}

	string getSex()
	{
		string _sex;

		switch (sex)
		{
		case SEX::male:
			_sex = "Male"; break;
		case SEX::female:
			_sex = "Female"; break;
		case SEX::undefined:
			_sex = "Undefined"; break;
		default:
			cout << "Geschlecht nicht ausgewaehlt wird."; break;
		}
		return _sex;
	}
	void setSex(int i)
	{

		switch (i)
		{
		case 1: sex = SEX::male;/*
								cout << "set Geschlecht : Male" << endl;*/
			break;

		case 2: sex = SEX::female;/*
								  cout << "set Geschlecht : Female" << endl;*/
			break;

		case 3: sex = SEX::undefined;/*
									 cout << "set Geschlecht : undefinded" << endl;*/
			break;

		default:/*
				cout << "wrong Input." << endl;*/
			break;
		}
	}
	void changeSex()
	{
		cout << "0.Undefinded 1. Male  2.Female  " << endl;
		int i;
		cin >> i;
		switch (i)
		{
		case 0: sex = SEX::undefined;
			cout << "Geschlecht : undefinded" << endl;
			break;
		case 1: sex = SEX::male;
			cout << "Geschlecht : Male" << endl;
			break;

		case 2: sex = SEX::female;
			cout << "Geschlecht : Female" << endl;
			break;

		default:
			cout << "wrong Input." << endl;
			break;
		}
	}

	string getStadt()
	{
		string _stadt;

		switch (stadt)
		{
		case STADT::Stuttgart:
			_stadt = "Stuttgart"; break;
		case STADT::Filderstadt:
			_stadt = "Filderstadt"; break;
		case STADT::Frankfurt:
			_stadt = "Frankfurt"; break;
		case STADT::Berlin:
			_stadt = "Berlin"; break;
		case STADT::Unselected:
			_stadt = "Unselected"; break;
		}
		return _stadt;
	}
	void setStadt(int i)//this function should be altered to combobox of MFC.
	{
		/*cout << "1.Stuttgart 2.Filderstadt 3.Frankfurt 4.Berlin 5.unselected" << endl;
		*/
		switch (i)
		{
		case 1: stadt = STADT::Stuttgart;
			/*cout << "set Stadt : Stuttgart" << endl;
			*/break;

		case 2: stadt = STADT::Filderstadt;
			/*cout << "set Stadt : Filderstadt" << endl;
			*/break;

		case 3: stadt = STADT::Frankfurt;
			/*cout << "set Stadt : Frankfurt" << endl;
			*/break;

		case 4: stadt = STADT::Berlin;
			/*cout << "set Stadt : Berlin" << endl;
			*/break;

		default:
			/*cout << "wrong Input." << endl;
			*/break;
		}
	}
	void changeStadt()//this function should be altered to combobox of MFC.
	{
		cout << "0.Unselected 1.Stuttgart 2.Filderstadt 3.Frankfurt 4.Berlin " << endl;
		int i;
		cin >> i;
		switch (i)
		{
		case 0: stadt = STADT::Unselected;
			cout << "Stadt : Unselected" << endl;
			break;

		case 1: stadt = STADT::Stuttgart;
			cout << "Stadt : Stuttgart" << endl;
			break;

		case 2: stadt = STADT::Filderstadt;
			cout << "Stadt : Filderstadt" << endl;
			break;

		case 3: stadt = STADT::Frankfurt;
			cout << "Stadt : Frankfurt" << endl;
			break;

		case 4: stadt = STADT::Berlin;
			cout << "Stadt : Berlin" << endl;
			break;

		default:
			cout << "wrong Input." << endl;
			break;
		}
	}
};
