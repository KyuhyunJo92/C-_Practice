#pragma once
#pragma once
#include "Common.h"
#include "PersonDB.h"
#include "Person.h"
#include "Functionen.h"
#include <vector>


//PersonDB is a receiver. in command pattern perspective


//abstract class Cmd
//interface command
class Cmd
{
public:
	PersonDB * pdb;
	virtual void execute() = 0;
};

//concrete command
class defaultCmd : public Cmd
{
private:
public:
	defaultCmd(PersonDB * _pdb)
	{
		pdb = _pdb;
	}

	void execute() override
	{
		cout << "No Command set up." << endl;
	}
};
class registerNewPersonCmd : public Cmd
{
private:
public:
	registerNewPersonCmd(PersonDB *_pdb)
	{
		pdb = _pdb;
	}
	RegisterNewPerson * regi = new RegisterNewPerson(pdb);

	void execute() override
	{
		regi->execute();
	}
};
class deletePersonCmd : public Cmd
{
public:
	deletePersonCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	DeletePerson * dele = new DeletePerson(pdb);

	void execute() override
	{
		dele->execute();
	}
};
class searchInfoCmd : public Cmd
{
public:
	searchInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	SearchInfo * sear = new SearchInfo(pdb);

	void execute() override
	{
		sear->execute();
	}
};
class changeInfoCmd : public Cmd
{
public:
	changeInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	ChangeInfo * chan = new ChangeInfo(pdb);
	void execute() override
	{
		chan->execute();
	}
};
class viewAllInfoCmd : public Cmd
{
public:
	viewAllInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	ViewAllInfo * view = new ViewAllInfo(pdb);

	void execute() override
	{
		view->execute();
	}
};

class importCSVFileCmd : public Cmd
{
public:
	importCSVFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	ImportCSVFile * icsv = new ImportCSVFile(pdb);
	void execute() override
	{
		icsv->execute();
	}
};
class importTXTFileCmd : public Cmd
{
public:
	importTXTFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	ImportTXTFile * itxt = new ImportTXTFile(pdb);
	void execute() override
	{
		itxt->execute();
	}
};

class exportCSVFileCmd : public Cmd
{
public:
	exportCSVFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	ExportCSVFile * ocsv = new ExportCSVFile(pdb);
	void execute() override
	{
		ocsv->execute();
	}
};
class exportTXTFileCmd : public Cmd
{
public:
	exportTXTFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	ExportTXTFile * otxt = new ExportTXTFile(pdb);
	void execute() override
	{
		otxt->execute();
	}
};
//invoker
class RemoteController
{
private:
	Cmd* cmd;
public:
	RemoteController(Cmd* _cmd)
	{
		cmd = _cmd;
	}
	//change the command
	void setCmd(Cmd * _cmd)
	{
		cmd = _cmd;
	}
	void pressButton()
	{
		cmd->execute();
	}
};
//client
class RemoteControllerTest
{
private:
	//receiver objekt,
	PersonDB *pdb = new PersonDB();

	defaultCmd*				defa = new defaultCmd(pdb);
	registerNewPersonCmd*	regi = new registerNewPersonCmd(pdb);
	deletePersonCmd*		dele = new deletePersonCmd(pdb);
	viewAllInfoCmd*			view = new viewAllInfoCmd(pdb);
	searchInfoCmd*			sear = new searchInfoCmd(pdb);
	changeInfoCmd*			chan = new changeInfoCmd(pdb);
	importCSVFileCmd*		icsv = new importCSVFileCmd(pdb);
	importTXTFileCmd*		itxt = new importTXTFileCmd(pdb);
	exportCSVFileCmd*		ocsv = new exportCSVFileCmd(pdb);
	exportTXTFileCmd*		otxt = new exportTXTFileCmd(pdb);

	RemoteController controller = RemoteController(defa);

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
public:

	void start()
	{
		//Eines "Integer" dafuer, die While loop kontrollieren.
		int while_i = 1;
		int ss = 0;
		int sss = 0;

		while (while_i)
		{
			int j;
			cout << "\n0.EXIT 1.Anmelden  2.Abmelden  3.AnzeigenAllenInfo  4.Nachschlagen  5.Data aendern  6.exportieren  7.importieren \n";
			cout << "Welche Funtion moechten Sie benutzen?";
			cin >> j;
			switch (j)
			{
			case 0: while_i = 0;
				break;
			case 1:
				controller.setCmd(regi);
				controller.pressButton();
				break;

			case 2:
				controller.setCmd(dele);
				controller.pressButton();
				break;
			case 3:
				controller.setCmd(view);
				controller.pressButton();
				break;
			case 4:
				controller.setCmd(sear);
				controller.pressButton();
				break;
			case 5:
				controller.setCmd(chan);
				controller.pressButton();
				break;
			case 6:
				cout << "1.Text file  2.CSV file \nWhich File Type :";
				cin >> ss;
				switch (ss)
				{
				case 1:
					controller.setCmd(otxt);
					controller.pressButton();
					break;
				case 2:
					controller.setCmd(ocsv);
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
					controller.setCmd(itxt);
					controller.pressButton();
					break;
				case 2:
					controller.setCmd(icsv);
					controller.pressButton();
					break;
				}
				break;

			default:
				break;
			}
		}
	}
};