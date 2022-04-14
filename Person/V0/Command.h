#pragma once
#include "Common.h"
#include "PersonDB.h"
#include "Person.h"
#include <vector>


//PersonDB is a receiver. in command pattern perspective


//abstract class Cmd
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
class registerNewPersonCmd : public Cmd
{
private:
	PersonDB * pdb;
public:
	registerNewPersonCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		return pdb->registerNewPerson();
	}
};
class deletePersonCmd : public Cmd
{
private :
	PersonDB * pdb;
public :
	deletePersonCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		return pdb->deletePerson();
	}
};
class searchInfoCmd : public Cmd
{
private:
	PersonDB * pdb;
public:
	searchInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		return pdb->searchInfo();
	}
};
class changeInfoCmd : public Cmd
{
private:
	PersonDB * pdb;
public:
	changeInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
	void execute() override
	{
		return pdb->changeInfo();
	}
};
class viewAllInfoCmd : public Cmd
{
private:
	PersonDB * pdb;
public:
	viewAllInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		return pdb->viewAllInfo();
	}
};
class importCSVFileCmd : public Cmd
{
private:
	PersonDB * pdb;
public:
	importCSVFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		return pdb->importCSVFile();
	}
};

class importTXTFileCmd : public Cmd
{
private:
	PersonDB * pdb;
public:
	importTXTFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		return pdb->importTXTFile();
	}
};

class exportCSVFileCmd : public Cmd
{
private:
	PersonDB * pdb;
public:
	exportCSVFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		return pdb->exportCSVFile();
	}
};

class exportTXTFileCmd : public Cmd
{
private:
	PersonDB * pdb;
public:
	exportTXTFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

	void execute() override
	{
		return pdb->exportTXTFile();
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
	registerNewPersonCmd*	regi = new registerNewPersonCmd(pdb);
	deletePersonCmd*		dele = new deletePersonCmd(pdb);
	viewAllInfoCmd*			view = new viewAllInfoCmd(pdb);
	searchInfoCmd*			sear = new searchInfoCmd(pdb);
	changeInfoCmd*			chan = new changeInfoCmd(pdb);
	importCSVFileCmd*		imCSV = new importCSVFileCmd(pdb);
	importTXTFileCmd*		imTXT = new importTXTFileCmd(pdb);
	exportCSVFileCmd*		exCSV = new exportCSVFileCmd(pdb);
	exportTXTFileCmd*		exTXT = new exportTXTFileCmd(pdb);


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
					controller.setCmd(exTXT);
					controller.pressButton();
					break;
				case 2 : 
					controller.setCmd(exCSV);
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
					controller.setCmd(imTXT);
					controller.pressButton();
					break;
				case 2:
					controller.setCmd(imCSV);
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
