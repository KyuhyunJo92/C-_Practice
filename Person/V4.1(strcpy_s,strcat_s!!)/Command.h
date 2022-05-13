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
	Sqlite3_insert * c_sqlite3Ins;
	PersonDB * pdb;
public :
	_SQLite_insertCmd(PersonDB* _pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		c_sqlite3Ins = new Sqlite3_insert(pdb);
		c_sqlite3Ins->execute();
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

	_SQLite_insertCmd*		c_sqlite3Ins = new _SQLite_insertCmd(pdb);
	//controller 7, enough controller
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
			cout << "\n0.EXIT 1.Anmelden  2.Abmelden  3.AnzeigenAllenInfo  4.Nachschlagen  5.Data aendern  6.exportieren  7.importieren 8.sqlite3 test\n";
			cout << "Welche Funtion moechten Sie benutzen?";
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
				//controller.setCmd(dele);
				controller.setCmd(c_dele);
				controller.pressButton();
				break;
			case 3:
				//controller.setCmd(view);
				controller.setCmd(c_view);
				controller.pressButton();
				break;
			case 4:
				//controller.setCmd(sear);
				controller.setCmd(c_sear);
				controller.pressButton();
				break;
			case 5:
				//controller.setCmd(chan);
				controller.setCmd(c_chan);
				controller.pressButton();
				break;
			case 6:
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
			case 7:
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
			case 8:
				controller.setCmd(c_sqlite3Ins);
				controller.pressButton();
				break;

			default:
				break;
			}
		}
	}
};

//class ConnectSQLite3
//{
//	sqlite3 *db;
//
//
//
//};

