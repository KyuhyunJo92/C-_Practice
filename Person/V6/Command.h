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

class _SQLite_insertCmd : public Cmd
{
private:
	Sqlite_insert_pers * c_sqlite3Ins;
	PersonDB * pdb;
public :
	_SQLite_insertCmd(PersonDB* _pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_sqlite3Ins = new Sqlite_insert_pers(pdb);
		c_sqlite3Ins->execute();
	}
};

class _SQLite_search_Id_from_nameCmd : public Cmd
{
private :
	Sqlite_search_Id_from_name * c_sqlite3Sea;
	PersonDB * pdb;
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

class _SQLite_insert_AddrCmd : public Cmd
{
private:
	Sqlite_insert_Addr * c_sqlite3insAddr;
	PersonDB * pdb;
public:
	_SQLite_insert_AddrCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	void execute() override
	{
		c_sqlite3insAddr = new Sqlite_insert_Addr(pdb);
		c_sqlite3insAddr->execute();
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

	defaultCmd*				defa = new defaultCmd(pdb);
	//registerNewPersonCmd*	regi = new registerNewPersonCmd(pdb);
	_registerNewPersonCmd*	c_regi = new _registerNewPersonCmd(pdb);
	
	//deletePersonCmd*		dele = new deletePersonCmd(pdb);
	_deletePersonCmd*		c_dele = new _deletePersonCmd(pdb);

	//searchInfoCmd*			sear = new searchInfoCmd(pdb);
	_searchInfoCmd*			c_sear = new _searchInfoCmd(pdb);

	//viewAllInfoCmd*			view = new viewAllInfoCmd(pdb);
	_viewAllInfoCmd*		c_view = new _viewAllInfoCmd(pdb);

	//changeInfoCmd*			chan = new changeInfoCmd(pdb);
	_changeInfoCmd*			c_chan = new _changeInfoCmd(pdb);

	//importCSVFileCmd*		imCSV = new importCSVFileCmd(pdb);
	_importCSVFileCmd*		c_imCSV = new _importCSVFileCmd(pdb);

	//importTXTFileCmd*		imTXT = new importTXTFileCmd(pdb);
	_importTXTFileCmd*		c_imTXT = new _importTXTFileCmd(pdb);
	
	//exportCSVFileCmd*		exCSV = new exportCSVFileCmd(pdb);
	_exportCSVFileCmd*		c_exCSV = new _exportCSVFileCmd(pdb);

	//exportTXTFileCmd*		exTXT = new exportTXTFileCmd(pdb);
	_exportTXTFileCmd*		c_exTXT = new _exportTXTFileCmd(pdb);

	_SQLite_insertCmd*		c_sqliteIns = new _SQLite_insertCmd(pdb);
	
	_SQLite_search_Id_from_nameCmd* c_sqliteSea = new _SQLite_search_Id_from_nameCmd();
	
	_saveNewAddressCmd*		c_SaveNewAddr = new _saveNewAddressCmd(pdb);
	
	_SQLite_insert_AddrCmd* c_sqliteInsAddr = new _SQLite_insert_AddrCmd(pdb);
	
	_SQLite_insert_PersAddrCmd *c_sqliteInsPersAddr = new _SQLite_insert_PersAddrCmd(pdb);
	
	
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
			cout <<
				"\n==============================================================================="
				"\n0.EXIT  1.Regist_PersonalInfo   2.Add_Address   3.Data_aendern   4.Abmelden"
				"\n10.AnzeigenAllenInfo   11.Nachschlagen   12.exportieren   13.importieren"
				"\n21.DB_insert_persInfo 22.DB_search_persID   23.DB_regist_Address"
				"\n24.DB_insert_pers+addr"
				"\n==============================================================================="
				"\nWelche Funtion moechten Sie benutzen?";
			cin >> j;
			switch (j)
			{
			case 0: while_i = 0;
				break;
			case 1:
				//controller.setCmd(regi);
				controller.setCmd(c_regi);
				controller.pressButton();
				break;
			case 2:
				controller.setCmd(c_SaveNewAddr);
				controller.pressButton();
				break;
			case 3:
				//controller.setCmd(chan);
				controller.setCmd(c_chan);
				controller.pressButton();
				break;
			case 4:
				//controller.setCmd(dele);
				controller.setCmd(c_dele);
				controller.pressButton();
				break;
			case 10:
				//controller.setCmd(view);
				controller.setCmd(c_view);
				controller.pressButton();
				break;
			case 11:
				//controller.setCmd(sear);
				controller.setCmd(c_sear);
				controller.pressButton();
				break;
			
			case 12:
				cout << "1.Text file  2.CSV file \nWhich File Type :";
				cin >> ss;
				switch (ss)
				{
				case 1:
					//controller.setCmd(exTXT);
					controller.setCmd(c_exTXT);
					controller.pressButton();
					break;
				case 2:
					//controller.setCmd(exCSV);
					controller.setCmd(c_exCSV);
					controller.pressButton();
					break;
				}
				break;
			case 13:
				cout << "1.Text file  2.CSV file \nWhich File Type :";
				cin >> sss;
				switch (sss)
				{
				case 1:
					//controller.setCmd(imTXT);
					controller.setCmd(c_imTXT);
					controller.pressButton();
					break;
				case 2:
					//controller.setCmd(imCSV);
					controller.setCmd(c_imCSV);
					controller.pressButton();
					break;
				}
				break;
			case 21:
				controller.setCmd(c_sqliteIns);
				controller.pressButton();
				break;
			case 22:
				controller.setCmd(c_sqliteSea);
				controller.pressButton();
				break;
			case 23:
				controller.setCmd(c_sqliteInsAddr);
				controller.pressButton();
			case 24:
				controller.setCmd(c_sqliteInsPersAddr);
				controller.pressButton();
			default:
				break;
			}
		}
	}
};