#pragma once
#include "Address.h"
#include "Person.h"
//#include <vector>

class PersonDB
{
public:
	map <int, Person*> personen;
	map <int, Person*>::iterator it;

	PersonDB()
	{
		/*Person* person = new Person();*//*
		cnndun = new CreateNewNonDuplicateUserNum(this);*/
		/*this->personen.emplace(make_pair(createNewNonDuplicateUserNum(this), person));*/
		//참조 가능한 외부파일 목록 열거하고 선택해서 불러오거나,
		//새롭게 데이터베이스 다시 만들기.
	}; 

	/*int createNewNonDuplicateUserNum()
	{
		int count = 0;

		for (it = personen.begin(); it != personen.end(); it++)
		{
			if (it->first == count)
			{
				count++;
			}
		}
		return count;
	}*/

	int checkSexAndPutNumOut(string _dummyString)
	{
		//this is a worst "HardCoding". It would have very easily typo. 
		int i = 0;
		if (_dummyString == "Undefined") i = 0;
		else if (_dummyString == "Male") i = 1;
		else if (_dummyString == "Female") i = 2;

		return i;
	}
	int checkStadtAndPutNumOut(string _dummyString)
	{
		//this is a worst "HardCoding". It would have very easily typo. 
		int i = 0;
		if (_dummyString == "Unselected") i = 0;
		else if (_dummyString == "Stuttgart") i = 1;
		else if (_dummyString == "Filderstadt") i = 2;
		else if (_dummyString == "Frankfurt") i = 3;
		else if (_dummyString == "Berlin") i = 4;

		return i;

	}
	int createNewNonDuplicateUserNum(PersonDB* _pdb)
	{
		int count = 0;

		for (_pdb->it = _pdb->personen.begin(); _pdb->it != _pdb->personen.end(); _pdb->it++)
		{
			if (_pdb->it->first == count)
			{
				count++;
			}
		}
		return count;
	}
};

int checkStadtAndPutNumOut(string _dummyString)
{
	//this is a worst "HardCoding". It would have very easily typo. 
	int i = 0;
	if (_dummyString == "Unselected") i = 0;
	else if (_dummyString == "Stuttgart") i = 1;
	else if (_dummyString == "Filderstadt") i = 2;
	else if (_dummyString == "Frankfurt") i = 3;
	else if (_dummyString == "Berlin") i = 4;

	return i;
}
int checkSexAndPutNumOut(string _dummyString)
{
	//this is a worst "HardCoding". It would have very easily typo. 
	int i = 0;
	if (_dummyString == "Undefined") i = 0;
	else if (_dummyString == "Male") i = 1;
	else if (_dummyString == "Female") i = 2;

	return i;
}

/*class RemoteController
{
private:
Cmd* cmd;

public :
void setCmd(Cmd * _cmd)
{
this->cmd = _cmd;
}

void pressButton()
{
cmd->execute();
}
};
//funktionen
	
	void registerNewPerson()
	{
		int i = createNewNonDuplicateUserNum();
		Person* person = new Person();//Ruft es 'default Construct' auf.
		person->registerAllOfMemberVariable();
		personen.emplace(make_pair(i, person));
		cout << "\nNeue Benutzer wird registriert.\n";
		cout << "Benutzer Nummer : " + to_string(i) << endl;
		person->printPersonalInfo();
	}
	void deletePerson()
	{
		int userNum;
		cout << "input user Number";
		cin >> userNum;
		personen.erase(userNum);
		//현재 벡터에 저장되어있는 사람의 이름과 인덱스 번호를 보여준다?
		//목록에 이름이 많을 경우 찾기 힘들 수 있음.
		//사람마다 유저 번호라는 고유값을 가지고 있어야한다.멥을 이용하는게 좋지않을까? 
	}
	void searchInfo()
	{
		int userNum;
		cout << "input user Number : ";
		cin >> userNum;
		if (personen[userNum])
		{
			cout << "User Number :" + to_string(userNum) << "\n";
			personen[userNum]->printPersonalInfo();
		}
		else
		{
			cout << "No File for UserNumber :" + to_string(userNum) << "\n";
		}
	}
	void changeInfo()
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
		case 1: personen[j]->changeVorname();
			break;

		case 2: personen[j]->changeNachname();
			break;

		case 3: personen[j]->changeGeburtsdatum();
			break;

		case 4: personen[j]->changeSex();
			break;

		case 5: personen[j]->changeStadt();
			break;

		default:
			cout << "wrong Input.";
			break;
		}
	}
	void viewAllInfo()
	{
		for (it = personen.begin(); it != personen.end(); it++)
		{
			it->second->printPersonalInfo();
		}
	}
	

	//import Funktionen
	void importWordFile()
	{
		string dummyString;
		ifstream iMyFile;
		personen.clear();
		Person* person = new Person();
		iMyFile.open("Personen.docx");

		if (iMyFile.is_open())
		{
			while (!iMyFile.eof())
			{
				getline(iMyFile, dummyString);
			}
		}
	}

	//export Funktion
	
	void importCSVFile()//ifstream
	{
		string testString;
		string dummyString;
		ifstream iMyFile;
		personen.clear();
		iMyFile.open("Personen.csv");
		int i;
		while (iMyFile.is_open())
		{
			while (!iMyFile.eof())
			{
				Person* person = new Person();

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

				i = createNewNonDuplicateUserNum();
				personen.emplace(make_pair(i, person));
			}
			//while (getline(iMyFile, dummyString,','));
			//getline(파일객체,저장변수,구분자);
			//getline(fs, str_buf, ',');
			if(iMyFile.eof())
			{
				iMyFile.close();
			}
		}
		//if(txt file is exist)
		//bring the file.
		//if not exist, "there is no TXT file in the Path"
	}
	void importTXTFile()//ifstream
	{
		string dummyString;
		int dummyUserNum;
		string line;
		int index;
		ifstream iMyFile;
		personen.clear();

		iMyFile.open("Personen.txt");
		cout << "file is opened";
		while (iMyFile.is_open())
		{
			
			//문제는 포인터가 가리키는 메모리에 저장된 값이 같다는 것이다.
			//값을 분리해야한다.
			
			Person* person = new Person();

			while (!iMyFile.eof())
			{
				getline(iMyFile, line, '\n');
				if (line.find("Usernumber") != string::npos)
				{
					index = line.find("Usernumber : ");
					index = index + 13;
					dummyString = line.substr(index, '\n');
					dummyUserNum = stoi(dummyString);
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
					personen.emplace(make_pair(dummyUserNum, person));
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
		//while (getline(iMyFile, dummyString,','));
		//getline(파일객체,저장변수,구분자);
		//getline(fs, str_buf, ',');
	}
	//if(txt file is exist)
	//bring the file.
	//if not exist, "there is no TXT file in the Path"

	void exportCSVFile()//ofstream
	{
		ofstream oMyFile;
		oMyFile.open("Personen.csv");

		for (it = personen.begin(); it != personen.end(); it++)
		{
			oMyFile << it->second->getVorname() + ","
				+ it->second->getNachname() + ","
				+ it->second->getGeburtsdatum() + ","
				+ it->second->getSex() + ","
				+ it->second->getStadt() + "\n";
		}

		oMyFile.close();
		//oMyFile>>
		//fstream fs;
		//fs.open("test.csv", ios::in);
		//this data should be sperated with "," wie CSV data
		//enum type(sex, stadt -> take as a string => male,female,undefined  stuttgart...)
		//}
		//void inputDataOfMapContainerToFile()
		//{
		//	//use'TakeDataOfMapContainerOut()'method
			
	}
	void exportTXTFile()
	{
		ofstream oMyFile;
		oMyFile.open("Personen.txt");

		for (it = personen.begin(); it != personen.end(); it++)
		{
			oMyFile <<

				"Usernumber : " + to_string(it->first) + "\n"
				"Vorname    : " + it->second->getVorname() + "\n"
				"Nachname   : " + it->second->getNachname() + "\n"
				"Geburtstag : " + it->second->getGeburtsdatum() + "\n"
				"Geschlecht : " + it->second->getSex() + "\n"
				"Stadt      : " + it->second->getStadt() + "\n"";\n";
		}

		oMyFile.close();
	}
	
	//void mainFuction()
	//{
	//	int while_i = 1;//Eines "Integer" dafuer, die While loop kontrollieren.
	//	while (while_i)
	//	{
	//		int j;
	//		cout << "0.EXIT 1.Anmelden  2.Abmelden  3.AnzeigenAllenInfo  4.Nachschlagen  5.Data aendern  6.exportieren  7.importieren \n";
	//		cout << "Welche Funtion moechten Sie benutzen?";
	//		cin >> j;
	//		switch (j)
	//		{
	//		case 0: while_i = 0;
	//			break;
	//		case 1: registerNewPerson();
	//			break;
	//		case 2: deletePerson();
	//			break;
	//		case 3: viewAllInfo();
	//			break;
	//		case 4: searchInfo();
	//			break;
	//		case 5: changeInfo();
	//			break;
	//		case 6: exportCSVFile();
	//			break;
	//		case 7: importCSVFile();
	//			break;
	//
	//		default:
	//			break;
	//		}
	//	}
	//}*/