#pragma once
#include "Common.h"
#include "PersonDB.h"
#include "Person.h"
#include "Funktionen.h"
#include <vector>


//PersonDB is a receiver. in command pattern perspective


//interface command
class Cmd
{
public:
	virtual void execute()=0;
};

//concrete command
class defaultCmd : public Cmd
{
private :
	PersonDB * pdb;
public :
	defaultCmd(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
	
	void execute() override
	{
		cout << "No Command set up." << endl;
	}
};

//class registerNewPersonCmd : public Cmd
//{
//private:
//	PersonDB * pdb;
//public:
//	registerNewPersonCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		return pdb->registerNewPerson();
//	}
//};
class _registerNewPersonCmd : public Cmd
{
private:
	PersonDB * pdb;
	RegisterNewPerson * c_regi;
public:
	_registerNewPersonCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_regi = new RegisterNewPerson(pdb);
		c_regi->execute();
	}
};

//class deletePersonCmd : public Cmd
//{
//private :
//	PersonDB * pdb;
//public :
//	deletePersonCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		return pdb->deletePerson();
//	}
//};
class _deletePersonCmd : public Cmd
{
private:
	PersonDB * pdb;
	DeletePerson * c_dele;
public:
	_deletePersonCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_dele = new DeletePerson(pdb);
		c_dele->execute();
	}
};

//class searchInfoCmd : public Cmd
//{
//private:
//	PersonDB * pdb;
//public:
//	searchInfoCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		return pdb->searchInfo();
//	}
//};
class _searchInfoCmd : public Cmd
{
private:
	SearchInfo * c_sear;
	PersonDB * pdb;
public:
	_searchInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_sear = new SearchInfo(pdb);
		c_sear->execute();
	}
};

//class viewAllInfoCmd : public Cmd
//{
//private:
//	PersonDB * pdb;
//public:
//	viewAllInfoCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		return pdb->viewAllInfo();
//	}
//};
class _viewAllInfoCmd : public Cmd
{
private:
	ViewAllInfo * c_view;
	PersonDB * pdb;
public:
	_viewAllInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_view = new ViewAllInfo(pdb);
		c_view->execute();
	}
};

//class changeInfoCmd : public Cmd
//{
//private:
//	PersonDB * pdb;
//public:
//	changeInfoCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//	void execute() override
//	{
//		return pdb->changeInfo();
//	}
//};
class _changeInfoCmd : public Cmd
{
private:
	ChangeInfo * c_chan;
	PersonDB * pdb;
public:
	_changeInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_chan = new ChangeInfo(pdb);
		c_chan->execute();
	}
};

//class importCSVFileCmd : public Cmd
//{
//private:
//	PersonDB * pdb;
//public:
//	importCSVFileCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		return pdb->importCSVFile();
//	}
//};
class _importCSVFileCmd : public Cmd
{
private:
	ImportCSVFile * c_imCSV;
	PersonDB * pdb;
public:
	_importCSVFileCmd(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_imCSV = new ImportCSVFile(pdb);
		c_imCSV->execute();
	}
};

//class importTXTFileCmd : public Cmd
//{
//private:
//	PersonDB * pdb;
//public:
//	importTXTFileCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		return pdb->importTXTFile();
//	}
//};
class _importTXTFileCmd : public Cmd
{
private:
	ImportTXTFile * c_imTXT;
	PersonDB * pdb;
public:
	_importTXTFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_imTXT = new ImportTXTFile(pdb);
		c_imTXT->execute();
	}
};

//class exportCSVFileCmd : public Cmd
//{
//private:
//	PersonDB * pdb;
//public:
//	exportCSVFileCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		return pdb->exportCSVFile();
//	}
//};
class _exportCSVFileCmd : public Cmd
{
private:
	ExportCSVFile * c_exCSV;
	PersonDB * pdb;
public:
	_exportCSVFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_exCSV = new ExportCSVFile(pdb);
		c_exCSV->execute();
	}
};

//class exportTXTFileCmd : public Cmd
//{
//private:
//	PersonDB * pdb;
//public:
//	exportTXTFileCmd(PersonDB *_pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		return pdb->exportTXTFile();
//	}
//};
class _exportTXTFileCmd : public Cmd
{
private:
	ExportTXTFile * c_exTXT;
	PersonDB * pdb;
public:
	_exportTXTFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_exTXT = new ExportTXTFile(pdb);
		c_exTXT->execute();
	}
};

//class _SQLite_insertCmd : public Cmd
//{
//private:
//	Sqlite_insert_pers * c_sqlite3Ins;
//	PersonDB * pdb;
//public :
//	_SQLite_insertCmd(PersonDB* _pdb)
//	{
//		this->pdb = _pdb;
//	}
//
//	void execute() override
//	{
//		c_sqlite3Ins = new Sqlite_insert_pers(pdb);
//		c_sqlite3Ins->execute();
//	}
//};

class _SQLite_search_Id_from_nameCmd : public Cmd
{
private :
	Sqlite_search_Id_from_name * c_sqlite3Sea;
	//PersonDB * pdb;
public:
	void execute() override
	{
		c_sqlite3Sea = new Sqlite_search_Id_from_name();
		c_sqlite3Sea->execute();
	}
};

class _saveNewAddressCmd : public Cmd
{
private :
	SaveNewAddress * c_SaveNewAddr;
	PersonDB * pdb;
public:
	_saveNewAddressCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_SaveNewAddr = new SaveNewAddress(pdb);
		c_SaveNewAddr->execute();
	}
};

class _SQLite_add_AddrCmd : public Cmd
{
private:
	Sqlite_add_Addr_toPers * c_sqlite3addAddrtoPers;
	PersonDB * pdb;
public:
	_SQLite_add_AddrCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	void execute() override
	{
		c_sqlite3addAddrtoPers = new Sqlite_add_Addr_toPers(pdb);
		c_sqlite3addAddrtoPers->execute();
	}
};

class _SQLite_insert_PersAddrCmd : public Cmd
{
private:
	Sqlite_insert_PersAddr * c_sqlite3insPersAddr;
	PersonDB * pdb;
public:
	_SQLite_insert_PersAddrCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	void execute() override
	{
		c_sqlite3insPersAddr = new Sqlite_insert_PersAddr(pdb);
		c_sqlite3insPersAddr->execute();
		//c_sqlite3insPersAddr->execute2();
		//c_sqlite3insPersAddr->test();
	}
};

class _SQLite_purchase_prod_processCmd : public Cmd
{
private:
	Sqlite_purchase_prod_process * sqlite_purchase_prod;
	//PersonDB * pdb;
public:
	void execute() override
	{
		sqlite_purchase_prod = new Sqlite_purchase_prod_process();
		sqlite_purchase_prod->execute();
	}
};

class _LoginCmd : public Cmd
{
private:
	Login * login;
public:
	void execute() override
	{
		login = new Login();
		login->execute();
	}
};

class _LogoutCmd : public Cmd
{
private:
	Login_stmt * login_stmt;
public:
	_LogoutCmd(Login_stmt *_login_stmt)
	{
		this->login_stmt = _login_stmt;
	}

	void execute() override
	{
		login_stmt->logout();
	}
};

//invoker
class RemoteController
{
private:
	Cmd* cmd;

public :
	RemoteController(Cmd* _cmd)
	{
		cmd = _cmd;
	}
	
	//change the command
	void setCmd(Cmd * _cmd)
	{
		this->cmd = _cmd;
	}

	void pressButton()
	{
		cmd->execute();
	}
};

//client
class RemoteControllerTest
{
private : 
	
	//receiver objekt,
	PersonDB *pdb = new PersonDB();
	Login_stmt* _login_stmt = new Login_stmt();


	defaultCmd*				defa = new defaultCmd(pdb);
	//registerNewPersonCmd*	regi = new registerNewPersonCmd(pdb);
	_registerNewPersonCmd*	cmd_regi = new _registerNewPersonCmd(pdb);
	
	//deletePersonCmd*		dele = new deletePersonCmd(pdb);
	_deletePersonCmd*		cmd_dele = new _deletePersonCmd(pdb);

	//searchInfoCmd*			sear = new searchInfoCmd(pdb);
	_searchInfoCmd*			cmd_sear = new _searchInfoCmd(pdb);

	//viewAllInfoCmd*			view = new viewAllInfoCmd(pdb);
	_viewAllInfoCmd*		cmd_view = new _viewAllInfoCmd(pdb);

	//changeInfoCmd*			chan = new changeInfoCmd(pdb);
	_changeInfoCmd*			cmd_chan = new _changeInfoCmd(pdb);

	//importCSVFileCmd*		imCSV = new importCSVFileCmd(pdb);
	_importCSVFileCmd*		cmd_imCSV = new _importCSVFileCmd(pdb);

	//importTXTFileCmd*		imTXT = new importTXTFileCmd(pdb);
	_importTXTFileCmd*		cmd_imTXT = new _importTXTFileCmd(pdb);
	
	//exportCSVFileCmd*		exCSV = new exportCSVFileCmd(pdb);
	_exportCSVFileCmd*		cmd_exCSV = new _exportCSVFileCmd(pdb);

	//exportTXTFileCmd*		exTXT = new exportTXTFileCmd(pdb);
	_exportTXTFileCmd*		cmd_exTXT = new _exportTXTFileCmd(pdb);

	//_SQLite_insertCmd*		c_sqliteIns = new _SQLite_insertCmd(pdb);
	
	//this function doesn't need pdb Object. 
	_SQLite_search_Id_from_nameCmd* cmd_sqliteSea = new _SQLite_search_Id_from_nameCmd();
	
	_saveNewAddressCmd*		cmd_SaveNewAddr = new _saveNewAddressCmd(pdb);
	
	_SQLite_add_AddrCmd* cmd_sqliteaddAddr = new _SQLite_add_AddrCmd(pdb);
	
	_SQLite_insert_PersAddrCmd *cmd_sqliteInsPersAddr = new _SQLite_insert_PersAddrCmd(pdb);

	//this function doesn't need pdb Object. 
	_SQLite_purchase_prod_processCmd *cmd_sqlite_purchase_prod = new _SQLite_purchase_prod_processCmd();

	_LoginCmd *cmd_login = new _LoginCmd();

	_LogoutCmd *cmd_logout = new _LogoutCmd(_login_stmt);
	
	
	

	/*
	RemoteController * controller1 = new RemoteController(regi);
	RemoteController * controller2 = new RemoteController(dele);
	RemoteController * controller3 = new RemoteController(view);
	RemoteController * controller4 = new RemoteController(sear);
	RemoteController * controller5 = new RemoteController(chan);
	RemoteController * controller6 = new RemoteController(expo);
	RemoteController * controller7 = new RemoteController(impo);
	*/

	//when we have lots of controll pannels, of course we can map every function,
	//before we use them without mapping. but if we use only one pannel,
	//we have to mapping each of the execution of the function.

	RemoteController controller = RemoteController(defa);


public :
	void execute()
	{
		//Eines "Integer" dafuer, die While loop kontrollieren.
		int while_i = 1;
		int ss = 0;
		int sss = 0;

		while (while_i)
		{
			int j;
			//21.DB_insert_persInfo 
			
			if(_login_stmt->bool_login_stmt==true)
			{
				cout << "\n\nID derzeit eingeloggt : "+ _login_stmt->activated_login_id;
			}if (_login_stmt->bool_login_stmt == false)
			{
				cout << "\n\nnicht eingeloggt";
			}
			cout <<
				"\n==============================================================================="
				"\n0.Program Ausschalten   1.Einloggen   2.Ausloggen"
				"\n10.Neue Kunde   11.Add_Address   12.Data_aendern   13.Abmelden"
				"\n20.AnzeigenAllenInfo   21.Nachschlagen   22.Exportieren   23.Importieren"
				"\n30.DB_insert_pers+addr  31.DB_search_persID  32.DB_add_Address"
				"\n40.DB_search_product "
				"\n==============================================================================="
				"\nWelche Funtion moechten Sie benutzen?";
			cin >> j;
			switch (j)
			{
			case 0: 
				while_i = 0;
				break;
			case 1: 
				controller.setCmd(cmd_login);
				controller.pressButton();
				break;
			case 2:
				controller.setCmd(cmd_logout);
				controller.pressButton();
				break;
			case 10:
				//controller.setCmd(regi);
				controller.setCmd(cmd_regi);
				controller.pressButton();
				break;
			case 11:
				controller.setCmd(cmd_SaveNewAddr);
				controller.pressButton();
				break;
			case 12:
				//controller.setCmd(chan);
				controller.setCmd(cmd_chan);
				controller.pressButton();
				break;
			case 13:
				//controller.setCmd(dele);
				controller.setCmd(cmd_dele);
				controller.pressButton();
				break;
			case 20:
				//controller.setCmd(view);
				controller.setCmd(cmd_view);
				controller.pressButton();
				break;
			case 21:
				//controller.setCmd(sear);
				controller.setCmd(cmd_sear);
				controller.pressButton();
				break;
			case 22:
				cout << "1.Text file  2.CSV file \nWhich File Type :";
				cin >> ss;
				switch (ss)
				{
				case 1:
					//controller.setCmd(exTXT);
					controller.setCmd(cmd_exTXT);
					controller.pressButton();
					break;
				case 2:
					//controller.setCmd(exCSV);
					controller.setCmd(cmd_exCSV);
					controller.pressButton();
					break;
				}
				break;
			case 23:
				cout << "1.Text file  2.CSV file \nWhich File Type :";
				cin >> sss;
				switch (sss)
				{
				case 1:
					//controller.setCmd(imTXT);
					controller.setCmd(cmd_imTXT);
					controller.pressButton();
					break;
				case 2:
					//controller.setCmd(imCSV);
					controller.setCmd(cmd_imCSV);
					controller.pressButton();
					break;
				}
				break;
			/*case 21:
				controller.setCmd(c_sqliteIns);
				controller.pressButton();*/
				break;
			case 30:
				controller.setCmd(cmd_sqliteInsPersAddr);
				controller.pressButton();
				break;
			case 31:
				controller.setCmd(cmd_sqliteSea);
				controller.pressButton();
				break;
			case 32:
				controller.setCmd(cmd_sqliteaddAddr);
				controller.pressButton();
				break;
			case 40:
				controller.setCmd(cmd_sqlite_purchase_prod);
				controller.pressButton();
				break;
			default:
				break;
			}
		}
	}
};

//<sqlite3_frame>
//sqlite3 *db;
//char *err_msg = 0;
//
////open DB-Server File
//int rc = sqlite3_open("test.db", &db);
//
////error check
//if (rc != SQLITE_OK)
//{
//	fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//	sqlite3_close(db);
//}
//
////char[] sql initialize.
//char sql[300];
//memset(sql, 0, sizeof(char) * 300);
//
////query write
//strcpy_s(
//	sql,
//	//"CREATE TABLE IF NOT EXISTS Person(ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE, nachname text, vorname text, geburtsdatum text, stadt text, sex text);"
//	"INSERT INTO Person(id,nachname,vorname,geburtsdatum,stadt,sex) VALUES(?,'"
//);
//strcat_s(
//	sql,
//	pdb->it->second->getNachname().c_str()
//);
//
////query execute. this function can be replaced for sqlite3_prepared,step,finalized.
//rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
//
//if (rc != SQLITE_OK)
//{
//	fprintf(stderr, "SQL error: %s\n", err_msg);
//
//	sqlite3_free(err_msg);
//	sqlite3_close(db);
//}
//sqlite3_close(db);

//char* execute()
//{
//	sqlite3 *db;
//
//	char *err_msg = 0;
//open argument test.db, return=>&db is pointing test db
//	int rc = sqlite3_open("test.db", &db);
//stmt obj
//	sqlite3_stmt* stmt = NULL;
//
//							  //int st = sqlite3_step(stmt);
//
//	if (rc != SQLITE_OK)
//	{
//		fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//		sqlite3_close(db);
//
//		return 0;
//	}
//
//	cout << "Bitte schreiben Nachname um person ID zu suchen.";
//	string dummyName = "";
//	cin >> dummyName;
//
//	char sql[300];
//	memset(sql, 0, sizeof(char) * 300);//initializing
//	strcpy_s(sql, "select id,nachname,vorname,geburtsdatum from Person where nachname = '");
//	strcat_s(sql, dummyName.c_str());
//	strcat_s(sql, "';");
//
//	puts(sql);
//
//	if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK)
//	{
//		//how many scrape? -> cols
//		int cols = sqlite3_column_count(stmt);
//
//		int result = 0;
//		while (true)
//		{
//			result = sqlite3_step(stmt);
//			if (result == SQLITE_ROW)
//			{
//				for (int col = 0; col < cols; col++)
//				{
//					//printConsole
//					//printf("%s\t", (char*)sqlite3_column_text(stmt, col));
//
//					char PersId[100];
//					memset(PersId, 0, sizeof(char) * 100);
//					strcpy_s(PersId, (char*)sqlite3_column_text(stmt, col));
//					printf("%s\t", PersId);
//				}
//				puts("");
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	if (rc != SQLITE_OK)
//	{
//		fprintf(stderr, "SQL error: %s\n", err_msg);
//
//		sqlite3_free(err_msg);
//		sqlite3_close(db);
//
//		return 0;
//	}
//
//	sqlite3_close(db);//SQLITE_OK or error
//}