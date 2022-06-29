#ifndef COMMAND_H
#define COMMAND_H

#include "Funktionen.h"



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
	defaultCmd(PersonDB * _pdb);

		void execute() override;
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
	_registerNewPersonCmd(PersonDB *_pdb);

	void execute() override;
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
	_deletePersonCmd(PersonDB *_pdb);

	void execute() override;
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
	_searchInfoCmd(PersonDB *_pdb);

	void execute() override;
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
	_viewAllInfoCmd(PersonDB *_pdb);

	void execute() override;
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
	_changeInfoCmd(PersonDB *_pdb);

	void execute() override;
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
	_importCSVFileCmd(PersonDB * _pdb);

	void execute() override;
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
	_importTXTFileCmd(PersonDB *_pdb);

	void execute() override;
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
	_exportCSVFileCmd(PersonDB *_pdb);

	void execute() override;
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
	_exportTXTFileCmd(PersonDB *_pdb);

	void execute() override;
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
	void execute() override;
};

class _saveNewAddressCmd : public Cmd
{
private :
	SaveNewAddress * c_SaveNewAddr;
	PersonDB * pdb;
public:
	_saveNewAddressCmd(PersonDB *_pdb);

	void execute() override;
};

class _SQLite_add_AddrCmd : public Cmd
{
private:
	Sqlite_add_Addr_toPers * c_sqlite3addAddrtoPers;
	PersonDB * pdb;
public:
	_SQLite_add_AddrCmd(PersonDB *_pdb);
	void execute() override;
};

class _SQLite_insert_PersAddrCmd : public Cmd
{
private:
	Sqlite_insert_PersAddr * c_sqlite3insPersAddr;
	PersonDB * pdb;
public:
	_SQLite_insert_PersAddrCmd(PersonDB *_pdb);
	void execute() override;
};

class _SQLite_purchase_prod_processCmd : public Cmd
{
private:
	Sqlite_purchase_prod_process * sqlite_purchase_prod;
	//PersonDB * pdb;
public:
	void execute() override;
};

class _LoginCmd : public Cmd
{
private:
	Login * login;
public:
	void execute() override;
};

class _LogoutCmd : public Cmd
{
private:
	Login_stmt * login_stmt;
public:
	_LogoutCmd(Login_stmt *_login_stmt);

	void execute() override;
};

class _charge_Konto_BargeldCmd : public Cmd
{
private:
	Login_stmt * login_stmt;
public:
	charge_Konto_Bargeld * _charge_Konto_Bargeld;
	void execute() override;
};

class _Nachschlage_KontostandCmd : public Cmd
{
private:
	Login_stmt * login_stmt;
public:
	Nachschlage_Kontostand * _Nachschlage_Kontostand;
	void execute() override;
};

//invoker
class RemoteController
{
private:
	Cmd* cmd;

public :
	RemoteController(Cmd* _cmd);
	
	//change the command
	void setCmd(Cmd * _cmd);

	void pressButton();
};

//client
class RemoteControllerTest
{
private : 
	
	//receiver objekt,
	PersonDB *pdb = new PersonDB();
	Login_stmt* _login_stmt = new Login_stmt();
	bring_Kontostand obj_bring_Kontostand = bring_Kontostand();


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
	
	_charge_Konto_BargeldCmd *cmd_Charge_Konto_Bargeld = new _charge_Konto_BargeldCmd();
	
	_Nachschlage_KontostandCmd *cmd_Nachschlage_Kontostand = new _Nachschlage_KontostandCmd();
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
	void execute();
};
#endif