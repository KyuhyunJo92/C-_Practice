#include "stdafx.h"
#include "labyrinth.h"

#include <cstdlib>//abs(): output, absolute value.=> abs(-5) : 5
#include <ctime>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	cout << "Verwendung: ";
	cout << argv[0] << " [<breite> [<hoehe> [<startwert>]]" << endl;
	int Breite = 50;
	int Hoehe = 50;

	if (argc >= 2) {//in CMD console, @path/labyrinth.exe|40(B) 40(H) anynumber(for srand) 
		Breite = atoi(argv[1]);
		if (Breite < 3) return 1;
	}

	if (argc >= 3) {
		Hoehe = atoi(argv[2]);
		if (Hoehe < 3) return 2;
	}

	//Construct tLabtrinth obj, (40,40), ZelleBesucht[1600], Boden[1640], Wand[1640]
	tLabyrinth Labyrinth(Breite, Hoehe);

	// Durch Angabe einer Nummer kann immer wieder das gleiche
	// Labyrinth erzeugt werden.
	int ZufallsStartwert = 0;//random starting value
	if (argc >= 4) {
		ZufallsStartwert = atoi(argv[3]);
	}

	// Wenn der Aufrufer nichts Anderes angibt, nehmen wir die 
	// aktuelle Uhrzeit als Startwert.
	if (ZufallsStartwert == 0) {
		ZufallsStartwert = time(0);//get time(bunch of second), amount of second from 01.01.1970 to now
	}
	srand(ZufallsStartwert);//srand = seed of rand(), time => at every moment has other value.

							// wir brauchen eine zufaellige Startkoordinate
	int x = rand() % Breite;//0 <= x < x variable hat jedenmal andere Wert.
	int y = rand() % Hoehe;//0 <= y < y variable hat jedenmal andere Wert.
	//Zuerste Koordinate Punkt(x,y)					   
							   // ... und erzeugen ein Labyrinth
	Labyrinth.generiere(x, y);//tLabyrinth::gerneriere,
	Labyrinth.durchbrecheTrennung(1, -1, 1, 0);
	// Unser Stolz gehoert auf den Bildschirm
	Labyrinth.zeige();//Malen.
}
