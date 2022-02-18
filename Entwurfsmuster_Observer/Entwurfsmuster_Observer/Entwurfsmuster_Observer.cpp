// Entwurfsmuster_Observer.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

//class Beobachter deklaration
class Beobachter
{

public:
	virtual void aktualisieren(float temp, float feucht, float druck) = 0;
};

//class Subjekt deklaration
class Subjekt
{
public: 
	//virtual methods registrieren, entferne, benachrichtige Beobachter deklaration
	virtual void registriereBeobachter(Beobachter *b) = 0;
	virtual void entferneBeobachter(Beobachter *b) = 0;
	virtual void benachrichtigeBeobachter() = 0;
};

//class AnzeigeElement deklaration
class AnzeigeElement
{
public: 
	virtual void anzeigen() = 0;
};

//virtual methods registrieren, entferne, benachrichtige Beobachter implementation

class WetterDaten : public Subjekt 
{
private:
	
	vector<Beobachter*> beobachter;
	float temperatur;
	float feuchtigkeit;
	float luftdruck;


public:
	//WetterDaten() {
	//	list<Beobachter> beobachter;//im buch, es 'beobachter = new Arraylist()' geschrieben wird. 
	//}
	virtual void benachrichtigeBeobachter()
	{
		vector<Beobachter *>::iterator iter = beobachter.begin();
		for ( ; iter !=beobachter.end(); iter++)
		{
			Beobachter *b = *iter;//in die Zeile, bedeutung von "*iter" "Beobachter pointer" ist,
								  // Deswegen muss der Variable ein Dereferenz deklarationen.
			b->aktualisieren(temperatur, feuchtigkeit, luftdruck);
		}
	}
	virtual void registriereBeobachter(Beobachter* b)
	{
		beobachter.push_back(b);//wenn der parameter als * gedeklaratiert wird und der list <Beo*> auch,
								// dann muss der Argument von push_back einen Address sein.
								// Für referenzieren zu sein können. 
	}

	//when list, vector erase element of them, they use find method, iterator. because, those have only pop_back() member method   
	virtual void entferneBeobachter(Beobachter* b)
	{
		vector<Beobachter*>::iterator iter = beobachter.begin();
		iter = find(beobachter.begin(), beobachter.end(), b);
		if (iter != beobachter.end()) beobachter.erase(iter);
	}


	void messwerteGeaendert()
	{
		benachrichtigeBeobachter();
	}

	//set die werten(temperatur, feuchtigkeit, luftdruck)
	void setMesswerte(float temp, float feucht, float druck)
	{
		this->temperatur = temp;
		this->feuchtigkeit = feucht;
		this->luftdruck = druck;
		messwerteGeaendert();
	}
/*
	void anzeigenBeobachterslist()
	{
		Beobachter * b;
		vector<Beobachter*>::iterator iter = beobachter.begin();
		for (; iter != beobachter.end(); iter++) 
		{
			b = *iter;
			b->
			
		}
	}*/
};


class AktuelleBedingungenAnzeige : public Beobachter, public AnzeigeElement
{
private:
	float temperatur;
	float feuchtigkeit;
	Subjekt* wetterDaten;

public:
	AktuelleBedingungenAnzeige(Subjekt* wetterDaten)
	{
		this->wetterDaten = wetterDaten;//member variable (belong to objekt of class A-B-A) = pointer parameter.
		wetterDaten->registriereBeobachter(this);
	}
	//implementierung 'Method aktualisieren' von Class Beobachter
	virtual void aktualisieren(float temp, float feucht, float druck)
	{
		this->temperatur = temp;
		this->feuchtigkeit = feucht;
		anzeigen();
	}

	
	//implementierung 'Method anzeigen' von Class AnzeigeElement
	virtual void anzeigen()
	{
		cout << "Aktuelle Wetterbedingungen: "<< this->temperatur << "Grad C und" <<this ->feuchtigkeit <<"% feuchtigkeit";
		//der Ausdruck muss einen ganzzahligen Enumerationstyp der einen Enumerationstyp ohne Bereichseinschränkung aufweisen
	}//wenn die typ des parameter ein Klass ist, es gibt dreie verschidene moeglichkeit. Objekt, pointer oder referenze.
};

int main()
{
	WetterDaten* wetterDaten_1 = new WetterDaten();
	AktuelleBedingungenAnzeige* ABA = new AktuelleBedingungenAnzeige(wetterDaten_1);
	cout << endl;
	wetterDaten_1->setMesswerte(15.5, 40.0, 30.4);	//setting the values to member value 
													//of objekt of class wetterdaten
													//additionally benachreichtigen zu beobachters
													//will be operated. 
	cout << endl;
	ABA->anzeigen();								//if you want to show the data
													//without changing the weather Data,
													//you can use directly the method anzeigen().   
	cout << endl;
	wetterDaten_1->benachrichtigeBeobachter();

	return 0;
}

