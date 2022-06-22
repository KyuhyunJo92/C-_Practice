#include "Person.h"

Person::Person()
{
}
//overloaded construct 1
Person::Person(int _userNum)
{
	userNum = _userNum;
}

//overloaded construct 2
Person::Person(int _persId, string _vorname, string _nachname, SEX _sex, string _geburtsdatum, STADT _stadt)
{
	persId = _persId;
	vorname = _vorname;
	nachname = _nachname;
	geburtsdatum = _geburtsdatum;
	sex = _sex;
	stadt = _stadt;
}

Person::Person(int _persId, string _vorname, string _nachname, SEX _sex, string _geburtsdatum, STADT _stadt, string _login_id, string _login_pw)
{
	persId = _persId;
	vorname = _vorname;
	nachname = _nachname;
	geburtsdatum = _geburtsdatum;
	sex = _sex;
	stadt = _stadt;
	login_id = _login_id;
	login_pw = _login_pw;
}


void Person::setUserNum(int _userNum)
{
	userNum = _userNum;
}
string Person::getStrUserNum()
{
	return to_string(userNum);
}

void Person::setElementToAddresses()
{
	address::TYPE dummyType = selectAddrType();
	address* dummyAddr = new address(dummyType);
	cout << "Selected Addr Type : " + dummyAddr->getStringType();
	dummyAddr->writeStadt();
	dummyAddr->writeStrasse();
	dummyAddr->writeHnr();
	dummyAddr->writePlz();
	cout << "addresses map container hinzu";
	addresses.emplace(make_pair(dummyType, dummyAddr));
}
address* Person::getAdress(address::TYPE _type)
{
	return addresses[_type];
}
address::TYPE Person::selectAddrType()
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

void Person::registerAllOfMemberVariable()
{
	changeVorname();
	changeNachname();
	changeSex();
	changeGeburtsdatum();
	changeStadt();
	changelogin_id();
	changelogin_pw();
}

//Problem Gesclecht, Stadt Ausdruck
void Person::printPersonalInfo()
{
	cout <<
		"\n======================"
		"\nUserNum : " + getStrUserNum() +
		"\nVorname : " + getVorname() +
		"\nNachname : " + getNachname() +
		"\nGeburtsdatum : " + getGeburtsdatum() +
		"\nGeschlecht : " + getSex() +
		"\nStadt : " + getStadt() +
		"\nlogin_id : " + getlogin_id() +
		"\nlogin_pw : " + getlogin_pw() +
		"\n======================";
}

//print information
void Person::printAllAddr()
{
	for (it_addr = addresses.begin(); it_addr != addresses.end(); it_addr++)
	{
		cout <<
			"\nAddr Type : " + it_addr->second->getStringType();
		it_addr->second->printAddresse();
	}
}

string Person::getVorname()
{
	return vorname;
}
void Person::setVorname(string _vorname)
{
	vorname = _vorname;
}
void Person::changeVorname()
{
	cout << "Schreiben Sie neue Vorname : ";
	cin >> vorname;
}

string Person::getNachname()
{
	return nachname;
}
void Person::setNachname(string _nachname)
{
	nachname = _nachname;
}
void Person::changeNachname()
{
	cout << "Schreiben Sie neue Nachname : ";
	cin >> nachname;
}

string Person::getGeburtsdatum()
{
	return geburtsdatum;
}
void Person::setGeburtsdatum(string _geburtsdatum)
{
	geburtsdatum = _geburtsdatum;
}
void Person::changeGeburtsdatum()
{
	cout << "TTMMYYYY" << endl;
	cout << "Schreiben Sie neuen Geburtsdatum.";
	cin >> geburtsdatum;
}

string Person::getlogin_id()
{
	return login_id;
}
void Person::setlogin_id(string _login_id)
{
	login_id = _login_id;
}
void Person::changelogin_id()
{
	cout << "Schreiben Sie neuen login_id.";
	cin >> login_id;
}

string Person::getlogin_pw()
{
	return login_pw;
}
void Person::setlogin_pw(string _login_pw)
{
	login_pw = _login_pw;
}
void Person::changelogin_pw()
{
	cout << "Schreiben Sie neuen login_pw.";
	cin >> login_pw;
}

string Person::getSex()
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
void Person::setSex(int i)
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
void Person::changeSex()
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

string Person::getStadt()
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
void Person::setStadt(int i)//this function should be altered to combobox of MFC.
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
void Person::changeStadt()//this function should be altered to combobox of MFC.
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