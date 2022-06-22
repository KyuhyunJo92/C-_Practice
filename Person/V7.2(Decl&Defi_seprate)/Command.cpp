#include "Command.h"

//concrete command
defaultCmd::defaultCmd(PersonDB * _pdb)
	{
		pdb = _pdb;
	}
void defaultCmd::execute()
	{
		cout << "No Command set up." << endl;
	}

_registerNewPersonCmd::_registerNewPersonCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
void _registerNewPersonCmd::execute()
	{
		c_regi = new RegisterNewPerson(pdb);
		c_regi->execute();
	}

_deletePersonCmd::_deletePersonCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
void _deletePersonCmd::execute()
	{
		c_dele = new DeletePerson(pdb);
		c_dele->execute();
	}


_searchInfoCmd ::_searchInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

void _searchInfoCmd::execute()
	{
		c_sear = new SearchInfo(pdb);
		c_sear->execute();
	}

_viewAllInfoCmd::_viewAllInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
void _viewAllInfoCmd::execute()
	{
		c_view = new ViewAllInfo(pdb);
		c_view->execute();
	}


_changeInfoCmd::_changeInfoCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

void _changeInfoCmd::execute()
	{
		c_chan = new ChangeInfo(pdb);
		c_chan->execute();
	}


_importCSVFileCmd::_importCSVFileCmd(PersonDB * _pdb)
	{
		this->pdb = _pdb;
	}

void _importCSVFileCmd::execute()
	{
		c_imCSV = new ImportCSVFile(pdb);
		c_imCSV->execute();
	}


_importTXTFileCmd::_importTXTFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

void _importTXTFileCmd::execute()
	{
		c_imTXT = new ImportTXTFile(pdb);
		c_imTXT->execute();
	}


_exportCSVFileCmd::_exportCSVFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

void _exportCSVFileCmd::execute()
	{
		c_exCSV = new ExportCSVFile(pdb);
		c_exCSV->execute();
	}


_exportTXTFileCmd::_exportTXTFileCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

void _exportTXTFileCmd::execute()
	{
		c_exTXT = new ExportTXTFile(pdb);
		c_exTXT->execute();
	}


void _SQLite_search_Id_from_nameCmd::execute() 
	{
		c_sqlite3Sea = new Sqlite_search_Id_from_name();
		c_sqlite3Sea->execute();
	}


_saveNewAddressCmd::_saveNewAddressCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}

void  _saveNewAddressCmd::execute()
	{
		c_SaveNewAddr = new SaveNewAddress(pdb);
		c_SaveNewAddr->execute();
	}


_SQLite_add_AddrCmd ::_SQLite_add_AddrCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
void _SQLite_add_AddrCmd::execute()
	{
		c_sqlite3addAddrtoPers = new Sqlite_add_Addr_toPers(pdb);
		c_sqlite3addAddrtoPers->execute();
	}


_SQLite_insert_PersAddrCmd::_SQLite_insert_PersAddrCmd(PersonDB *_pdb)
	{
		this->pdb = _pdb;
	}
void _SQLite_insert_PersAddrCmd::execute()
	{
		c_sqlite3insPersAddr = new Sqlite_insert_PersAddr(pdb);
		c_sqlite3insPersAddr->execute();
		//c_sqlite3insPersAddr->execute2();
		//c_sqlite3insPersAddr->test();
	}



void _SQLite_purchase_prod_processCmd::execute() 
	{
		sqlite_purchase_prod = new Sqlite_purchase_prod_process();
		sqlite_purchase_prod->execute();
	}


void _LoginCmd::execute()
	{
		login = new Login();
		login->execute();
	}


_LogoutCmd::_LogoutCmd(Login_stmt *_login_stmt)
	{
		this->login_stmt = _login_stmt;
	}

void _LogoutCmd::execute() 
	{
		login_stmt->logout();
	}


//invoker
RemoteController::RemoteController(Cmd* _cmd)
	{
		cmd = _cmd;
	}

	//change the command
void RemoteController::setCmd(Cmd * _cmd)
	{
		this->cmd = _cmd;
	}

void RemoteController::pressButton()
	{
		cmd->execute();
	}


//client

void RemoteControllerTest::execute()
	{
		//Eines "Integer" dafuer, die While loop kontrollieren.
		int while_i = 1;
		int ss = 0;
		int sss = 0;

		while (while_i)
		{
			int j;
			//21.DB_insert_persInfo 

			if (_login_stmt->bool_login_stmt == true)
			{
				cout << "\n\nID derzeit eingeloggt : " + _login_stmt->activated_login_id;
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