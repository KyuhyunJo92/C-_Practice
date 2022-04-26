#pragma once

#include "PersonDB.h"
#include "Person.h"
#include "Common.h"
#include "Functionen.h"

//class Import ist ein Interface in diesem fall. Wenn benutzer CSV File herstellen moechten,  

class Import

{
public :
	PersonDB * pdb;
	string dummyString;
	ifstream iMyFile;
};

class ImportCSVFile :  public Import
{
public:
	ImportCSVFile(PersonDB * _pdb)
	{
		pdb = _pdb;
	}

	void execute()//ifstream
	{
		
		pdb->personen.clear();
		iMyFile.open("Personen.csv");
		int i;
		while (iMyFile.is_open())
		{
			while (!iMyFile.eof())
			{
				Person* person = new Person();

				getline(iMyFile, dummyString, ',');
				i = stoi(dummyString);

				getline(iMyFile, dummyString, ',');
				person->setVorname(dummyString);

				getline(iMyFile, dummyString, ',');
				person->setNachname(dummyString);

				getline(iMyFile, dummyString, ',');
				person->setGeburtsdatum(dummyString);

				getline(iMyFile, dummyString, ',');
				//받은 dummyString값을 int로 바꾸고

				person->setSex(checkSexAndPutNumOut(dummyString));
				//int값을 setSex()의 argument로 넣는다.

				getline(iMyFile, dummyString, '\n');
				//받은 dummyString값을 int로 바꾸고
				person->setStadt(checkSexAndPutNumOut(dummyString));

				pdb->personen.emplace(make_pair(i, person));
			}
			//while (getline(iMyFile, dummyString,','));
			//getline(파일객체,저장변수,구분자);
			//getline(fs, str_buf, ',');
			if (iMyFile.eof())
			{
				iMyFile.close();
			}
		}
	}
};

class ImportTXTFile : public Import
{
public:
	ImportTXTFile(PersonDB* _pdb)
	{
		pdb = _pdb;
	}
	int cursor;
	string line;
	int dummyUserNum;

	void execute()//ifstream
	{
		//variables initiate.
		cursor = 0;
		line = "";
		dummyUserNum = 0;

		//PersonDB::map<int,Person*>.clear()
		pdb->personen.clear();

		iMyFile.open("Personen.txt");
		cout << "file is opened";
		while (iMyFile.is_open())
		{
			/*
			문제는 포인터가 가리키는 메모리에 저장된 값이 같다는 것이다.
			값을 분리해야한다.
			*/
			Person* person = new Person();

			while (!iMyFile.eof())
			{
				getline(iMyFile, line, '\n');
				if (line.find("Usernumber") != string::npos)
				{
					cursor = line.find("Usernumber : ");
					cursor = cursor + 13;
					dummyString = line.substr(cursor, '\n');
					dummyUserNum = stoi(dummyString);
				}
				else if (line.find("Vorname") != string::npos)
				{
					cursor = line.find("Vorname    : ");
					cursor = cursor + 13;
					dummyString = line.substr(cursor, '\n');
					person->setVorname(dummyString);
				}
				else if (line.find("Nachname") != string::npos)
				{
					cursor = line.find("Nachname   : ");
					cursor = cursor + 13;
					dummyString = line.substr(cursor, '\n');
					person->setNachname(dummyString);
				}
				else if (line.find("Geburtstag") != string::npos)
				{
					cursor = line.find("Geburtstag : ");
					cursor = cursor + 13;
					dummyString = line.substr(cursor, '\n');
					person->setGeburtsdatum(dummyString);
				}
				else if (line.find("Geschlecht") != string::npos)
				{
					cursor = line.find("Geschlecht : ");
					cursor = cursor + 13;
					dummyString = line.substr(cursor, '\n');
					person->setSex(checkSexAndPutNumOut(dummyString));
				}
				else if (line.find("Stadt") != string::npos)
				{
					cursor = line.find("Stadt      : ");
					cursor = cursor + 13;
					dummyString = line.substr(cursor, '\n');
					person->setGeburtsdatum(dummyString);
				}
				else if (line.find(';') != string::npos)
				{
					//dummyUserNum = createNewNonDuplicateUserNum();
					pdb->personen.emplace(make_pair(dummyUserNum, person));
					//person = nullptr;
					break;
				}
				//else
				//{
				//	//break;
				//}
			}
			//"\n"을 만날때까지 읽은 문자열을 dummystring에 저장한다.
			//dummystring을 setVorname()함수에 인자로 넣고 실행한다.
			//int i = createNewNonDuplicateUserNum();`
			if (iMyFile.eof())
			{
				iMyFile.close();
			}
		}
		//while (getline(iMyFile, dummyString,','));
		//getline(파일객체,저장변수,구분자);
		//getline(fs, str_buf, ',');
	}
};