#pragma once
#include "PersonDB.h"
#include "Person.h"
#include "Common.h"



class registerNewPerson
{
private:
	PersonDB * pdb;
public:
	registerNewPerson(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
	void execute()
	{
		int i = pdb->createNewNonDuplicateUserNum();
		Person* person = new Person();//Ruft es 'default Construct' auf.
		person->registerAllOfMemberVariable();
		pdb->personen.emplace(make_pair(i, person));
		cout << "\nNeue Benutzer wird registriert.\n";
		cout << "Benutzer Nummer : " + to_string(i) << endl;
		person->printPersonalInfo();
	}
};

class deletePerson
{
private:
	PersonDB * pdb;
public:
	deletePerson(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
	void execute()
	{
		int userNum;
		cout << "input user Number";
		cin >> userNum;
		pdb->personen.erase(userNum);
	}
};

class searchInfo
{
private:
	PersonDB * pdb;
public:
	searchInfo(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
	void execute()
	{
		int userNum;
		cout << "input user Number : ";
		cin >> userNum;
		if (pdb->personen[userNum])
		{
			cout << "User Number :" + to_string(userNum) << "\n";
			pdb->personen[userNum]->printPersonalInfo();
		}
		else
		{
			cout << "No File for UserNumber :" + to_string(userNum) << "\n";
		}
	}

};

class changeInfo
{
private:
	PersonDB * pdb;
public:
	changeInfo(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
	void execute()
	{
		cout << "Bitte tun Sie die Usernumber rein.";
		int j;
		cin >> j;


		cout << "1.Vorname  2.Nachname  3.Geburtsdatum  4.Geschlecht  5.Stadt" << endl;
		cout << "veraendern personal data. auswaehlen Sie der Data, den Sie veraendern moechte. :";
		int i;
		cin >> i;
		switch (i)
		{
		case 1: pdb->personen[j]->changeVorname();
			break;

		case 2: pdb->personen[j]->changeNachname();
			break;

		case 3: pdb->personen[j]->changeGeburtsdatum();
			break;

		case 4: pdb->personen[j]->changeSex();
			break;

		case 5: pdb->personen[j]->changeStadt();
			break;

		default:
			cout << "wrong Input.";
			break;
		}
	}
};




int checkStadtAndPutNumOut(string _dummyString)
{
	//this is a worst "HardCoding". It would have very easily typo. 
	int i = 0;
	if (_dummyString == "Unselected") i = 0;
	else if (_dummyString == "Stuttgart") i = 1;
	else if (_dummyString == "Filderstadt") i = 2;
	else if (_dummyString == "Frankfurt") i = 3;
	else if (_dummyString == "Berlin") i = 4;

	return i;

}
int checkSexAndPutNumOut(string _dummyString)
{
	//this is a worst "HardCoding". It would have very easily typo. 
	int i = 0;
	if (_dummyString == "Undefined") i = 0;
	else if (_dummyString == "Male") i = 1;
	else if (_dummyString == "Female") i = 2;

	return i;
}

/*void mainFuction()
{
int while_i = 1;//Eines "Integer" dafuer, die While loop kontrollieren.
while (while_i)
{
int j;
cout << "0.EXIT 1.Anmelden  2.Abmelden  3.AnzeigenAllenInfo  4.Nachschlagen  5.Data aendern  6.exportieren  7.importieren \n";
cout << "Welche Funtion moechten Sie benutzen?";
cin >> j;
switch (j)
{
case 0: while_i = 0;
break;
case 1: registerNewPerson();
break;
case 2: deletePerson();
break;
case 3: viewAllInfo();
break;
case 4: searchInfo();
break;
case 5: changeInfo();
break;
case 6: exportCSVFile();
break;
case 7: importCSVFile();
break;
default:
break;
}
}
}*/

