#include "stdafx.h"
#include "Ente.h"
#include <iostream>

using namespace std;

int main()
{
	Ente *stockEnte = new StockEnte();
	stockEnte->anzeigen();
	stockEnte->schwimmen();
	stockEnte->flugVerhalten->fliegen();
	
	Ente *gummiEnte = new GummiEnte();
	gummiEnte->flugVerhalten->fliegen();
	gummiEnte->quakVerhaleten->quaken();


	
	return 0;

}