#include "stdafx.h"
#include "Funktionen.h"
#include "PersonDB.h"
//#include <math.h>


CreateNewNonDuplicateUserNum::CreateNewNonDuplicateUserNum(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
int CreateNewNonDuplicateUserNum::execute()
	{
		/*int count = 0;*/

		int count = 1;

		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
			if (pdb->it->first == count)
			{
				count++;
			}
		}
		return count;
	}


RegisterNewPerson::RegisterNewPerson(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
void RegisterNewPerson::execute()
	{
		//int i = pdb->createNewNonDuplicateUserNum();
		cnndun = new CreateNewNonDuplicateUserNum(pdb);
		int _cnndun = cnndun->execute();
		Person* person = new Person(_cnndun);//Ruft es 'default Construct' auf.

											 //even if the Person class has been changed, data has strong intergrity.
											 //this is the reason why I must learn ood.
		person->registerAllOfMemberVariable();
		pdb->personen.emplace(make_pair(_cnndun, person));
		/*cout << "\nNeue Benutzer wird registriert.\n";
		cout << "Benutzer Nummer : " + to_string(_cnndun) << endl;*/
		person->printPersonalInfo();
		//added delete Pointer
		delete cnndun;
	}

SaveNewAddress::SaveNewAddress(PersonDB* _pdb)
	{
		pdb = _pdb;
	}
void SaveNewAddress::execute()
	{
		cout << "Bitte tun Sie die Usernumber rein.";
		int j;
		cin >> j;

		//access to person*, aufruf setElementToAddresses().
		pdb->personen[j]->setElementToAddresses();
		/*//1.select AddrType in map_container of the Person*	2.call makeObjAddress  3.put it in.
		pers->addresses.emplace(make_pair(selectType(), pers->makeObjAdress()));*/
	}

DeletePerson::DeletePerson(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
void DeletePerson::execute()
	{
		int userNum;
		cout << "input user Number";
		cin >> userNum;
		pdb->personen.erase(userNum);
	}

SearchInfo::SearchInfo(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
void SearchInfo::execute()
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

ChangeInfo::ChangeInfo(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}
void ChangeInfo::execute()
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

ViewAllInfo::ViewAllInfo(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
void ViewAllInfo::execute()
	{
		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
			//pdb->it->second : Person*
			pdb->it->second->printPersonalInfo();
		}
	}

//usernum logic check!!!!!!!!!!!!!
ImportCSVFile::ImportCSVFile(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
void ImportCSVFile::execute()//ifstream
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

				person->setSex(pdb->checkSexAndPutNumOut(dummyString));
				//int값을 setSex()의 argument로 넣는다.

				getline(iMyFile, dummyString, '\n');
				//받은 dummyString값을 int로 바꾸고
				person->setStadt(pdb->checkSexAndPutNumOut(dummyString));

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

ImportTXTFile::ImportTXTFile(PersonDB* _pdb)
	{
		pdb = _pdb;
	}
void ImportTXTFile::execute()//ifstream
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
						person->setUserNum(stoi(dummyString, 0, 10));
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
						person->setSex(pdb->checkSexAndPutNumOut(dummyString));
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

ExportCSVFile::ExportCSVFile(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
void ExportCSVFile::execute()//ofstream
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

ExportTXTFile::ExportTXTFile(PersonDB *_pdb)
	{
		pdb = _pdb;
	}
void ExportTXTFile::execute()
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

void Sqlite_execute::execute(char * sql)
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
/*printf("%i\t", sqlite3_last_insert_rowid(db));*/

Sqlite_insert_pers::Sqlite_insert_pers(PersonDB *_pdb)
	{
		pdb = _pdb;
	}
void Sqlite_insert_pers::execute()
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
				//"CREATE TABLE IF NOT EXISTS Person(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, nachname text, vorname text, geburtsdatum text, stadt text, sex text);"
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

//The sqlite3_finalize() function is called to delete a prepared statement.
Sqlite_insert_PersAddr::Sqlite_insert_PersAddr(PersonDB *_pdb)
	{
		pdb = _pdb;
	}
void Sqlite_insert_PersAddr::execute()
	{
		//iterator it zeicht einzel Person obejekt. 
		//und jede Person objekt hat drei Address objekt(home, work, shipping)
		for (_it_pers = pdb->personen.begin(); _it_pers != pdb->personen.end(); _it_pers++)
		{
			//PersId = 0;
			err_msg = 0;
			sqlite3_stmt* stmt = NULL;

			//open DB-Server File
			rc = sqlite3_open("test.db", &db);

			//error check
			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);
			}

			//char[] sql initialize.

			memset(sql, 0, sizeof(char) * 3000);

			//query write
			strcpy_s(
				sql,
				"CREATE TABLE IF NOT EXISTS Person(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, nachname text, vorname text, geburtsdatum text, stadt text, sex text);"
				"INSERT INTO Person(id,nachname,vorname,geburtsdatum,stadt,sex) VALUES(?,'"
			);
			strcat_s(sql, _it_pers->second->getNachname().c_str());
			strcat_s(sql, "','");
			strcat_s(sql, _it_pers->second->getVorname().c_str());
			strcat_s(sql, "','");
			strcat_s(sql, _it_pers->second->getGeburtsdatum().c_str());
			strcat_s(sql, "','");
			strcat_s(sql, _it_pers->second->getStadt().c_str());
			strcat_s(sql, "','");
			strcat_s(sql, _it_pers->second->getSex().c_str());
			strcat_s(sql, "');");

			//last_rowId = sqlite3_last_insert_rowid(db);
			//query execute. this function can be replaced for sqlite3_prepared,step,finalized.
			rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
			//int __rowid = sqlite3_last_insert_rowid(db);
			last_rowId = sqlite3_last_insert_rowid(db);



			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "SQL error: %s\n", err_msg);

				sqlite3_free(err_msg);
				sqlite3_close(db);
			}

			//test~~~~~~~~~~~~~~~~~
			//sqlite3_close(db);
			sqlite3_finalize(stmt);
			//????
			rc = 0;
			//test1~~~~~~~~~~~~~~~~~~~~~~~~~~~//
			//PersId = new char[10];
			memset(PersId, 0, sizeof(char) * 20);
			strcat_s(PersId, sqlite_getPersId_from_rowid(last_rowId).c_str());

			for (_it_addr = _it_pers->second->addresses.begin(); _it_addr != _it_pers->second->addresses.end(); _it_addr++)
			{
				err_msg = 0;
				//rc = sqlite3_open("test.db", &db);

				if (rc != SQLITE_OK)
				{
					fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
					sqlite3_close(db);
				}
				//test
				memset(sql, 0, sizeof(char) * 3000);
				//test

				//query write
				strcat_s(sql, "CREATE TABLE IF NOT EXISTS Address");
				strcat_s(sql, _it_addr->second->getStringType().c_str());
				strcat_s(sql, "(PersId  INTEGER REFERENCES Person(ID),Stadt TEXT,Strasse TEXT,Haus_Nr TEXT,PLZ TEXT); ");
				strcat_s(sql, "INSERT INTO Address");
				strcat_s(sql, _it_addr->second->getStringType().c_str());
				strcat_s(sql, "(PersId,Stadt,Strasse,Haus_Nr,PLZ) VALUES(");
				//PersId
				//error
				strcat_s(sql, PersId);
				strcat_s(sql, ",'");
				//Stadt
				strcat_s(sql, _it_addr->second->getStadt().c_str());
				strcat_s(sql, "','");
				//Strasse
				strcat_s(sql, _it_addr->second->getStrasse().c_str());
				strcat_s(sql, "','");
				//Haus_Nr
				strcat_s(sql, _it_addr->second->getHnr().c_str());
				strcat_s(sql, "','");
				//PLZ
				strcat_s(sql, _it_addr->second->getPlz().c_str());
				strcat_s(sql, "');");

				rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

				if (rc != SQLITE_OK)
				{
					fprintf(stderr, "SQL error: %s\n", err_msg);

					sqlite3_free(err_msg);
					sqlite3_close(db);
				}
				//test~~~~~~~~~~~~~~~~~
				//sqlite3_close(db);
				//The sqlite3_finalize() function is called to delete a prepared statement.
				sqlite3_finalize(stmt);
			}

			//test1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
			sqlite3_close(db);
		}
	}
string Sqlite_insert_PersAddr::sqlite_getPersId_from_rowid(int _last_rowId)
	{

		//string _sPersId;
		char _PersId[10];
		memset(_PersId, 0, sizeof(char) * 10);
		//int iPersId;
		//char *
		err_msg = 0;
		rc = sqlite3_open("test.db", &db);//open argument test.db, return=>&db is pointing test db
		stmt = NULL;//stmt obj

		int st = sqlite3_step(stmt);

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

			return 0;
		}

		char sql[3000];
		memset(sql, 0, sizeof(char) * 3000);//initializing
		strcpy_s(sql, "select id from Person where rowid = ");
		strcat_s(sql, to_string(_last_rowId).c_str());
		strcat_s(sql, ";");

		//?
		//puts(sql);

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

						//memset(_PersId, 0, sizeof(char) * 10);
						//(int)sqlite3_column_int(stmt, col);
						strcpy_s(_PersId, (char*)sqlite3_column_text(stmt, col));
						//strcpy_s(PersId, to_string((int)sqlite3_column_int(stmt, col)).c_str());


						//rowid
						/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
					}
					string _sPersId(_PersId);
					return _sPersId;
					//return _PersId;
					//puts("");
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

//User have to input PersId one more time
//because in a DB, 2 or more person, who have same name, can be exist.
//PersId!!
bool Check_the_existence_of_login_id_in_DB::execute(string _login_id)
	{
		sqlite3 *db;
		char *err_msg = 0;
		int rc = sqlite3_open("test.db", &db);
		sqlite3_stmt* stmt = NULL;
		char _existence[100];


		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);
			//return 0;
		}

		char sql[300];
		memset(sql, 0, sizeof(char) * 300);//initializing
		strcpy_s(sql, "select exists (select * from person where login_id ='");
		strcat_s(sql, _login_id.c_str());
		strcat_s(sql, "');");

		//puts(sql);

		if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
		{
			//how many scrape? -> cols
			int cols = sqlite3_column_count(stmt);

			int result = 0;

			int while_i = 1;
			while (while_i)
			{

				result = sqlite3_step(stmt);
				if (result == SQLITE_ROW)
				{

					for (int col = 0; col < cols; col++)
					{
						memset(_existence, 0, sizeof(char) * 100);
						strcpy_s(_existence, (char*)sqlite3_column_text(stmt, col));
					}

				}

				else
				{
					while_i = 0;
				}
			}

		}
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", err_msg);

			sqlite3_free(err_msg);
			sqlite3_close(db);

			//return 0;
		}

		sqlite3_close(db);//SQLITE_OK or error
		if (stoi(_existence) == 0)
		{
			cout << "ID existiert nicht\n";
			sqlite3_close(db);
			return false;
		}
		else if (stoi(_existence) == 1)
		{
			sqlite3_close(db);
			return true;
		}
	}


char* Sqlite_search_Id_from_name::execute()
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

		//puts(sql);

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

						char PersId[100];
						memset(PersId, 0, sizeof(char) * 100);
						strcpy_s(PersId, (char*)sqlite3_column_text(stmt, col));
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

Sqlite_add_Addr_toPers::Sqlite_add_Addr_toPers(PersonDB *_pdb)
	{
		pdb = _pdb;
	}
void Sqlite_add_Addr_toPers::execute()
	{
		//selectType = new String_SelectAddrType();
		/*while (whileControl)
		{*/
		//iterator it zeicht einzel Person obejekt. 
		//und jede Person objekt hat drei Address objekt(home, work, shipping)

		//test
		int _cinPersId = 0;
		cout << "Bitte tun PersId rein. ";
		cin >> _cinPersId;
		//test

		/*for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
		{
		*/
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

		/*for (pdb->it->second->it_addr = pdb->it->second->addresses.begin(); pdb->it->second->it_addr != pdb->it->second->addresses.end(); pdb->it->second->it_addr++)
		{*/
		//query write
		strcat_s
		(
			sql,
			"CREATE TABLE IF NOT EXISTS Address"
		);


		//string _type = selectType->execute();
		int Addr_choice;
		string _type;
		cout << "1.home 2.work 3.shipping ";
		cout << "\nWelche Addresse moechten Sie Speichern? ";
		cin >> Addr_choice;

		switch (Addr_choice)
		{
		case 1:
			_type = "home";
			break;
		case 2:
			_type = "work";
			break;
		case 3:
			_type = "shipping";
			break;
		default:
			cout << "error";
			break;
		}
		strcat_s
		(
			sql,
			_type.c_str()
			//pdb->it->second->it_addr->second->getStringType().c_str()
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
			_type.c_str()
			//pdb->it->second->it_addr->second->getStringType().c_str()
		);
		strcat_s
		(
			sql,
			"("
			"PersId,Stadt,Strasse,Haus_Nr,PLZ"
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
		string dummy = "";
		cout << "Stadt :";
		cin >> dummy;
		strcat_s
		(
			sql,
			dummy.c_str()
			//pdb->it->second->it_addr->second->getStadt().c_str()
		);
		strcat_s
		(
			sql,
			"','"
		);
		//Strasse
		dummy = "";
		cout << "Strasse :";
		cin >> dummy;
		strcat_s
		(
			sql,
			dummy.c_str()
			//pdb->it->second->it_addr->second->getStrasse().c_str()
		);
		strcat_s
		(
			sql,
			"','"
		);
		//Haus_Nr
		dummy = "";
		cout << "Strasse :";
		cin >> dummy;
		strcat_s
		(
			sql,
			dummy.c_str()
			//pdb->it->second->it_addr->second->getHnr().c_str()
		);
		strcat_s
		(
			sql,
			"','"
		);
		//PLZ
		dummy = "";
		cout << "PLZ :";
		cin >> dummy;
		strcat_s
		(
			sql,
			dummy.c_str()
			//pdb->it->second->it_addr->second->getPlz().c_str()
		);
		strcat_s
		(
			sql,
			"');"
		);
		/*}*///for it_addr

			 //query execute. this function can be replaced for sqlite3_prepared,step,finalized.
		rc = sqlite3_exec(db, sql, 0, 0, &err_msg);


		/*int __rowid = sqlite3_last_insert_rowid(db);*/
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", err_msg);

			sqlite3_free(err_msg);
			sqlite3_close(db);

		}
		cout << "Addresse hat hinzugefuegt." << endl;
		sqlite3_close(db);
	}

char* Search_prodName_from_ProdId::execute(int _prod_id)
	{
		sqlite3 *db;

		char *err_msg = 0;
		int rc = sqlite3_open("test.db", &db);
		sqlite3_stmt* stmt = NULL;


		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

			return 0;
		}

		char sql[300];
		memset(sql, 0, sizeof(char) * 300);
		strcpy_s(sql, "select name from Product where id = '");
		strcat_s(sql, to_string(_prod_id).c_str());
		strcat_s(sql, "';");

		puts(sql);

		if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
		{
			int cols = sqlite3_column_count(stmt);

			int result = 0;
			while (true)
			{
				result = sqlite3_step(stmt);
				if (result == SQLITE_ROW)
				{
					cout << "ausgewähltes Produkt : ";
					for (int col = 0; col < cols; col++)
					{
						//printConsole
						//printf("%s\t", (char*)sqlite3_column_text(stmt, col));

						char _ProdName[100];
						memset(_ProdName, 0, sizeof(char) * 100);
						strcpy_s(_ProdName, (char*)sqlite3_column_text(stmt, col));
						printf("%s\n", _ProdName);
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


string String_SelectAddrType::execute()
	{
		int Addr_choice;
		string _type;
		cout << "1.home 2.work 3.shipping ";
		cout << "\nWelche Addresse moechten Sie Speichern? ";
		cin >> Addr_choice;

		switch (Addr_choice)
		{
		case 1:
			_type = "home";
			break;
		case 2:
			_type = "work";
			break;
		case 3:
			_type = "shipping";
			break;
		default:
			cout << "error";
			break;
		}

		return _type;
	}

/*bool bool_login_stmt;
string activated_login_id;
int activated_pers_id;*/

bool Login_stmt::is_Login()
	{
		return bool_login_stmt;
	}
void Login_stmt::set_login_stmt(bool b)
	{
		bool_login_stmt = b;
	}
void Login_stmt::logout()
	{
		bool_login_stmt = false;
		activated_login_id = "default";
		activated_pers_id = 0;
	}

bool Login_stmt::bool_login_stmt = false;
string Login_stmt::activated_login_id = "default";
int Login_stmt::activated_pers_id = 0;


void Login::execute()
	{
		login_stmt = new Login_stmt();
		int switch_i = 0;
		if (login_stmt->bool_login_stmt == true)
		{

			cout << "\n0.zurueck zum Startbildschirm   1.Einloggen mit Andere ID    2.Ausloggen \nEs gibt eine ID, die bereits angemeldet ist. Was moechten Sie tun?";
			cin >> switch_i;
			switch (switch_i)
			{
			case 0: break;

			case 1:
				login_stmt->logout();
				login = new Login();
				login->execute();
				break;
			case 2:
				login_stmt->logout();
				break;
			}

		}
		if (login_stmt->bool_login_stmt == false && switch_i != 2)
		{


			cout << "< login >";
			string dummyid;
			cout << "input your ID : ";
			cin >> dummyid;

			string dummypw;
			cout << "input your PW : ";
			cin >> dummypw;

			sqlite3 *db;
			sqlite3_stmt* stmt = NULL;
			char *err_msg = 0;
			int rc = sqlite3_open("test.db", &db);

			if (rc != SQLITE_OK)
			{
				fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
				sqlite3_close(db);

				//return 0;
			}

			char sql[300];
			memset(sql, 0, sizeof(char) * 300);//initializing
			strcpy_s(sql, "select login_pw from Person where login_id='");
			strcat_s(sql, dummyid.c_str());
			strcat_s(sql, "';");

			/*puts(sql);*/
			if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
			{
				//how many scrape? -> cols
				int cols = sqlite3_column_count(stmt);

				int result = 0;
				int while_i = 1;
				while (while_i)
				{
					result = sqlite3_step(stmt);
					if (result == SQLITE_ROW)
					{
						char _login_pw[100];
						for (int col = 0; col < cols; col++)
						{
							//printConsole
							//printf("%s\t", (char*)sqlite3_column_text(stmt, col));

							//
							/*char PersId[100];*/
							memset(_login_pw, 0, sizeof(char) * 100);
							strcpy_s(_login_pw, (char*)sqlite3_column_text(stmt, col));


							//printf("%s\t", _login_pw);
						}
						//login success. login statement = true.
						if (_login_pw == dummypw)
						{
							login_stmt->bool_login_stmt = true;
							login_stmt->activated_login_id = dummyid;
						}
						else
						{
							cout << "Password is wrong.";
						}
					}
					else
					{
						while_i = 0;
					}
				}
			}
			if (rc != SQLITE_OK)
			{
				//fprintf(stderr, "SQL error: %s\n", err_msg);

				sqlite3_free(err_msg);
				sqlite3_close(db);

				//return 0;
			}
			sqlite3_close(db);
			//!!!!!!!!!!!!!!!!Hier einmal die sqlite3 funktion war funktioniert.

			//von hier neue Runde!!!!!
			if (login_stmt->bool_login_stmt == true)
			{

				err_msg = 0;
				if (rc != SQLITE_OK)
				{
					fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
					sqlite3_close(db);

					//return 0;
				}

				memset(sql, 0, sizeof(char) * 300);//initializing
				strcpy_s(sql, "select id from Person where login_id='");
				strcat_s(sql, dummyid.c_str());
				strcat_s(sql, "';");

				/*puts(sql);*/

				if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
				{
					//how many time scrape? -> cols
					int cols = sqlite3_column_count(stmt);

					int result = 0;

					int while_i = 1;
					while (while_i)
					{
						result = sqlite3_step(stmt);
						if (result == SQLITE_ROW)
						{
							char _pers_id[100];
							for (int col = 0; col < cols; col++)
							{
								//printConsole
								//printf("%s\t", (char*)sqlite3_column_text(stmt, col));

								//
								/*char PersId[100];*/
								memset(_pers_id, 0, sizeof(char) * 100);
								strcpy_s(_pers_id, (char*)sqlite3_column_text(stmt, col));
								//printf("%s\t", _pers_id);


								//rowid
								/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
							}
							//login success. login statement = true.
							login_stmt->activated_pers_id = stoi(_pers_id);
						}
						else
						{
							while_i = 0;
						}
					}
				}
				if (rc != SQLITE_OK)
				{
					//fprintf(stderr, "SQL error: %s\n", err_msg);
					printf("login failed.");

					sqlite3_free(err_msg);
					sqlite3_close(db);

					//return 0;
				}
			}

			sqlite3_close(db);



			bool existence_login_id = false;

			//test!!!!!!!!!!!!!!!!!!!!
			check_the_existence_of_login_id_in_DB = Check_the_existence_of_login_id_in_DB();

			/*existence_login_id = */
			check_the_existence_of_login_id_in_DB.execute(dummyid);
		}



		/*if (existence_login_id == false)
		{
		cout << "ID existiert nicht.";
		}*/
	}//id is also a PK,UNIQUE KEY,NOT NULL

void Buy_Product::execute()
	{
		//check the login Statement
		login_stmt = new Login_stmt();
		int while_i = 1;

		//loginstatement = true
		if (login_stmt->bool_login_stmt == true)
		{
			while_i = 0;
		}

		//If login_statement is false, login.
		while (while_i)
		{
			cout << "Diese Funktion erfordert eine Anmeldung.\n";
			login = new Login();
			login->execute();

			if (login_stmt->bool_login_stmt == true)
			{
				while_i = 0;
			}
		}


		int func_control = 0;
		if (login_stmt->bool_login_stmt == true)
		{
			func_control = 1;
		}

		
		int prod_id;
		cout << "schreiben Sie product id : ";
		cin >> prod_id;

		//nur zeigen die Produkt_Information. 
		see_Produkt_detail_2 obj_see_Produkt_detail_2 = see_Produkt_detail_2();
		obj_see_Produkt_detail_2.execute(prod_id);
		
		show_haltemenge odj_show_haltemenge = show_haltemenge();

		int Maximal_waehlbare_Menge = odj_show_haltemenge.execute(prod_id);
		cout << "\nMaximal waehlbare Menge : " << Maximal_waehlbare_Menge;
		
		while (func_control == 1)
		{	
			//Bestellmenge eingeben
			cout << "\n\n-------------------------------------------------------------------\nWie viel moechten Sie kaufen?";
			
			int quantity = 0;
			cin >> quantity;

			//okay(Maximal_waehlbare_Menge>=quantity)
			if (Maximal_waehlbare_Menge>=quantity)
			{
				cout << "1.CreditCard   2.Bargeld(von Kontostand)\nWelche Zahlungsmethode benutzen Sie? ";
				int _Zahlungsmethode = 0;
				cin >> _Zahlungsmethode;
				
				switch (_Zahlungsmethode)
				{

				//Bargeld von Kontostand
				case 2:
					bring_Kontostand obj_bring_Kontostand = bring_Kontostand();
					int _kontostand = obj_bring_Kontostand.execute(login_stmt->activated_pers_id);

					bring_Preis obj_bring_Preis = bring_Preis();
					int _Insgesamte_Zahl = obj_bring_Preis.execute(prod_id)*quantity;

					//wenn kontostand ist genug. 
					if(_kontostand>=_Insgesamte_Zahl)
					{
						sql_purchase_transaction(prod_id, quantity);
						func_control = 0;
					}
					else
					{
						cout << "Die Transaktion kann aufgrund eines unzureichenden Kontostands nicht fortgesetzt werden.\n";
						
						cout << "\n0. bestellung unterbrechen   1. konto stand charging function " <<"\nwas moechten Sie tun?";
						int switch_on = 0;
						switch (switch_on)
						{
						case 0 :
							func_control = 0; break;
						case 1 : 
							charge_Konto_Bargeld * obj_charge_Konto_Bargeld = new charge_Konto_Bargeld();
							obj_charge_Konto_Bargeld->execute(login_stmt->activated_pers_id);
							break;
						}
					}
					break;
				}
			}

			//not okay(Maximal_waehlbare_Menge<quantity)
			else
			{
				cout << "Die Abnahmemenge darf die maximale waehlbare Menge nicht ueberschreiten.\n"; 
			}
			
			
			//check that both of factor, kontostand is bigger than price of product and    
			//update prod_quantity from product where prod_id="_prod_id"--> if(product(haltmenge)-kaufsmenge>=0)
			//update balance from person where pers_id = "_pers_id" --> if(balance-(menge*price)>=0)
			
			//insert into purchase(pers_id,prod_id,quantity) VALUES(login_stmt->activated_pers_id,prod_id,quantity);...
			
		}

	}
char* Buy_Product::sql_purchase_transaction(int _prod_id, int _bestell_Menge)
{
	
	//통장잔고(구매자)열과 보유수량(판매자)열을 잠근다. (lock(kontostand) where pers_id = "" )
	//1. 보유수량(판매자)을 구매수량(purchase_quantity)만큼 제한다. (replace into product(Haltemenge) values('before_Haltemenge'-'purchase_quantity');)
	//2. 통장잔고(구매자)를 판매가격*구매수량 만큼 제한다.(replace into person(kontostand) values('before_kontostand'-('purchase_price'*'purchase_quantity'));
	//3. 구매열을 추가한다.(insert into purchase(pers_id, prod_id, quantity) values('??','??','??');)
	


	sqlite3 *db;
	sqlite3_stmt* stmt = NULL;
	char *err_msg = 0;

	//open DB-Server File
	int rc = sqlite3_open("test.db", &db);

	//error checkt
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		//break;
		return 0;
	}

	bring_Preis obj_bring_Preis = bring_Preis();
	double _insgesamt_Zahlung = round(obj_bring_Preis.execute(_prod_id) * _bestell_Menge*100)/100;

	//char[] sql initialize.
	char sql[300];
	memset(sql, 0, sizeof(char) * 300);
	//모든 조건이 성립할 경우 트랜잭션을 시작한다.
	//query write
	//sql "begin transaction;...
	/*UPDATE Product SET Haltemenge=Haltemenge-4 WHERE id=3;
UPDATE Person SET Kontostand=Kontostand-(select price from product where id=3)*4 WHERE id=3;
insert into purchase(pers_id, prod_id, quantity) values(3,3,4);*/
	strcpy_s(sql, "begin;");
	strcat_s(sql, "INSERT INTO purchase(pers_id,prod_id,quantity) VALUES(");
	strcat_s(sql, to_string(login_stmt->activated_pers_id).c_str());
	strcat_s(sql, ",");
	strcat_s(sql, to_string(_prod_id).c_str());
	strcat_s(sql, ",");
	strcat_s(sql, to_string(_bestell_Menge).c_str());
	strcat_s(sql, ");");

	strcat_s(sql, "UPDATE Product SET Haltemenge=Haltemenge-");
	strcat_s(sql, to_string(_bestell_Menge).c_str());
	strcat_s(sql, " WHERE id=");
	strcat_s(sql, to_string(_prod_id).c_str());
	strcat_s(sql, ";");
	
	strcat_s(sql, "UPDATE Person SET Kontostand=Kontostand-");
	strcat_s(sql, to_string(_insgesamt_Zahlung).c_str());
	strcat_s(sql, " WHERE id=");
	strcat_s(sql, to_string(login_stmt->activated_pers_id).c_str());
	strcat_s(sql, ";");
	strcat_s(sql, "commit;");

	//puts(sql);
	//query execute. this function can be replaced for sqlite3_prepared,step,finalized.
	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

	//int __rowid = sqlite3_last_insert_rowid(db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);

		sqlite3_free(err_msg);
		sqlite3_close(db);
		//break;

		//func_control = 0;
	}
	cout << "Sie haben die Produkte erfolgreich gekauft";
	sqlite3_close(db);
	//func_control = 0;
}

char* Nachschlage_Kontostand::execute(int _pers_id)
{
	Login_stmt* login_stmt = new Login_stmt();
	if (login_stmt->bool_login_stmt == true)
	{
		sqlite3 *db;

		char *err_msg = 0;
		int rc = sqlite3_open("test.db", &db);
		sqlite3_stmt* stmt = NULL;


		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

			return 0;
		}

		char sql[300];
		memset(sql, 0, sizeof(char) * 300);
		strcpy_s(sql, "select Kontostand from Person where id = ");
		strcat_s(sql, to_string(_pers_id).c_str());
		strcat_s(sql, ";");

		puts(sql);

		if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
		{
			int cols = sqlite3_column_count(stmt);

			int result = 0;
			while (true)
			{
				result = sqlite3_step(stmt);
				if (result == SQLITE_ROW)
				{
					cout << "ausgewähltes Produkt : ";
					for (int col = 0; col < cols; col++)
					{
						//printConsole
						//printf("%s\t", (char*)sqlite3_column_text(stmt, col));

						char _Kontostand[100];
						memset(_Kontostand, 0, sizeof(char) * 100);
						strcpy_s(_Kontostand, (char*)sqlite3_column_text(stmt, col));
						printf("%s\n", _Kontostand);
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
	else
	{
		cout << "Diese Funktion steht nach dem Einloggen zur Verfuegung.";
	}
}

int bring_Kontostand::execute(int _pers_id)
{
	sqlite3 *db;
	sqlite3_stmt* stmt = NULL;
	char *err_msg = 0;
	int rc = sqlite3_open("test.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 0;
	}

	/*cout << "Bitte schreiben einen prod_id fuer product_detail zu sehen.";
	string dummyName = "";
	cin >> dummyName;
	*/
	char sql[300];
	memset(sql, 0, sizeof(char) * 300);//initializing
	strcpy_s(sql, "select Kontostand from Person where id=");
	/*strcat_s(sql, dummyName.c_str());*/
	strcat_s(sql, to_string(_pers_id).c_str());
	strcat_s(sql, ";");

char _Kontostand[100];
	//puts(sql);

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
				
				memset(_Kontostand, 0, sizeof(char) * 100);

				for (int col = 0; col < cols; col++)
				{

					//printConsole
					//printf("%s\t", (char*)sqlite3_column_text(stmt, col));

					strcpy_s(_Kontostand, (char*)sqlite3_column_text(stmt, col));
					//printf("%s\t", PersId);


					//rowid
					/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
				}

				
				//puts("");
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
	sqlite3_close(db);
	return stoi(_Kontostand);
}

char* charge_Konto_Bargeld::execute(int _pers_id)
{
	Login_stmt * obj_login_stmt = new Login_stmt();
	if (obj_login_stmt->bool_login_stmt == true)
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

		cout << "Wie viel Geld ueberweisen Sie?.";
		int dummyGeld = 0;
		cin >> dummyGeld;

		char sql[300];
		memset(sql, 0, sizeof(char) * 300);//initializing
		strcpy_s(sql, "UPDATE Person SET Kontostand=Kontostand+");
		strcat_s(sql, to_string(dummyGeld).c_str());
		strcat_s(sql, " where id = ");//UPDATE Person SET Kontostand=Kontostand-'purchase_price'*4 WHERE id=3;
		strcat_s(sql, to_string(_pers_id).c_str());
		strcat_s(sql, ";");

		//puts(sql);
		rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
		//if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
		//{
		//	//how many scrape? -> cols
		//	int cols = sqlite3_column_count(stmt);
		//	int result = 0;
		//	while (true)
		//	{
		//		result = sqlite3_step(stmt);
		//		if (result == SQLITE_ROW)
		//		{
		//			for (int col = 0; col < cols; col++)
		//			{
		//				//printConsole
		//				//printf("%s\t", (char*)sqlite3_column_text(stmt, col));
		//				char PersId[100];
		//				memset(PersId, 0, sizeof(char) * 100);
		//				strcpy_s(PersId, (char*)sqlite3_column_text(stmt, col));
		//				printf("%s\t", PersId);
		//				//rowid
		//				/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
		//			}
		//			puts("");
		//		}
		//		else
		//		{
		//			break;
		//		}
		//	}
		//}
		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "SQL error: %s\n", err_msg);

			sqlite3_free(err_msg);
			sqlite3_close(db);

			return 0;
		}

		sqlite3_close(db);//SQLITE_OK or error
	}
	else
	{
		cout << "Diese Funktion steht nach dem Einloggen zur Verfuegung.";
	}
}

char* see_Produkt_detail::execute()
	{
		sqlite3 *db;
		sqlite3_stmt* stmt = NULL;
		char *err_msg = 0;
		int rc = sqlite3_open("test.db", &db);

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

			return 0;
		}

		cout << "Bitte schreiben einen prod_id fuer product_detail zu sehen.";
		string dummyName = "";
		cin >> dummyName;

		char sql[300];
		memset(sql, 0, sizeof(char) * 300);//initializing
		strcpy_s(sql, "select id,name,price,gewicht from Product where id=");
		strcat_s(sql, dummyName.c_str());
		strcat_s(sql, ";");

		//puts(sql);

		if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
		{
			cout << "id\tname\tprice\tgewicht\n";
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
						char PersId[100];
						memset(PersId, 0, sizeof(char) * 100);
						strcpy_s(PersId, (char*)sqlite3_column_text(stmt, col));
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
		sqlite3_close(db);

	}

void see_Produkt_detail_2::execute(int _prod_id)
{
	sqlite3 *db;
	sqlite3_stmt* stmt = NULL;
	char *err_msg = 0;
	int rc = sqlite3_open("test.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		//return 0;
	}

	/*cout << "Bitte schreiben einen prod_id fuer product_detail zu sehen.";
	string dummyName = "";
	cin >> dummyName;
	*/
	char sql[300];
	memset(sql, 0, sizeof(char) * 300);//initializing
	strcpy_s(sql, "select id,name,price,gewicht from Product where id=");
	/*strcat_s(sql, dummyName.c_str());*/
	strcat_s(sql, to_string(_prod_id).c_str()); 
	strcat_s(sql, ";");

	//puts(sql);

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
	{
		cout << "id\tname\tprice\tgewicht\n";
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
					char PersId[100];
					memset(PersId, 0, sizeof(char) * 100);
					strcpy_s(PersId, (char*)sqlite3_column_text(stmt, col));
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

		//return 0;
	}
	sqlite3_close(db);

}

double bring_Preis::execute(int _prod_id)
{
	sqlite3 *db;
	sqlite3_stmt* stmt = NULL;
	char *err_msg = 0;
	int rc = sqlite3_open("test.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 0;
	}

	/*cout << "Bitte schreiben einen prod_id fuer product_detail zu sehen.";
	string dummyName = "";
	cin >> dummyName;
	*/
	char sql[300];
	memset(sql, 0, sizeof(char) * 300);//initializing
	strcpy_s(sql, "select Price from Product where id=");
	/*strcat_s(sql, dummyName.c_str());*/
	strcat_s(sql, to_string(_prod_id).c_str());
	strcat_s(sql, ";");

	char _Price[100];
	//puts(sql);

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
				
				memset(_Price, 0, sizeof(char) * 100);

				for (int col = 0; col < cols; col++)
				{

					//printConsole
					//printf("%s\t", (char*)sqlite3_column_text(stmt, col));

					strcpy_s(_Price, (char*)sqlite3_column_text(stmt, col));
					//printf("%s\t", PersId);


					//rowid
					/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
				}

				
				//puts("");
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
	sqlite3_close(db);
	
	return stod(_Price);
}


int show_haltemenge::execute(int _prod_id)
{
	sqlite3 *db;
	sqlite3_stmt* stmt = NULL;
	char *err_msg = 0;
	int rc = sqlite3_open("test.db", &db);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 0;
	}

	/*cout << "Bitte schreiben einen prod_id fuer product_detail zu sehen.";
	string dummyName = "";
	cin >> dummyName;
	*/
	char sql[300];
	memset(sql, 0, sizeof(char) * 300);//initializing
	strcpy_s(sql, "select Haltemenge from Product where id=");
	/*strcat_s(sql, dummyName.c_str());*/
	strcat_s(sql, to_string(_prod_id).c_str());
	strcat_s(sql, ";");
	
	char haltemenge[100];
	//puts(sql);

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
				
				memset(haltemenge, 0, sizeof(char) * 100);
				
				for (int col = 0; col < cols; col++)
				{
					
					//printConsole
					//printf("%s\t", (char*)sqlite3_column_text(stmt, col));

					strcpy_s(haltemenge, (char*)sqlite3_column_text(stmt, col));
					//printf("%s\t", PersId);


					//rowid
					/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
				}
				
				
				//puts("");
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
	sqlite3_close(db);
	return stoi(haltemenge);
}

char* search_produkt_with_keyword::execute()
	{
		sqlite3 *db;
		sqlite3_stmt* stmt = NULL;
		char *err_msg = 0;

		int rc = sqlite3_open("test.db", &db);

		if (rc != SQLITE_OK)
		{
			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
			sqlite3_close(db);

			return 0;
		}

		cout << "Schreiben Sie einen Keyword : ";
		string dummyName = "";
		cin >> dummyName;

		char sql[300];
		memset(sql, 0, sizeof(char) * 300);//initializing
		strcpy_s(sql, "select id,name from Product where name LIKE '%");
		strcat_s(sql, dummyName.c_str());
		strcat_s(sql, "%';");

		//puts(sql);

		if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
		{
			cout << "Produkt_id\tProdukt_name\n";
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
						char PersId[100];
						memset(PersId, 0, sizeof(char) * 100);
						strcpy_s(PersId, (char*)sqlite3_column_text(stmt, col));
						printf("%s\t\t", PersId);


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

		sqlite3_close(db);
	}

char* Sqlite_purchase_prod_process::execute()
	{
		bool Produkt_search_while = true;
		while (Produkt_search_while)
		{
			//q1 : was moechten Sie tun? (1.see the detail of produkt 2.search with other keyword 3.go back to start Page)
			int switch_i;
			cout <<
				"\n====================================================================="
				"\n0.zurueck zum Startbildschirm "
				"\n1.Produkt suchen   2.Detail des produkts suchen   3.Produkt kaufen"
				"\nwas moechten Sie tun?";
			cin >> switch_i;
			switch (switch_i)
			{
				//q1-case0: "exit", Produkt_search_while = 0
			case 0:
				Produkt_search_while = false;
				break;

				//q1-case1: Produkt_search_while = 1
			case 1:
				//input keyword for searching
				//sql = "select prod_id from produkt where like %keyword%;"
				search_prod_with_keyword = new search_produkt_with_keyword();
				search_prod_with_keyword->execute();
				break;

				//q1-case2: auflufen - 'see produkt detail', //Produkt_search_while = 0(kaufen funktion ist hier drin)
			case 2:
				see_prod_detail = new see_Produkt_detail();
				see_prod_detail->execute();
				break;

			case 3:
				buy_prod = new Buy_Product();
				buy_prod->execute();
				//noch nicht implementiert.
				break;
			}
		}
		return 0;
	}


