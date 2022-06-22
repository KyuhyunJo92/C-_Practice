#include "PersonDB.h"

PersonDB::PersonDB()
{
};


int PersonDB::checkSexAndPutNumOut(string _dummyString)
{
	//this is a worst "HardCoding". It would have very easily typo. 
	int i = 0;
	if (_dummyString == "Undefined") i = 0;
	else if (_dummyString == "Male") i = 1;
	else if (_dummyString == "Female") i = 2;

	return i;
}
int PersonDB::checkStadtAndPutNumOut(string _dummyString)
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
int PersonDB::createNewNonDuplicateUserNum(PersonDB* _pdb)
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
//
//int PersonDB::checkStadtAndPutNumOut(string _dummyString)
//{
//	//this is a worst "HardCoding". It would have very easily typo. 
//	int i = 0;
//	if (_dummyString == "Unselected") i = 0;
//	else if (_dummyString == "Stuttgart") i = 1;
//	else if (_dummyString == "Filderstadt") i = 2;
//	else if (_dummyString == "Frankfurt") i = 3;
//	else if (_dummyString == "Berlin") i = 4;
//
//	return i;
//}
//int PersonDB::checkSexAndPutNumOut(string _dummyString)
//{
//	//this is a worst "HardCoding". It would have very easily typo. 
//	int i = 0;
//	if (_dummyString == "Undefined") i = 0;
//	else if (_dummyString == "Male") i = 1;
//	else if (_dummyString == "Female") i = 2;
//
//	return i;
//}