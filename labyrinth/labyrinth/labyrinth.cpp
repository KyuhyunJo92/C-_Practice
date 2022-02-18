// labyrinth.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "labyrinth.h"

#include <cstdlib>//abs(): output, absolute value.=> abs(-5) : 5
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
// Der Konstruktor erfaehrt die Dimension des Labyrinths.
tLabyrinth::tLabyrinth(int pBreite, int pHoehe)
	: Breite(pBreite), Hoehe(pHoehe)
{
	ZelleBesucht = new bool[Breite * Hoehe];
	for (int i = 0; i<Breite*Hoehe; ++i) {
		ZelleBesucht[i] = false;
	}
	Boden = new bool[Breite * (Hoehe + 1)];
	for (int i = 0; i<Breite*(Hoehe + 1); ++i) {
		Boden[i] = true;//initialize statement : all Boden,Wall are closed.
	}
	Wand = new bool[(Breite + 1) * Hoehe];
	for (int i = 0; i<(Breite + 1)*Hoehe; ++i) {
		Wand[i] = true;
	}
}

tLabyrinth::~tLabyrinth()//destructor
{
	delete[] ZelleBesucht;
	delete[] Boden;
	delete[] Wand;
}

// istGueltigeKoordinate vereinfacht die Abfrage, ob eine
// Koordinate ueberhaupt innerhalb des Labyrinths liegt
//check the current coordinate point is in the range(True),out of range(False)
bool tLabyrinth::istGueltigeKoordinate(int x, int y)
{
	if (x<0 || y<0 || x >= Breite || y >= Hoehe) return false;
	return true;
}

//getTrennung return(x aenderen=>Wand, y aenderen=>Boden)
bool* tLabyrinth::getTrennung(int x, int y, int x1, int y1)//prameters sind Koordinate Wert.
														   //Wenn punkt bewegt links oder recht, rückgabe ist Boden. 
														   // Eine der beiden Koordinaten kann -1 sein.
{
	//moved vertically	
	if ((x == x1) && (abs(y - y1) == 1)) {
		// x-Koordinate gleich, also Boden!
		y = y>y1 ? y : y1; // das obere Feld ist relevant //moved up= y1, down=y
		return &Boden[x + Breite*y];//bool Boden
	}
	//moved horizontally
	else if (y == y1 && abs(x - x1) == 1) {
		// y-Koordinate gleich, also Wand!
		x = x>x1 ? x : x1; // das rechte Feld ist relevant//recht =x, links=x1
		return &Wand[x + (Breite + 1)*y];//bool Wand
	}

	else {
		cout << "getTrennung unmoegliche Parameter: " << x << "," << y << " - "
			<< x1 << "," << y1 << endl;
	}
	return 0; // das sollte zum Absturz fuehren!
}

bool tLabyrinth::istTrennung(int x, int y, int x1, int y1)
{
	bool *Trennung = getTrennung(x, y, x1, y1);
	return *Trennung;
}

void tLabyrinth::durchbrecheTrennung(int x, int y, int x1, int y1)
{
	bool *Trennung = getTrennung(x, y, x1, y1);
	*Trennung = false;
}

void tLabyrinth::untersucheNachbarn(int x, int y, int x1, int y1)
{
	//wenn Koordinate wert ist gueltig,
	if (istGueltigeKoordinate(x1, y1)) {
		//wenn Die Zelle noch nicht besucht.
		if (istZelleUnbesucht(x1, y1)) {
			// Neuer Nachbar: Wand durchbrechen
			durchbrecheTrennung(x, y, x1, y1);
			// rekursiver Aufruf!!!!
			generiere(x1, y1);
		}
	}
}

// generiere ist eine rekursive Funktion zur Erzeugung eines Labyrinths.
void tLabyrinth::generiere(int x, int y)
{
	// ist diese Zelle bereits besucht worden?
	if (istZelleBesucht(x, y)) return;
	// markiere sie als bereits abgearbeitet
	setZelleBesucht(x, y);//ZelleBesucht[x+y*Breite] = true.

	// Die Reihenfolge, in welche Richtung gelaufen werden soll, muss
	// variieren. Das setzen wir einfach mit einem Reihenfolge-Array um.
	int Reihenfolge[4] = { 0, 1, 2, 3 };
	//Richtung[4][2] = { {[0][0],[0][1]},{[1][0],[1][1]},{[2][0],[2][1]},{[3][0],[3][1]} }
	int Richtung[4][2] = { { -1, 0 },{ 1, 0 },{ 0, 1 },{ 0, -1 } };

	// wir mischen die Reihenfolge ein wenig//Mischung!
	for (int i = 0; i<12; i++)
	{ // ein paar Mal durchlaufen
								 // wir waehlen zufaellig Indizes des Reihenfolge-Arrays
		int a = rand() % 4;
		int b = rand() % 4;
		if (a != b)
		{
			// wenn sie sich unterscheiden, tauschen wir!
			int zwischen = Reihenfolge[a];
			Reihenfolge[a] = Reihenfolge[b];
			Reihenfolge[b] = zwischen;
		}
	}

	// von der aktuellen Zelle aus untersuchen wir die
	// Nachbarzellen. Die Funktion untersuche reisst die
	// die Wand zu einer bisher nicht besuchten Zelle ein
	// und ruft von dort aus die Rekursion generiere(x,y) auf.
	for (int i = 0; i<4; i++) 
	{//Aendern die Richtung um 90 Grad und wiederholen dies 4 Mal.
		int j = Reihenfolge[i];
		//j=0 => (x,y,x-1,y) , j=1 => (x,y,x+1,y), j=2 => (x,y,x,y+1), j=3 => (x,y,x,y-1);
		untersucheNachbarn(x, y, x + Richtung[j][0], y + Richtung[j][1]);
	}
}

// zeige gibt das Labyrinth auf der Konsole aus. Es ist plattformunabhaenig
// und setzt nur voraus, dass die Schrift nicht proportional ist.
void tLabyrinth::zeige()
{
	int x, y;
	// Durchlaufe alle Zeilen
	for (y = Hoehe - 1; y >= 0; y--)
	{
		// Zeichne die untere Linie
		for (x = 0; x<Breite; x++)
		{
			
			// oben, schloss
			if (istTrennung(x, y, x, y + 1)) {
				cout << "+--";
			}

			// oben, oeffen
			else {
				cout << "+  ";
			}
			/*std::this_thread::sleep_for(std::chrono::milliseconds(50));*/
		}
		cout << "+" << endl;
		// Es folgt der Zelleninhalt

		for (x = 0; x<Breite; x++)
		{
			
			// Zeichne die linke Wand, so sie da ist.
			if (istTrennung(x, y, x - 1, y)) { // links
				cout << "|";
			}
			else {
				cout << " ";
			}
			// zeichne den Flaecheninhalt
			cout << "  ";
			/*std::this_thread::sleep_for(std::chrono::milliseconds(50));*/
		}
		// die rechte Wand ist immer da

		if (istTrennung(x, y, x - 1, y)) {
			cout << "|";
		}
		else {
			cout << " ";
		}
		cout << endl;
		/*std::this_thread::sleep_for(std::chrono::milliseconds(50));*/
	}


	// Nun noch die Abschlusslinie
	for (x = 0; x<Breite; x++) {
		if (istTrennung(x, 0, x, -1)) { // unten
			cout << "+--";
		}
		else {
			cout << "+  ";
		}
	}
	cout << "+" << endl;
}


