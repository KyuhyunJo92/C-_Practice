#pragma once
#include "Common.h"

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
	CreateNewNonDuplicateUserNum * cnndun;
public:
	RegisterNewPerson(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}

	void execute()
	{
		//int i = pdb->createNewNonDuplicateUserNum();
		cnndun = new CreateNewNonDuplicateUserNum(pdb);
		int _cnndun = cnndun->execute();
		Person* person = new Person(_cnndun);//Ruft es 'default Construct' auf.
		person->registerAllOfMemberVariable();
		pdb->personen.emplace(make_pair(_cnndun, person));
		/*cout << "\nNeue Benutzer wird registriert.\n";
		cout << "Benutzer Nummer : " + to_string(_cnndun) << endl;*/
		person->printPersonalInfo();
		//added delete Pointer
		delete cnndun;
	}
};

class SaveNewAddress
{
public :
	SaveNewAddress(PersonDB* _pdb)
	{
		pdb = _pdb;
	}

	PersonDB* pdb;

	void execute()
	{
		cout << "Bitte tun Sie die Usernumber rein.";
		int j;
		cin >> j;

		//access to person*, aufruf setElementToAddresses().
		pdb->personen[j]->setElementToAddresses();
		/*//1.select AddrType in map_container of the Person*	2.call makeObjAddress  3.put it in.
		pers->addresses.emplace(make_pair(selectType(), pers->makeObjAdress()));*/
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
			pdb->personen[userNum]->printAllAddr();
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
			//pdb->it->second : Person*
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
		if (iMyFile.is_open())
		{
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
						person->setUserNum(stoi(dummyString,0,10));
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
		}
		else
		{
			cout << "file open failed";
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

class Sqlite3_execute
{
public:

	char * sql;
	//parameter ist char*, execute(query)
	void execute(char * sql)
	{
		sqlite3 *db;
		char *err_msg = 0;

		int rc = sqlite3_open("test.db", &db);

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

		}
		rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
		/*
				int __rowid = sqlite3_last_insert_rowid(db);*/

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", err_msg);

			sqlite3_free(err_msg);
			sqlite3_close(db);
		}
		sqlite3_close(db);
	}

};
/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
//back up
class Sqlite3_insert
{
public:
	//construct
	Sqlite3_insert(PersonDB *_pdb)
	{
		pdb = _pdb;
	}

	PersonDB * pdb;

	void execute()
	{
		
		//iterator it zeicht einzel Person obejekt. 
		//und jede Person objekt hat drei Address objekt(home, work, shipping)
		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
			sqlite3 *db;
			char *err_msg = 0;

			//open DB-Server File
			int rc = sqlite3_open("test.db", &db);

			//error check
			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
			}

			//char[] sql initialize.
			char sql[300];
			memset(sql, 0, sizeof(char) * 300);

			//query write
			strcpy_s(
				sql,
				"CREATE TABLE IF NOT EXISTS Person(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, nachname text, vorname text, geburtsdatum text, stadt text, sex text);"
				"INSERT INTO Person(id,nachname,vorname,geburtsdatum,stadt,sex) VALUES(?,'"
			);
			strcat_s(
				sql,
				pdb->it->second->getNachname().c_str()
			);
			strcat_s(
				sql,
				"','"
			);
			strcat_s(
				sql,
				pdb->it->second->getVorname().c_str()
			);
			strcat_s(
				sql,
				"','"
			);
			strcat_s(
				sql,
				pdb->it->second->getGeburtsdatum().c_str()
			);
			strcat_s(
				sql,
				"','"
			);
			strcat_s(
				sql,
				pdb->it->second->getStadt().c_str()
			);
			strcat_s(
				sql,
				"','"
			);
			strcat_s(
				sql,
				pdb->it->second->getSex().c_str()
			);
			strcat_s(
				sql,
				"');"
			);

			//query execute. this function can be replaced for sqlite3_prepared,step,finalized.
			rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

			//int __rowid = sqlite3_last_insert_rowid(db);

			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "SQL error: %s\n", err_msg);

				sqlite3_free(err_msg);
				sqlite3_close(db);

			}
			sqlite3_close(db);


		}
	}
};


//User have to input PersId one more time
//because in a DB, 2 or more person, who have same name, can be exist.
//PersId!!
class Sqlite3_search_Id_from_name
{
public:

	char* execute()
	{
		sqlite3 *db;

		char *err_msg = 0;
		int rc = sqlite3_open("test.db", &db);//open argument test.db, return=>&db is pointing test db
		sqlite3_stmt* stmt = NULL;//stmt obj

		//int st = sqlite3_step(stmt);

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

			return 0;
		}

		cout << "Bitte schreiben Nachname um person ID zu suchen.";
		string dummyName = "";
		cin >> dummyName;

		char sql[300];
		memset(sql, 0, sizeof(char) * 300);//initializing
		strcpy_s(sql, "select id,nachname,vorname,geburtsdatum from Person where nachname = '");
		strcat_s(sql, dummyName.c_str());
		strcat_s(sql, "';");

		puts(sql);

		if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
		{
			//how many scrape? -> cols
			int cols = sqlite3_column_count(stmt);

			int result = 0;
			while (true)
			{
				result = sqlite3_step(stmt);
				if (result == SQLITE_ROW)
				{
					for (int col = 0; col < cols; col++)
					{
						//printConsole
						//printf("%s\t", (char*)sqlite3_column_text(stmt, col));
						
						//
						char PersId[10];
						memset(PersId, 0, sizeof(char) * 10);
						strcpy_s(PersId,(char*)sqlite3_column_text(stmt, col));
						printf("%s\t", PersId);
						

						//rowid
						/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
					}
					puts("");
				}
				else
				{
					break;
				}
			}
		}
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", err_msg);

			sqlite3_free(err_msg);
			sqlite3_close(db);

			return 0;
		}

		sqlite3_close(db);//SQLITE_OK or error
	}
};

class Sqlite3_insert_Addr
{
public:
	//construct
	Sqlite3_insert_Addr(PersonDB *_pdb)
	{
		pdb = _pdb;
	}

	PersonDB * pdb;
	///*map<int, Person*>::iterator  it;*/
	///*map<address::TYPE, address*>::iterator it_addr;*/
	///*int whileControl = 1;*/

	void execute()
	{
		/*while (whileControl)
		{*/
		//iterator it zeicht einzel Person obejekt. 
		//und jede Person objekt hat drei Address objekt(home, work, shipping)
		
		//test
		int _cinPersId=0;
		cout << "Bitte tun PersId rein. ";
		cin >> _cinPersId;
		//test
		
		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
			sqlite3 *db;
			char *err_msg = 0;

			//open DB-Server File
			int rc = sqlite3_open("test.db", &db);

			//error check
			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
			}
			
			//char[] sql initialize.
			char sql[3000];
			memset(sql, 0, sizeof(char) * 3000);

			for(pdb->it->second->it_addr=pdb->it->second->addresses.begin(); pdb->it->second->it_addr != pdb->it->second->addresses.end(); pdb->it->second->it_addr++)
			{
				//query write
				strcat_s
				(
					sql,
					"CREATE TABLE IF NOT EXISTS Address"
				);
				strcat_s
				(
					sql,
					pdb->it->second->it_addr->second->getStringType().c_str()
				);
				strcat_s
				(
					sql,
					"("
					"PersId  INTEGER REFERENCES Person(ID),"
					/*
					"AddrId  INTEGER PRIMARY KEY AUTOINCREMENT"
					"NOT NULL UNIQUE,"
					*/
					"Stadt   TEXT,"
					"Strasse TEXT,"
					"Haus_Nr TEXT,"
					"PLZ     TEXT"
					"); "
				);
				strcat_s
				(
					sql, 
					"INSERT INTO Address"
				);
				strcat_s
				(
					sql,
					pdb->it->second->it_addr->second->getStringType().c_str()
				);
				strcat_s
				(
					sql,
					"("
					"PersId,"
					/*AddrId*/
					"Stadt,Strasse,Haus_Nr,PLZ"
					")"
					"VALUES"
					"("
				);
				//PersId
				strcat_s
				(
					sql,
					to_string(_cinPersId).c_str()
				);
				//AddressTYPE(AddrId) : AUTO_INCREMENT -> NULL schreiben als Value
				strcat_s
				(
					sql,
					",'"
					/*",?,'"*/
				);
				//Stadt
				strcat_s
				(
					sql,
					pdb->it->second->it_addr->second->getStadt().c_str()
				);
				strcat_s
				(
					sql,
					"','"
				);
				//Strasse
				strcat_s
				(
					sql,
					pdb->it->second->it_addr->second->getStrasse().c_str()
				);
				strcat_s
				(
					sql,
					"','"
				);
				//Haus_Nr
				strcat_s
				(
					sql,
					pdb->it->second->it_addr->second->getHnr().c_str()
				);
				strcat_s
				(
					sql,
					"','"
				);
				//PLZ
				strcat_s
				(
					sql,
					pdb->it->second->it_addr->second->getPlz().c_str()
				);
				strcat_s
				(
					sql,
					"');"
				);
			}//for it_addr
			
			//query execute. this function can be replaced for sqlite3_prepared,step,finalized.
			rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

			/*int __rowid = sqlite3_last_insert_rowid(db);*/
			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "SQL error: %s\n", err_msg);

				sqlite3_free(err_msg);
				sqlite3_close(db);

			}
			sqlite3_close(db);
		}
	}
};



//pure functions, no side effect. pure input, pure output