#ifndef FUNKTIONENE_H
#define FUNKTIONENE_H
//#include "Common.h"
#include "PersonDB.h"
#include <fstream>
#include <iostream>
#include "sqlite3.h"

using namespace std;


class CreateNewNonDuplicateUserNum
{
public:
	CreateNewNonDuplicateUserNum(PersonDB * _pdb);
	PersonDB * pdb;

	int execute();
};

class RegisterNewPerson
{
private:
	PersonDB * pdb;
	CreateNewNonDuplicateUserNum * cnndun;
public:
	RegisterNewPerson(PersonDB * _pdb);

	void execute();
};

class SaveNewAddress
{
public:
	SaveNewAddress(PersonDB* _pdb);

	PersonDB* pdb;

	void execute();
};

class DeletePerson
{
private:
	PersonDB * pdb;
public:
	DeletePerson(PersonDB * _pdb);
	void execute();
};

class SearchInfo
{
private:
	PersonDB * pdb;
public:
	SearchInfo(PersonDB * _pdb);
	void execute();

};

class ChangeInfo
{
private:
	PersonDB * pdb;
public:
	ChangeInfo(PersonDB * _pdb);
	void execute();
};

class ViewAllInfo
{
public:
	ViewAllInfo(PersonDB * _pdb);
	PersonDB * pdb;
	void execute();
};
//usernum logic check!!!!!!!!!!!!!
class ImportCSVFile
{
public:
	ImportCSVFile(PersonDB * _pdb);

	PersonDB * pdb;

	void execute();
};

class ImportTXTFile
{
public:
	ImportTXTFile(PersonDB* _pdb);
	PersonDB * pdb;
	void execute();
};

class ExportCSVFile
{
public:
	ExportCSVFile(PersonDB * _pdb);
	PersonDB * pdb;


	void execute();

};

class ExportTXTFile
{
public:
	ExportTXTFile(PersonDB *_pdb);
	PersonDB * pdb;
	void execute();
};

class Sqlite_execute
{
public:

	char * sql;
	//parameter ist char*, execute(query)
	void execute(char * sql);

};
/*printf("%i\t", sqlite3_last_insert_rowid(db));*/

class Sqlite_insert_pers
{
public:
	//construct
	Sqlite_insert_pers(PersonDB *_pdb);

	PersonDB * pdb;

	void execute();
};

//The sqlite3_finalize() function is called to delete a prepared statement.
class Sqlite_insert_PersAddr
{
public:
	//construct
	Sqlite_insert_PersAddr(PersonDB *_pdb);

	PersonDB * pdb;

	map<address::TYPE, address*>::iterator _it_addr;
	map<int, Person*>::iterator _it_pers;

	char PersId[20];
	int last_rowId = 0;
	sqlite3 *db;
	sqlite3_stmt* stmt;
	char *err_msg;
	int rc;
	char sql[3000];

	//create Person Table, Insert Person wert
	void execute();
	string sqlite_getPersId_from_rowid(int _last_rowId);
};

//class Sqlite_insert_PersAddr
//{
//public:
//	//construct
//	Sqlite_insert_PersAddr(PersonDB *_pdb)
//	{
//		pdb = _pdb;
//	}
//
//	PersonDB * pdb;
//
//	map<address::TYPE, address*>::iterator _it_addr;
//	map<int, Person*>::iterator _it_pers;
//
//	char* PersId;
//	int last_rowId = 0;
//	sqlite3 *db;
//	sqlite3_stmt* stmt;
//	char *err_msg;
//	int rc;
//	char sql[3000];
//	
//	//create Person Table, Insert Person wert
//	void execute()
//	{
//		//iterator it zeicht einzel Person obejekt. 
//		//und jede Person objekt hat drei Address objekt(home, work, shipping)
//		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
//		{
//			//PersId = 0;
//			err_msg = 0;
//			sqlite3_stmt* stmt = NULL;
//
//			//open DB-Server File
//			rc = sqlite3_open("test.db", &db);
//
//			//error check
//			if (rc != SQLITE_OK)
//			{
//				fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//				sqlite3_close(db);
//			}
//
//			//char[] sql initialize.
//
//			memset(sql, 0, sizeof(char) * 3000);
//
//			//query write
//			strcpy_s(
//				sql,
//				"CREATE TABLE IF NOT EXISTS Person(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, nachname text, vorname text, geburtsdatum text, stadt text, sex text);"
//				"INSERT INTO Person(id,nachname,vorname,geburtsdatum,stadt,sex) VALUES(?,'"
//			);
//			strcat_s(sql, pdb->it->second->getNachname().c_str());
//			strcat_s(sql, "','");
//			strcat_s(sql, pdb->it->second->getVorname().c_str());
//			strcat_s(sql, "','");
//			strcat_s(sql, pdb->it->second->getGeburtsdatum().c_str());
//			strcat_s(sql, "','");
//			strcat_s(sql, pdb->it->second->getStadt().c_str());
//			strcat_s(sql, "','");
//			strcat_s(sql, pdb->it->second->getSex().c_str());
//			strcat_s(sql, "');");
//
//			//last_rowId = sqlite3_last_insert_rowid(db);
//			//query execute. this function can be replaced for sqlite3_prepared,step,finalized.
//			rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
//			//int __rowid = sqlite3_last_insert_rowid(db);
//			last_rowId = sqlite3_last_insert_rowid(db);
//
//			if (rc != SQLITE_OK)
//			{
//				fprintf(stderr, "SQL error: %s\n", err_msg);
//
//				sqlite3_free(err_msg);
//				sqlite3_close(db);
//			}
//			sqlite3_close(db);
//		}
//	}
//
//	//Sqlite3_getPersId_from_rowid
//	//void test()
//	//{
//	//	//sqlite_getPersId_from_rowid(this->last_rowId); <-Functioniert perfekt.
//	//	PersId = sqlite_getPersId_from_rowid(this->last_rowId);
//	//	//printf("%s\n", persId);
//	//	//char* persId = malloc(sizeof(char) * 10);
//	//	
//	//	//strcpy_s(persId,sqlite_getPersId_from_rowid(this->last_rowId));
//	//	//printf(persId);
//	//}
//	
//	void execute2()
//	{
//		PersId = sqlite_getPersId_from_rowid(last_rowId);
//		
//		/*if (!pdb->it->second->addresses.empty())
//		{*/
//			//persId wert wrong
//			//char* persId = sqlite_getPersId_from_rowid(this->last_rowId);
//			
//			err_msg = 0;
//			rc = sqlite3_open("test.db", &db);
//
//			if (rc != SQLITE_OK)
//			{
//				fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//				sqlite3_close(db);
//			}
//
//			//for (pdb->it->second->it_addr = pdb->it->second->addresses.begin(); pdb->it->second->it_addr != pdb->it->second->addresses.end(); pdb->it->second->it_addr++)
//			for(_it_addr = pdb->it->second->addresses.begin(); _it_addr != pdb->it->second->addresses.end(); _it_addr++)
//			{
//				//query write
//				strcat_s(sql, "CREATE TABLE IF NOT EXISTS Address");
//				strcat_s(sql, pdb->it->second->it_addr->second->getStringType().c_str());
//				strcat_s(sql, "(PersId  INTEGER REFERENCES Person(ID),Stadt TEXT,Strasse TEXT,Haus_Nr TEXT,PLZ TEXT); ");
//				strcat_s(sql, "INSERT INTO Address");
//				strcat_s(sql, pdb->it->second->it_addr->second->getStringType().c_str());
//				strcat_s(sql, "(PersId,Stadt,Strasse,Haus_Nr,PLZ) VALUES(");
//				//PersId
//				//error
//				strcat_s(sql, PersId);
//				strcat_s(sql, ",'");
//				//Stadt
//				strcat_s(sql, pdb->it->second->it_addr->second->getStadt().c_str());
//				strcat_s(sql, "','");
//				//Strasse
//				strcat_s(sql, pdb->it->second->it_addr->second->getStrasse().c_str());
//				strcat_s(sql, "','");
//				//Haus_Nr
//				strcat_s(sql, pdb->it->second->it_addr->second->getHnr().c_str());
//				strcat_s(sql, "','");
//				//PLZ
//				strcat_s(sql, pdb->it->second->it_addr->second->getPlz().c_str());
//				strcat_s(sql, "');");
//				rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
//			}
//			if (rc != SQLITE_OK)
//			{
//				fprintf(stderr, "SQL error: %s\n", err_msg);
//
//				sqlite3_free(err_msg);
//				sqlite3_close(db);
//			}
//			sqlite3_close(db);
//			//we have to access to Person(id) with rowId function, because id is autoincrement element.
//
//
//			//sqlite3_last_insert_rowid(db) function must be executed during the db obj is opened.
//			//last_rowId = sqlite3_last_insert_rowid(db);
//
//			//sqlite3_close(db);
//
//			//bring rowid
//
//			//cout << last_rowId+"\n";
//			//bring PersId from rowid
//			//PersId = Sqlite3_getPersId_from_rowid(last_rowId,db);
//			//memset(sql, 0, sizeof(char) * 3000);
//			//cout << PersId;
//			/*for (pdb->it->second->it_addr = pdb->it->second->addresses.begin(); pdb->it->second->it_addr != pdb->it->second->addresses.end(); pdb->it->second->it_addr++)
//			{
//				//query write
//				strcat_s(sql,"CREATE TABLE IF NOT EXISTS Address");
//				strcat_s(sql,pdb->it->second->it_addr->second->getStringType().c_str());
//				strcat_s(sql,"(PersId  INTEGER REFERENCES Person(ID),Stadt TEXT,Strasse TEXT,Haus_Nr TEXT,PLZ TEXT); ");
//				strcat_s(sql,"INSERT INTO Address");
//				strcat_s(sql,pdb->it->second->it_addr->second->getStringType().c_str());
//				strcat_s(sql,"(PersId,Stadt,Strasse,Haus_Nr,PLZ) VALUES(");
//				//PersId
//				strcat_s(sql,PersId);
//				strcat_s(sql,",'");
//				//Stadt
//				strcat_s(sql,pdb->it->second->it_addr->second->getStadt().c_str());
//				strcat_s(sql,"','");
//				//Strasse
//				strcat_s(sql,pdb->it->second->it_addr->second->getStrasse().c_str());
//				strcat_s(sql,"','");
//				//Haus_Nr
//				strcat_s(sql,pdb->it->second->it_addr->second->getHnr().c_str());
//				strcat_s(sql,"','");
//				//PLZ
//				strcat_s(sql,pdb->it->second->it_addr->second->getPlz().c_str());
//				strcat_s(sql,"');");
//				rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
//			}*/
//
//			//int __rowid = sqlite3_last_insert_rowid(db);
//			/*for (pdb->it->second->it_addr = pdb->it->second->addresses.begin(); pdb->it->second->it_addr != pdb->it->second->addresses.end(); pdb->it->second->it_addr++)
//			{
//				memset(sql, 0, sizeof(char) * 3000);
//				//query write
//				strcat_s(sql, "CREATE TABLE IF NOT EXISTS Address");
//				strcat_s(sql, pdb->it->second->it_addr->second->getStringType().c_str());
//				strcat_s(sql, "(PersId  INTEGER REFERENCES Person(ID),Stadt TEXT,Strasse TEXT,Haus_Nr TEXT,PLZ TEXT); ");
//				strcat_s(sql, "INSERT INTO Address");
//				strcat_s(sql, pdb->it->second->it_addr->second->getStringType().c_str());
//				strcat_s(sql, "(PersId,Stadt,Strasse,Haus_Nr,PLZ) VALUES(");
//				//PersId
//				strcat_s(sql, PersId);
//				strcat_s(sql, ",'");
//				//Stadt
//				strcat_s(sql, pdb->it->second->it_addr->second->getStadt().c_str());
//				strcat_s(sql, "','");
//				//Strasse
//				strcat_s(sql, pdb->it->second->it_addr->second->getStrasse().c_str());
//				strcat_s(sql, "','");
//				//Haus_Nr
//				strcat_s(sql, pdb->it->second->it_addr->second->getHnr().c_str());
//				strcat_s(sql, "','");
//				//PLZ
//				strcat_s(sql, pdb->it->second->it_addr->second->getPlz().c_str());
//				strcat_s(sql, "');");
//
//				rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
//			}
//			*/
//
//			//if (rc != SQLITE_OK)
//			//{
//			//	fprintf(stderr, "SQL error: %s\n", err_msg);
//			//
//			//	sqlite3_free(err_msg);
//			//	sqlite3_close(db);
//			//}
//
//
//		/*}*/
//
//		/*
//		for (pdb->it->second->it_addr = pdb->it->second->addresses.begin(); pdb->it->second->it_addr != pdb->it->second->addresses.end(); pdb->it->second->it_addr++)
//		{
//			//sqlite3 *db;
//			//*err_msg = 0;
//			//stmt = NULL;
//
//			//char sql[3000];
//			//memset(sql, 0, sizeof(char) * 3000);
//			//open DB-Server File
//			//rc = sqlite3_open("test.db", &db);
//
//			//error check
//			//if (rc != SQLITE_OK)
//			//{
//			//	fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//			//	sqlite3_close(db);
//			//}
//
//
//			//query write
//			strcat_s(sql, "CREATE TABLE IF NOT EXISTS Address");
//			strcat_s(sql, pdb->it->second->it_addr->second->getStringType().c_str());
//			strcat_s(sql, "(PersId  INTEGER REFERENCES Person(ID),Stadt TEXT,Strasse TEXT,Haus_Nr TEXT,PLZ TEXT); ");
//			strcat_s(sql, "INSERT INTO Address");
//			strcat_s(sql, pdb->it->second->it_addr->second->getStringType().c_str());
//			strcat_s(sql, "(PersId,Stadt,Strasse,Haus_Nr,PLZ) VALUES(");
//			//PersId
//			strcat_s(sql, PersId);
//			strcat_s(sql, ",'");
//			//Stadt
//			strcat_s(sql, pdb->it->second->it_addr->second->getStadt().c_str());
//			strcat_s(sql, "','");
//			//Strasse
//			strcat_s(sql, pdb->it->second->it_addr->second->getStrasse().c_str());
//			strcat_s(sql, "','");
//			//Haus_Nr
//			strcat_s(sql, pdb->it->second->it_addr->second->getHnr().c_str());
//			strcat_s(sql, "','");
//			//PLZ
//			strcat_s(sql, pdb->it->second->it_addr->second->getPlz().c_str());
//			strcat_s(sql, "');");
//
//			//char[] sql initialize.
//			//if (rc != SQLITE_OK)
//			//{
//			//	fprintf(stderr, "SQL error: %s\n", err_msg);
//			//
//			//	sqlite3_free(err_msg);
//			//	sqlite3_close(db);
//			//
//			//}
//			//sqlite3_close(db);
//		}
//	*/
//	}//for_it
//	
//	char* sqlite_getPersId_from_rowid(int _last_rowId)
//	{
//		
//
//		char _PersId[10];
//		memset(_PersId, 0, sizeof(char) * 10);
//		//int iPersId;
//		//char *
//		err_msg = 0;
//		rc = sqlite3_open("test.db", &db);//open argument test.db, return=>&db is pointing test db
//		stmt = NULL;//stmt obj
//
//		int st = sqlite3_step(stmt);
//
//		if (rc != SQLITE_OK)
//		{
//			fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//			sqlite3_close(db);
//		
//			return 0;
//		}
//
//		char sql[3000];
//		memset(sql, 0, sizeof(char) * 3000);//initializing
//		strcpy_s(sql, "select id from Person where rowid = ");
//		strcat_s(sql, to_string(_last_rowId).c_str());
//		strcat_s(sql, ";");
//		
//		//?
//		puts(sql);
//
//		if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
//		{
//			//how many scrape? -> cols
//			int cols = sqlite3_column_count(stmt);
//
//			int result = 0;
//			while (true)
//			{
//				result = sqlite3_step(stmt);
//				if (result == SQLITE_ROW)
//				{
//					for (int col = 0; col < cols; col++)
//					{
//						//printConsole
//						//printf("%s\t", (char*)sqlite3_column_text(stmt, col));
//
//						//memset(_PersId, 0, sizeof(char) * 10);
//						//(int)sqlite3_column_int(stmt, col);
//						strcpy_s(_PersId, (char*)sqlite3_column_text(stmt, col));
//						//strcpy_s(PersId, to_string((int)sqlite3_column_int(stmt, col)).c_str());
//						
//
//						//rowid
//						/*printf("%i\t", sqlite3_last_insert_rowid(db));*/
//					}
//					return _PersId;
//					//puts("");
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//		if (rc != SQLITE_OK)
//		{
//			fprintf(stderr, "SQL error: %s\n", err_msg);
//		
//			sqlite3_free(err_msg);
//			sqlite3_close(db);
//		
//			return 0;
//		}
//
//		sqlite3_close(db);//SQLITE_OK or error
//	}
//};

//User have to input PersId one more time
//because in a DB, 2 or more person, who have same name, can be exist.
//PersId!!
class Check_the_existence_of_login_id_in_DB
{
public:
	bool execute(string _login_id);
};

class Sqlite_search_Id_from_name
{
public:

	char* execute();
};

class Sqlite_add_Addr_toPers
{
public:
	//construct
	Sqlite_add_Addr_toPers(PersonDB *_pdb);
	//String_SelectAddrType* selectType;
	PersonDB * pdb;
	map<int, Person*>::iterator  _it_pers;
	map<address::TYPE, address*>::iterator _it_addr;
	///*int whileControl = 1;*/

	void execute();
	/*}*/
};

class Search_prodName_from_ProdId
{
public:
	char* execute(int _prod_id);
};

class String_SelectAddrType
{
public:

	string execute();
};
/*bool bool_login_stmt;
string activated_login_id;
int activated_pers_id;*/

class Login_stmt
{
public:
	static bool bool_login_stmt;
	static string activated_login_id;
	static int activated_pers_id;

	//bool is_Login;
	/*void variable_initializer()
	{
		bool_login_stmt = false;
		activated_login_id = "default";
		activated_pers_id = 0;
	}*/

	bool is_Login();

		void set_login_stmt(bool b);
		void logout();
};/*
bool Login_stmt::bool_login_stmt = false;
string Login_stmt::activated_login_id = "default";
int Login_stmt::activated_pers_id = 0;*/

class Login
{
public:
	Login_stmt * login_stmt;
	Login * login;
	Check_the_existence_of_login_id_in_DB check_the_existence_of_login_id_in_DB;
	void execute();
	//input_id
	//That id is not exist.
	//input_pw
	//pw is wrong
	//in this program, only usernum is necessary for login
};

//class Sqlite_add_Addr_toPers
//{
//public:
//	//construct
//	Sqlite_add_Addr_toPers(PersonDB *_pdb)
//	{
//		pdb = _pdb;
//	}
//
//	PersonDB * pdb;
//	///*map<int, Person*>::iterator  it;*/
//	///*map<address::TYPE, address*>::iterator it_addr;*/
//	///*int whileControl = 1;*/
//
//	void execute()
//	{
//		/*while (whileControl)
//		{*/
//		//iterator it zeicht einzel Person obejekt. 
//		//und jede Person objekt hat drei Address objekt(home, work, shipping)
//		
//		//test
//		int _cinPersId=0;
//		cout << "Bitte tun PersId rein. ";
//		cin >> _cinPersId;
//		//test
//		
//		for (pdb->it = pdb->personen.begin(); pdb->it != pdb->personen.end(); pdb->it++)
//		{
//			sqlite3 *db;
//			char *err_msg = 0;
//
//			//open DB-Server File
//			int rc = sqlite3_open("test.db", &db);
//
//			//error check
//			if (rc != SQLITE_OK)
//			{
//				fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//				sqlite3_close(db);
//			}
//			
//			//char[] sql initialize.
//			char sql[3000];
//			memset(sql, 0, sizeof(char) * 3000);
//
//			for(pdb->it->second->it_addr=pdb->it->second->addresses.begin(); pdb->it->second->it_addr != pdb->it->second->addresses.end(); pdb->it->second->it_addr++)
//			{
//				//query write
//				strcat_s
//				(
//					sql,
//					"CREATE TABLE IF NOT EXISTS Address"
//				);
//				strcat_s
//				(
//					sql,
//					pdb->it->second->it_addr->second->getStringType().c_str()
//				);
//				strcat_s
//				(
//					sql,
//					"("
//					"PersId  INTEGER REFERENCES Person(ID),"
//					/*
//					"AddrId  INTEGER PRIMARY KEY AUTOINCREMENT"
//					"NOT NULL UNIQUE,"
//					*/
//					"Stadt   TEXT,"
//					"Strasse TEXT,"
//					"Haus_Nr TEXT,"
//					"PLZ     TEXT"
//					"); "
//				);
//				strcat_s
//				(
//					sql, 
//					"INSERT INTO Address"
//				);
//				strcat_s
//				(
//					sql,
//					pdb->it->second->it_addr->second->getStringType().c_str()
//				);
//				strcat_s
//				(
//					sql,
//					"("
//					"PersId,"
//					/*AddrId*/
//					"Stadt,Strasse,Haus_Nr,PLZ"
//					")"
//					"VALUES"
//					"("
//				);
//				//PersId
//				strcat_s
//				(
//					sql,
//					to_string(_cinPersId).c_str()
//				);
//				//AddressTYPE(AddrId) : AUTO_INCREMENT -> NULL schreiben als Value
//				strcat_s
//				(
//					sql,
//					",'"
//					/*",?,'"*/
//				);
//				//Stadt
//				strcat_s
//				(
//					sql,
//					pdb->it->second->it_addr->second->getStadt().c_str()
//				);
//				strcat_s
//				(
//					sql,
//					"','"
//				);
//				//Strasse
//				strcat_s
//				(
//					sql,
//					pdb->it->second->it_addr->second->getStrasse().c_str()
//				);
//				strcat_s
//				(
//					sql,
//					"','"
//				);
//				//Haus_Nr
//				strcat_s
//				(
//					sql,
//					pdb->it->second->it_addr->second->getHnr().c_str()
//				);
//				strcat_s
//				(
//					sql,
//					"','"
//				);
//				//PLZ
//				strcat_s
//				(
//					sql,
//					pdb->it->second->it_addr->second->getPlz().c_str()
//				);
//				strcat_s
//				(
//					sql,
//					"');"
//				);
//			}//for it_addr
//			
//			//query execute. this function can be replaced for sqlite3_prepared,step,finalized.
//			rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
//
//			/*int __rowid = sqlite3_last_insert_rowid(db);*/
//			if (rc != SQLITE_OK)
//			{
//				fprintf(stderr, "SQL error: %s\n", err_msg);
//
//				sqlite3_free(err_msg);
//				sqlite3_close(db);
//
//			}
//			sqlite3_close(db);
//		}
//	}
//};
class Buy_Product
{
public:

	int selected_prod_id;
	string default_compare_str = "default";

	Login* login;
	Login_stmt* login_stmt;
	Search_prodName_from_ProdId * search_prodName_from_ProdId;


	void execute();
	//constructor
	//Buy_Produkt(current_Loged_in_userId, ausgewaelteProd_id)

	//while(!w_Bool_is_Loged_in)
	//if(Bool_is_Login_in)
	//true:w_Bool_is_Loged_in = 1
	//false:aufrufen Login funkution.

	//kaufen-Menge_auswahl.(int Menge, cin >>Menge) 
	//fragen: 1.kaufen 2.exit
	//case1: sql="Insert into Bestellung(pers_id, prod_id, Kaufen Time, Menge) Values(current_Loged_in_userId, ausgewaelteProd_id, datetime.now)"
};

class see_Produkt_detail
{
public:



	char* execute();
	//input product_id 
	//select prod_id,prod_name,prod_gewicht,Groesse... from produkt where v_prod_id = input_Nr. 
	//show all detail of selected Product.
	//Fragen) was moechten sie tun?
	//1.kaufen 2.tun diese Produkt rein Einkaufswagen 3.search with other keyword. 
	//case1 : ruft funktion 'Buy_Product' auf .
	//case2 : ruft funktion 'put_shoppingKart'
	//case3 : ruft funktion 'product_search'
};

class search_produkt_with_keyword
{
public:
	char* execute();
};

class Sqlite_purchase_prod_process
{
public:
	see_Produkt_detail * see_prod_detail;
	search_produkt_with_keyword * search_prod_with_keyword;
	Buy_Product * buy_prod;

	char* execute();
};

class Put_shoppingKart
{
	//constructor
	//Put_shoppingKart(current_Loged_in_userId, ausgewaelteProd_id)

	//while(Bool_is_Loged_in)
	//if(Bool_is_Login)
	//true:kaufen-Menge_auswahl.
	//false:aufrufen Login funkution.
	//fuegt produkt_info hinzu 'person.shopping_cart.(prod_id, prod_name..)'
	//i think the prod_id can be changed someday if so many seller upload new product. 
	//for that reason, program should specify the produkt.
	//end
};

#endif