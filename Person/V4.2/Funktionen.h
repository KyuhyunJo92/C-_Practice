﻿#pragma once
#include "Common.h"
#include "PersonDB.h"
#include "Person.h"

class CreateNewNonDuplicateUserNum
{
public:
	CreateNewNonDuplicateUserNum(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
	PersonDB * pdb;

	int execute()
	{
		int count = 0;

		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
			if (pdb->it->first == count)
			{
				count++;
			}
		}
		return count;
	}
};

class RegisterNewPerson
{
private:
	PersonDB * pdb;
	CreateNewNonDuplicateUserNum * cnndum;
public:
	RegisterNewPerson(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
	void execute()
	{
		//int i = pdb->createNewNonDuplicateUserNum();
		cnndum = new CreateNewNonDuplicateUserNum(pdb);
		int i = cnndum->execute();
		Person* person = new Person();//Ruft es 'default Construct' auf.
		person->registerAllOfMemberVariable();
		pdb->personen.emplace(make_pair(i, person));
		cout << "\nNeue Benutzer wird registriert.\n";
		cout << "Benutzer Nummer : " + to_string(i) << endl;
		person->printPersonalInfo();
	}
};

class DeletePerson
{
private:
	PersonDB * pdb;
public:
	DeletePerson(PersonDB * _pdb)
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

class SearchInfo
{
private:
	PersonDB * pdb;
public:
	SearchInfo(PersonDB * _pdb)
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

class ChangeInfo
{
private:
	PersonDB * pdb;
public:
	ChangeInfo(PersonDB * _pdb)
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

class ViewAllInfo
{
public:
	ViewAllInfo(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
	PersonDB * pdb;
	void execute()
	{
		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
			pdb->it->second->printPersonalInfo();
		}
	}
};
//usernum logic check!!!!!!!!!!!!!
class ImportCSVFile
{
public:
	ImportCSVFile(PersonDB * _pdb)
	{
		pdb = _pdb;
	}

	PersonDB * pdb;

	void execute()//ifstream
	{
		string testString;
		string dummyString;
		ifstream iMyFile;
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

class ImportTXTFile
{
public:
	ImportTXTFile(PersonDB* _pdb)
	{
		pdb = _pdb;
	}
	PersonDB * pdb;
	void execute()//ifstream
	{
		string dummyString;
		int dummyUserNum;
		string line;
		int index;
		ifstream iMyFile;
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
					index = line.find("Usernumber : ");
					index = index + 13;
					dummyString = line.substr(index, '\n');
					dummyUserNum = stoi(dummyString);
				}
				else if (line.find("Vorname") != string::npos)
				{
					index = line.find("Vorname    : ");
					index = index + 13;
					dummyString = line.substr(index, '\n');
					person->setVorname(dummyString);
				}
				else if (line.find("Nachname") != string::npos)
				{
					index = line.find("Nachname   : ");
					index = index + 13;
					dummyString = line.substr(index, '\n');
					person->setNachname(dummyString);
				}
				else if (line.find("Geburtstag") != string::npos)
				{
					index = line.find("Geburtstag : ");
					index = index + 13;
					dummyString = line.substr(index, '\n');
					person->setGeburtsdatum(dummyString);
				}
				else if (line.find("Geschlecht") != string::npos)
				{
					index = line.find("Geschlecht : ");
					index = index + 13;
					dummyString = line.substr(index, '\n');
					person->setSex(checkSexAndPutNumOut(dummyString));
				}
				else if (line.find("Stadt") != string::npos)
				{
					index = line.find("Stadt      : ");
					index = index + 13;
					dummyString = line.substr(index, '\n');
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

class ExportCSVFile
{
public:
	ExportCSVFile(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
	PersonDB * pdb;


	void execute()//ofstream
	{
		ofstream oMyFile;
		oMyFile.open("Personen.csv");

		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
			oMyFile << pdb->it->second->getVorname() + ","
				+ pdb->it->second->getNachname() + ","
				+ pdb->it->second->getGeburtsdatum() + ","
				+ pdb->it->second->getSex() + ","
				+ pdb->it->second->getStadt() + "\n";
		}

		oMyFile.close();
		/*oMyFile>>
		fstream fs;
		fs.open("test.csv", ios::in);
		this data should be sperated with "," wie CSV data
		enum type(sex, stadt -> take as a string => male,female,undefined  stuttgart...)
		}
		void inputDataOfMapContainerToFile()
		{
		//use'TakeDataOfMapContainerOut()'method
		*/
	}

};

class ExportTXTFile
{
public:
	ExportTXTFile(PersonDB *_pdb)
	{
		pdb = _pdb;
	}
	PersonDB * pdb;
	void execute()
	{
		ofstream oMyFile;
		oMyFile.open("Personen.txt");

		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
			oMyFile <<

				"Usernumber : " + to_string(pdb->it->first) + "\n"
				"Vorname    : " + pdb->it->second->getVorname() + "\n"
				"Nachname   : " + pdb->it->second->getNachname() + "\n"
				"Geburtstag : " + pdb->it->second->getGeburtsdatum() + "\n"
				"Geschlecht : " + pdb->it->second->getSex() + "\n"
				"Stadt      : " + pdb->it->second->getStadt() + "\n"";\n";
		}

		oMyFile.close();
	}
};

class Sqlite3_insert
{
public:
	Sqlite3_insert(PersonDB *_pdb)
	{
		pdb = _pdb;
	}
	PersonDB * pdb;
	map<int, Person*>::iterator  it;
	int whileControl = 1;
	void execute()
	{
		while(whileControl)
		{
		for (it = pdb->personen.begin(); it != pdb->personen.end(); it++)
		{
			sqlite3 *db;
			char *err_msg = 0;

			//string a, b, c, d, e;
			//strcpy_s(a, pdb->it->second->getNachname());
			/*strcpy_s(dummyNachname,pdb->it->second->getNachname());
			pdb->it->second->getNachname()
			pdb->it->second->getVorname() 
			pdb->it->second->getGeburtsdatum() 
			pdb->it->second->getStadt() 
			pdb->it->second->getSex() 
			*/

			/*string _nachname = it->second->getNachname();
			string _vorname = it->second->getVorname();
			string _geburtsDatum = it->second->getGeburtsdatum();
			string _stadt = it->second->getStadt();
			string _sex = it->second->getSex();*/
			
			//char* _a;
			//char carr[50];
			//string a = "aaaa\0";
			//strcpy_s(carr,sizeof(carr),"aa");
			//char* carr = new char[b.length()];
			//const char* carr2 = b.c_str();
			//for (int i = 0; i < b.length() + 1; i++)
			//{
			//	carr[i] = (b.at(i));
			//	cout << carr[i];
			//}
			//char buf[50];
			//b.copy(buf, b.length(), 0);
			//const char aa = 'a';


			int rc = sqlite3_open("test.db", &db);

			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);

				whileControl = 0;
			}

			//const char* _nachname=it->second->getNachname().c_str();
			//const char* _vorname = it->second->getVorname().c_str();
			//const char* _geburtsDatum = it->second->getGeburtsdatum().c_str();
			//const char* _stadt = it->second->getStadt().c_str();
			//const char* _sex = it->second->getSex().c_str();			
			/*if(rc == SQLITE_OK)
			{*/
			char _dummySQL[300];
			/*_dummySQL[0] = { 0, };*/
			memset(_dummySQL, 0, sizeof(char) * 300);
			/*'1','2','3','4','5');*/
			strcpy_s(
				_dummySQL,
				"CREATE TABLE IF NOT EXISTS Person(Id INT, nachname text, vorname text, gebertsdatum text, stadt text, sex text);"
				"INSERT INTO Person(id,nachname,vorname,gebertsdatum,stadt,sex) VALUES(?,'"
				);
			strcat_s(
				_dummySQL,
				it->second->getNachname().c_str()
				);
			strcat_s(
				_dummySQL,
				"','"
			);
			strcat_s(
				_dummySQL,
				it->second->getVorname().c_str()
			);
			strcat_s(
				_dummySQL,
				"','"
			);
			strcat_s(
				_dummySQL,
				it->second->getGeburtsdatum().c_str()
			);
			strcat_s(
				_dummySQL,
				"','"
			);
			strcat_s(
				_dummySQL,
				it->second->getStadt().c_str()
			);
			strcat_s(
				_dummySQL,
				"','"
			);
			strcat_s(
				_dummySQL,
				it->second->getSex().c_str()
			);
			strcat_s(
				_dummySQL,
				"');"
			);
			char* sql = _dummySQL;
			/*char *sql =
					"CREATE TABLE IF NOT EXISTS Person(Id INT, name text, vorname text, gebertsdatum text, stadt text, sex text);"
					"INSERT INTO Person VALUES(?,'1','2','3','4','5');";*/
					/*(name text, vorname text, gebertsdatum text, stadt text, sex text)*//*,_nachname,_vorname, _geburtsDatum, _stadt, _sex*/
					//,_nachname,_vorname,_geburtsDatum,_stadt,_sex);
						//_nachname.c_str()+"','"+ + "');"
						/*, (it->second->getNachname(), it->second->getVorname(), it->second->getGeburtsdatum(), it->second->getStadt(), it->second->getSex()));*/
					
					rc = sqlite3_exec(db, sql, 0, 0, &err_msg);	 
					

			/*}*/
			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "SQL error: %s\n", err_msg);
				
				sqlite3_free(err_msg);
				sqlite3_close(db);

				whileControl = 1;
			}
			sqlite3_close(db);

			whileControl = 0;
		}
		}
	}
};

//pure functions, no side effect. pure input, pure output
