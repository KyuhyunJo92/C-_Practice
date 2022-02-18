// VariablesEX.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
char myVar = 'A';
char myFuncn() {
	char myVar = 'B';
	return myVar;
}
int main()
{
	cout << "Funcn call:" << myFuncn() << endl;
	cout << "Value of myVar: " << myVar << endl;
	myVar = 'Z';
	cout << "Funcn call:" << myFuncn() << endl;
	cout << "Value of myVar: " << myVar <<endl;
    return 0;
}

