#pragma once
#include "Common.h"
#include "Address.h"
#include "Person.h"
#include <vector>

class PersonDB
{
private:
	map <int, Person*>::iterator it;
	map <int, Person*> personen ;

	//Zweite output muss 2, aber se ist 1000... problem
	int createNewNonDuplicateUserNum()
	{
		int count = 0;

		for (it = personen.begin(); it != personen.end();it++)
		{
				if (it->first == count)
				{
					count++;
				}
		}
		return count;
	}
		//for (int i = 0; i < 1000; i++)
		//	{
		//		if (it->first == i)
		//		{
		//			count = count + i;
		//			it++;
		//		}
		//		else if( it->first)
		//		{
		//			return count;
		//		}
		//}
		//int NewUserNum = 1;
		//int i = 1;
		//int j = 1;
		//it = personen.begin();
		//
		//createNewNonDuplicateUserNum()
		//while (it != personen.end())
		//{
		//	while (i)
		//	{
		//		if (it->second != nullptr) //if there is a value
		//		{
		//			if (it->first == j) //compare 
		//			{
		//				j++; 
		//			}
		//		}
		//		else i = 0;
		//	}
		//	it++;
		//}

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
		////finde neue nicht doppelte Nummer.
		//if (!personen[0]->)
		//{
		//	NewUserNum = 1;
		//}
		//else
		//{
		//	for (it = personen.begin(); it != personen.end(); it++)
		//	{
		//		////만약 해당 자리에 정보가 저장되어 있지 않다면
		//		//if(!it->first <1000)
		//		//{
		//			//1000이 넘어가지 않는 범위 내에서
		//		if (count < 1000) {
		//			NewUserNum = count + 1;
		//			//새로운 사용자번호를 지정한다.
		//			return NewUserNum;
		//		}
		//		count = it->first;
		//	}
		//}
public:
	//construct
	PersonDB()
	{
		Person* person = new Person();
		this->personen.emplace(make_pair(0,person));
		//참조 가능한 외부파일 목록 열거하고 선택해서 불러오거나,
		//새롭게 데이터베이스 다시 만들기.
	};
	~PersonDB()
	{
		//VECTOR 파일 추출여부 물어보고 동의할경우 외부 파일로 저장
		//저장시에는 CSV파일형태로 (, 기준으로 나누고), 열로 내용구분, 행으로 사람구분.
	}

	void registerNewPerson()
	{
		int i = createNewNonDuplicateUserNum();
		Person* person = new Person();//Ruft es 'default Construct' auf.
		person->regesterAllOfMemberVariable();
		personen.emplace(make_pair(i,person));
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
			cout << "User Number :" + to_string(userNum)<<"\n";
			personen[userNum]->printPersonalInfo();
		}
		else
		{
			cout << "No File for UserNumber :" + to_string(userNum)<<"\n";
		}
	}
	void changeInfo()
	{
		cout << "Bitte tun Sie die Usernumber rein.";
		int j;
		cin >> j;


		cout << "1.Vorname  2.Nachname  3.Geburtsdatum  4.Geschlecht  5.Stadt"<<endl;
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

		default :
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

	//vorname, nachname, geburtstag, sex, stadt
	//numOfPDataSort = 5;
	//open file. =>
	//while(!iMyFile.eof())
	//{
	//	for(int i=0; i<numOfPDataSort; 
	//	use "getline(iMyFile,dummyString,','))"
	//	{
	//		
	//	}
	//}
	
	void importCSVFile()//ifstream
	{
		string dummyString;
		ifstream iMyFile;
		personen.clear();
		Person* person = new Person();
		iMyFile.open("Personen.csv");

		if (iMyFile.is_open())
		{
			while (!iMyFile.eof())
			{
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

				getline(iMyFile, dummyString, ',');
				//받은 dummyString값을 int로 바꾸고
				person->setStadt(checkSexAndPutNumOut(dummyString));
			}
			//while (getline(iMyFile, dummyString,','));
			//getline(파일객체,저장변수,구분자);
			//getline(fs, str_buf, ',');
		}
		int i = createNewNonDuplicateUserNum();
		personen.emplace(make_pair(i, person));
		iMyFile.close();
		//if(txt file is exist)
		//bring the file.
		//if not exist, "there is no TXT file in the Path"
	}
	void exportCSVFile()//ofstream
	{
		ofstream oMyFile;
		oMyFile.open("Personen.csv");
		
		for (it = personen.begin(); it != personen.end(); it++) 
		{
			oMyFile << it->second->getVorname() +","
				+ it->second->getNachname()		+ ","
				+ it->second->getGeburtsdatum() + ","
				+ it->second->getSex()			+ ","
				+ it->second->getStadt()		+ "\n";
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
	void mainFuction()
	{	
		int while_i = 1;//Eines "Integer" dafuer, die While loop kontrollieren.
		while (while_i)
		{
			int j;
			cout << "0.EXIT 1.Anmelden  2.Abmelden  3.AnzeigenAllenInfo  4.Nachschlagen  5.Data aendern  6.exportieren  7.importieren \n";
			cout << "Welche Funtion moechten Sie benutzen?";
			cin >> j;
			switch (j)
			{
			case 0: while_i = 0;
				break;
			case 1: registerNewPerson();
				break;
			case 2: deletePerson();
				break;
			case 3: viewAllInfo();
				break;
			case 4: searchInfo();
				break;
			case 5: changeInfo();
				break;
			case 6: exportCSVFile();
				break;
			case 7: importCSVFile();
				break;
			
			default:
				break;
			}
		}
	}
}; 