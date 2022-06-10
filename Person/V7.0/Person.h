 #pragma once
#include "Common.h"
#include "Address.h"


//person list
class Person
{
public:
	int persId;
	int userNum;
	string nachname;
	string vorname;
	string geburtsdatum;
	typedef enum { Stuttgart = 1, Filderstadt, Frankfurt, Berlin, Unselected } STADT;
	typedef enum { male = 1, female, undefined } SEX;
	STADT stadt;
	SEX sex;
	map<address::TYPE, address*> addresses;
	map<address::TYPE, address*>:: iterator it_addr;

	//construct
	Person() 
	{
		/*nachname = "default";
		vorname = "default";
		geburtsdatum = "TTMMYYYY";
		stadt = STADT::Unselected;
		sex = SEX::undefined;*/
	}
	//overloaded construct 1
	Person(int _userNum)
	{
		userNum = _userNum;
	}

	//overloaded construct 2
	Person(int _persId,string _vorname, string _nachname, SEX _sex, int _geburtsdatum, STADT _stadt)
	{
		persId = _persId;
		vorname = _vorname;
		nachname = _nachname;
		geburtsdatum = _geburtsdatum;
		sex = _sex;
		stadt = _stadt;
	}

	/*int getPersId()
	{
		return persId;
	}
	void changePersId() 
	{

	}
*/
	//Function overloading with Type.
	//address* makeObjAdressWithType(address::TYPE _type)
	//{
	//	//using construct1
	//	address* addr = new address(_type);
	//
	//	addr->writeStadt();
	//	addr->writeStrasse();
	//	addr->writeHnr();
	//	addr->writePlz();
	//
	//	return addr;
	//}
	//Function overloading without Type.
	//address* makeObjAdress()
	//{
	//	//using construct1
	//	address* addr = new address();
	//	addr->writeStadt();
	//	addr->writeStrasse();
	//	addr->writeHnr();
	//	addr->writePlz();
	//	return addr;
	void setUserNum(int _userNum)
	{
		userNum = _userNum;
	}
	string getStrUserNum()
	{
		return to_string(userNum);
	}

	void setElementToAddresses()
	{
		address::TYPE dummyType = selectAddrType();
		address* dummyAddr = new address(dummyType);
		cout << "Selected Addr Type : "+dummyAddr->getStringType();
		dummyAddr->writeStadt();
		dummyAddr->writeStrasse();
		dummyAddr->writeHnr();
		dummyAddr->writePlz();
		cout << "addresses map container hinzu";
		addresses.emplace(make_pair(dummyType,dummyAddr));
	}
	address* getAdress(address::TYPE _type)
	{
		return addresses[_type];
	}
	address::TYPE selectAddrType()
	{
		int Addr_choice;
		address::TYPE _type;
		cout << "1.home 2.work 3.shipping ";
		cout << "\nWelche Addresse moechten Sie Speichern? ";
		cin >> Addr_choice;

		switch (Addr_choice)
		{
		case 1:
			_type = address::TYPE::home;
			break;
		case 2:
			_type = address::TYPE::work;
			break;
		case 3:
			_type = address::TYPE::shipping;
			break;
		default:
			cout << "error";
			break;
		}

		return _type;
	}

	void registerAllOfMemberVariable()
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
		cout <<
			"\n======================"
			"\nUserNum : " +getStrUserNum()+
			"\nVorname : " + getVorname() +
			"\nNachname : " + getNachname() +
			"\nGeburtsdatum : " + getGeburtsdatum() +
			"\nGeschlecht : " + getSex() +
			"\nStadt : " + getStadt() +
			"\n======================";		
	}
	//print information
	void printAllAddr()
	{
		for (it_addr=addresses.begin(); it_addr !=addresses.end(); it_addr++ )
		{
			cout <<
			"\nAddr Type : " + it_addr->second->getStringType();
			it_addr->second->printAddresse();
		}
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
		case SEX::male :
			_sex = "Male"; break;
		case SEX::female :
			_sex = "Female"; break;
		case SEX::undefined :
			_sex = "Undefined"; break;
		default :
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
		case STADT::Stuttgart :
			_stadt = "Stuttgart"; break;
		case STADT::Filderstadt :
			_stadt = "Filderstadt"; break;
		case STADT::Frankfurt :
			_stadt = "Frankfurt"; break;
		case STADT::Berlin :
			_stadt = "Berlin"; break;
		case STADT::Unselected :
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



//search
//sort_searched_result
//change_info
//register
//deregister