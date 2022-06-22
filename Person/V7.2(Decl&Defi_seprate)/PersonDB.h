#pragma once
#include "Address.h"
#include "Person.h"
//#include <map>
//#include <vector>

class PersonDB
{
public:
	map <int, Person*> personen;
	map <int, Person*>::iterator it;

	PersonDB();
	
	int checkSexAndPutNumOut(string _dummyString);
	int checkStadtAndPutNumOut(string _dummyString);
	int createNewNonDuplicateUserNum(PersonDB* _pdb);
};
//
//int checkStadtAndPutNumOut(string _dummyString);
//int checkSexAndPutNumOut(string _dummyString);
