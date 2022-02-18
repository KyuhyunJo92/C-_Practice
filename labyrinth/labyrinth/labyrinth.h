#pragma once

#ifndef LABYRINTH_H
#define LABYRINTH_H

// Die Klasse tLabyrinth beschreibt ein Labyrinth. Es enthaelt
// ein dynamisch angefordertes Array von tZelle und kann
// erzeugt und gezeichnet werden.
class tLabyrinth {
public:
	tLabyrinth(int pBreite, int pHoehe);
	~tLabyrinth();
	void generiere(int zufX, int zufY);
	void zeige();
	bool istTrennung(int x, int y, int x1, int y1);
	void bauAusgangWest(int y)
	{
		durchbrecheTrennung(0, y, -1, y);
	}
	void bauAusgangOst(int y)
	{
		durchbrecheTrennung(Breite, y, Breite - 1, y);
	}
	void bauAusgangNord(int x)
	{
		durchbrecheTrennung(x, Hoehe, x, Hoehe - 1);
	}
	void bauAusgangSued(int x)
	{
		durchbrecheTrennung(x, 0, x, -1);
	}
	void durchbrecheTrennung(int x, int y, int x1, int y1);

protected:
	int Breite;
	int Hoehe;

private:
	bool istZelleBesucht(int x, int y)
	{
		return ZelleBesucht[x + y*Breite];
	}
	bool istZelleUnbesucht(int x, int y)
	{
		return !ZelleBesucht[x + y*Breite];
	}
	void setZelleBesucht(int x, int y)
	{
		//x+y*Breite=> 
		//(0,0)	 = ZB[0], 
		//(39,0) = ZB[39], 
		//(0,1)  = ZB[40],
		//(39,1) = ZB[79],
		//...//
		//(39,39)= ZB[1600]
		ZelleBesucht[x + y*Breite] = true;
	}
	void untersucheNachbarn(int x, int y, int x1, int y1);
	void untersucheRechts(int x, int y);
	void untersucheOben(int x, int y);
	void untersucheUnten(int x, int y);
	bool istGueltigeKoordinate(int x, int y);
	bool *getTrennung(int x, int y, int x1, int y1);
	bool *ZelleBesucht; // Das Feld fuer die Labyrinthzellen
	bool *Wand; // Die Trennwaende zwischen den Zellen
	bool *Boden; // Die Bodenplatten zwischen den Zellen
};

#endif
