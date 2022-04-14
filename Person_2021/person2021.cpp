#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class C {
public:
	int index[10];
	//constuctor : initialize index[]
	C() {
		for (int i = 0; i < 10; i++) {
			index[i] = i;
		}
	}
	struct PersonAnlage {
		char name[20];
		char vorname[20];
		char geburtsdatum[20];
	};
	struct WohnortAdressAnlage {
		char strasse[20];
		char hausnummer[20];
		char plz[20];
		char ort[20];
		char typ[20];
	};
	struct ArbeitplatzAdressAnlage {
		char strasse[20];
		char hausnummer[20];
		char plz[20];
		char ort[20];
		char typ[20];
	};

	struct PersonAnlage PA[10] = { "default", };
	struct WohnortAdressAnlage WAA[10] = { "default", };
	struct ArbeitplatzAdressAnlage AAA[10] = { "default", };

	char N[20], V[20], G[20], WS[20], WH[20], WP[20], WO[20], WT[20], AS[20], AH[20], AP[20], AO[20], AT[20];

	//fstream fo;
	//printAll zeigt einem struct auf Console.
	void printAll(int index) {

		std::cout << "===========================================" << endl;
		std::cout << "Index Number     : " << index << endl;
		std::cout << endl;
		std::cout << "Name             : " << PA[index].name << endl;
		std::cout << "Vorname          : " << PA[index].vorname << endl;
		std::cout << "Geburtsdatum     : " << PA[index].geburtsdatum << endl;
		std::cout << endl;
		std::cout << "typ              : Wohnort" << endl;
		std::cout << "Strasse          : " << WAA[index].strasse << endl;
		std::cout << "Hausnummer       : " << WAA[index].hausnummer << endl;
		std::cout << "Postleitzahl     : " << WAA[index].plz << endl;
		std::cout << "Ort              : " << WAA[index].ort << endl;
		std::cout << endl;
		std::cout << "typ              : Arbeitplatz" << endl;
		std::cout << "Strasse          : " << AAA[index].strasse << endl;
		std::cout << "Hausnummer       : " << AAA[index].hausnummer << endl;
		std::cout << "Postleitzahl     : " << AAA[index].plz << endl;
		std::cout << "Ort              : " << AAA[index].ort << endl;
		std::cout << "===========================================" << endl;
	}
	void readAll(int index) {
		char RN[20];
		ifstream fi(to_string(index) + ".txt");
		std::cout << "Index Nummer     : " << index << endl;
		fi.seekg(20);
		fi.get(RN, 20);
		std::cout << "Name             : " << RN << endl;
		fi.seekg(61);
		fi.get(RN, 20);
		std::cout << "Vorname          : " << RN << endl;
		fi.seekg(101);
		fi.get(RN, 20);
		std::cout << "Geburtsdatum     : " << RN << "\n" << endl;
		fi.close();
	}

	void readPA(int index) {
		char RN[20];
		ifstream fi(to_string(index) + ".txt");
		std::cout << "Index Nummer     : " << index << endl;
		fi.seekg(20);
		fi.get(RN, 20);
		std::cout << "Name             : " << RN << endl;
		fi.seekg(61);
		fi.get(RN, 20);
		std::cout << "Vorname          : " << RN << endl;
		fi.seekg(101);
		fi.get(RN, 20);
		std::cout << "Geburtsdatum     : " << RN << "\n" << endl;
		fi.seekg(141);
		fi.get(RN, 20);
		std::cout << "typ              : " << RN << endl;
		fi.seekg(181);
		fi.get(RN, 20);
		std::cout << "Strasse          : " << RN << endl;
		fi.seekg(221);
		fi.get(RN, 20);
		std::cout << "Hausnummer       : " << RN << endl;
		fi.seekg(261);
		fi.get(RN, 20);
		std::cout << "Postleitzahl     : " << RN << endl;
		fi.seekg(301);
		fi.get(RN, 20);
		std::cout << "Ort              : " << RN << "\n" << endl;
		fi.seekg(341);
		fi.get(RN, 20);
		std::cout << "typ              : " << RN << endl;
		fi.seekg(381);
		fi.get(RN, 20);
		std::cout << "Strasse          : " << RN << endl;
		fi.seekg(421);
		fi.get(RN, 20);
		std::cout << "Hausnummer       : " << RN << endl;
		fi.seekg(461);
		fi.get(RN, 20);
		std::cout << "Postleitzahl     : " << RN << endl;
		fi.seekg(501);
		fi.get(RN, 20);
		std::cout << "Ort              : " << RN << endl;
		fi.close();
		fi.close();
	}
	void readWAA(int index) {
		char RN[20];
		ifstream fi(to_string(index) + ".txt");
		std::cout << "Index Nummer     : " << index << endl;
		fi.seekg(141);
		fi.get(RN, 20);
		std::cout << "typ              : " << RN << endl;
		fi.seekg(181);
		fi.get(RN, 20);
		std::cout << "Strasse          : " << RN << endl;
		fi.seekg(221);
		fi.get(RN, 20);
		std::cout << "Hausnummer       : " << RN << endl;
		fi.seekg(261);
		fi.get(RN, 20);
		std::cout << "Postleitzahl     : " << RN << endl;
		fi.seekg(301);
		fi.get(RN, 20);
		std::cout << "Ort              : " << RN << "\n" << endl;
		fi.close();
	}
	void readAAA(int index) {
		char RN[20];
		ifstream fi(to_string(index) + ".txt");
		std::cout << "Index Nummer     : " << index << endl;
		fi.seekg(341);
		fi.get(RN, 20);
		std::cout << "typ              : " << RN << endl;
		fi.seekg(381);
		fi.get(RN, 20);
		std::cout << "Strasse          : " << RN << endl;
		fi.seekg(421);
		fi.get(RN, 20);
		std::cout << "Hausnummer       : " << RN << endl;
		fi.seekg(461);
		fi.get(RN, 20);
		std::cout << "Postleitzahl     : " << RN << endl;
		fi.seekg(501);
		fi.get(RN, 20);
		std::cout << "Ort              : " << RN << endl;
		fi.close();
	}
	//writeFName schreibt Variable N über TXT file.
	void writeFName(char N[20], int index) {
		ofstream fo(to_string(index) + ".txt");//create a new one
		fo.close();
		fstream f(to_string(index) + ".txt");
		f.write("Name             : ", 20);
		f.seekp(20);
		f.write(N, strlen(N));
		string s = "";
		for (int i = 0; i < 20 - strlen(N); i++) s.append(" ");
		auto TempBuffer = s.c_str();
		f.write(TempBuffer, strlen(TempBuffer));
		//f.seekp(SEEK_SET());
		f.seekp(40);
		f << endl;
		//f.write("\n",1);
		f.close();
	}

	void writeFVorame(char V[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(41);
		f.write("Vorname          : ", 20);
		f.write(V, strlen(V));
		string s2 = "";
		for (int i = 0; i < 20 - strlen(V); i++) { s2.append(" "); }
		auto TempBuffer2 = s2.c_str();
		f.write(TempBuffer2, strlen(TempBuffer2));
		//f.seekp(SEEK_SET());
		f.seekp(80);
		f << endl;
		//f.write("\n",1);
		f.close();
	}
	void writeFGeburtstag(char G[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(81);
		f.write("Geburtsdatum     : ", 20);
		f.write(G, strlen(G));
		string s3 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s3.append(" "); }
		auto TempBuffer3 = s3.c_str();
		f.write(TempBuffer3, strlen(TempBuffer3));
		f.seekp(117);
		f << endl;
		f << endl;
		f.close();
	}

	void writeFWTyp(int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(121);
		f.write("Adresse Typ      : ", 20);
		f.write("Wohnort          ", 18);
		f.seekp(159);
		f << endl;
		f.close();
	}

	void writeFWStrasse(char S[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(161);
		f.write("Strasse          : ", 20);
		f.write(S, strlen(S));
		string s4 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s4.append(" "); }
		auto TempBuffer4 = s4.c_str();
		f.write(TempBuffer4, strlen(TempBuffer4));
		f.seekp(200);

		f << endl;
		f.close();
	}
	void writeFWHausnummer(char H[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(201);
		f.write("Hausnummer       : ", 20);
		f.write(H, strlen(H));
		string s5 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s5.append(" "); }
		auto TempBuffer5 = s5.c_str();
		f.write(TempBuffer5, strlen(TempBuffer5));
		f.seekp(240);
		f << endl;
		f.close();
	}
	void writeFWPlz(char P[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(241);
		f.write("Postleitzahl     : ", 20);
		f.write(P, strlen(P));
		string s6 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s6.append(" "); }
		auto TempBuffer6 = s6.c_str();
		f.write(TempBuffer6, strlen(TempBuffer6));
		f.seekp(280);
		f << endl;
		f.close();
	}
	void writeFWOrt(char O[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(281);
		f.write("Ort              : ", 20);
		f.write(O, strlen(O));
		string s7 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s7.append(" "); }
		auto TempBuffer7 = s7.c_str();
		f.write(TempBuffer7, strlen(TempBuffer7));
		f.seekp(317);
		f << endl;
		f << endl;
		f.close();
	}

	void writeFATyp(int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(321);
		f.write("Adrasse Typ      : ", 20);
		f.write("Arbeitplatz        ", 20);
		f.seekp(360);
		f << endl;
		f.close();
	}

	void writeFAStrasse(char S[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(361);
		f.write("Strasse          : ", 20);
		f.write(S, strlen(S));
		string s8 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s8.append(" "); }
		auto TempBuffer8 = s8.c_str();
		f.write(TempBuffer8, strlen(TempBuffer8));
		f.seekp(400);
		f << endl;
		f.close();
	}
	void writeFAHausnummer(char H[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(401);
		f.write("Hausnummer       : ", 20);
		f.write(H, strlen(H));
		string s9 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s9.append(" "); }
		auto TempBuffer9 = s9.c_str();
		f.write(TempBuffer9, strlen(TempBuffer9));
		f.seekp(440);
		f << endl;
		f.close();
	}
	void writeFAPlz(char P[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(441);
		f.write("Postleitzahl     : ", 20);
		f.write(P, strlen(P));
		string s10 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s10.append(" "); }
		auto TempBuffer10 = s10.c_str();
		f.write(TempBuffer10, strlen(TempBuffer10));
		f.seekp(480);
		f << endl;
		f.close();
	}
	void writeFAOrt(char O[20], int index) {
		fstream f(to_string(index) + ".txt");
		f.seekp(481);
		f.write("Ort              : ", 20);
		f.write(O, strlen(O));
		string s11 = "";
		for (int i = 0; i < 20 - strlen(G); i++) { s11.append(" "); }
		auto TempBuffer11 = s11.c_str();
		f.write(TempBuffer11, strlen(TempBuffer11));
		f.seekp(520);

		f << endl;
		f.close();
	}

	void printIndex() {
		for (int i = 0; i < 10; i++) {
			cout << "Number : " << index[i] << ". Name :" << PA[i].name << endl;
		}
	}

	void getPA(int index) {
		std::cout << "Index number " << index << "'s persoenliche Anlagen" << endl;
		std::cout << "Name :";
		std::cin >> N;
		strcpy_s(PA[index].name, N);
		//makeFile(index);
		writeFName(N, index);
		std::cout << endl;
		std::cout << "Vorname      : ";
		std::cin >> V;
		strcpy_s(PA[index].vorname, V);
		writeFVorame(V, index);
		std::cout << endl;
		std::cout << "Geburtsdatum : ";
		std::cin >> G;
		strcpy_s(PA[index].geburtsdatum, G);
		writeFGeburtstag(G, index);
		std::cout << endl;
	}
	void getWAA(int index) {

		std::cout << "Index number " << index << "'s Wohnort Adress Anlagen" << endl;
		writeFATyp(index);
		std::cout << "Strasse :";
		std::cin >> WS;
		strcpy_s(WAA[index].strasse, WS);
		writeFWStrasse(WS, index);
		std::cout << endl;
		std::cout << "Haus Nummer :";
		std::cin >> WH;
		strcpy_s(WAA[index].hausnummer, WH);
		writeFWHausnummer(WH, index);
		std::cout << endl;
		std::cout << "Postleitzahl :";
		std::cin >> WP;
		strcpy_s(WAA[index].plz, WP);
		writeFWPlz(WP, index);
		std::cout << endl;
		std::cout << "Ort :";
		std::cin >> WO;
		strcpy_s(WAA[index].ort, WO);
		writeFWOrt(WO, index);
		std::cout << endl;

	}
	void getAAA(int index) {

		std::cout << "Index number " << index << "'s Arbeitplatz Adress Anlagen" << endl;
		writeFWTyp(index);
		std::cout << "Strasse :";
		std::cin >> AS;
		strcpy_s(AAA[index].strasse, AS);
		writeFAStrasse(AS, index);
		std::cout << endl;
		std::cout << "Haus Nummer :";
		std::cin >> AH;
		strcpy_s(AAA[index].hausnummer, AH);
		writeFAHausnummer(AH, index);
		std::cout << endl;
		std::cout << "Postleitzahl :";
		std::cin >> AP;
		strcpy_s(AAA[index].plz, AP);
		writeFAPlz(AP, index);
		std::cout << endl;
		std::cout << "Ort :";
		std::cin >> AO;
		strcpy_s(AAA[index].ort, AO);
		writeFAOrt(AO, index);
		std::cout << endl;
	}
};

int main()
{
	C c;
	int switch1 = 0;
	int switch2 = 0;
	int switch3 = 0;
	int whileI = 1;
	int i = 0;
	char buff[10];


	while (whileI == 1) {

		std::cout << "<Person Data Anlagen>" << endl;
		std::cout << endl;
		c.printIndex();
		std::cout << "Welche Index nummer moechten Sie zugreifen? Bitte geben Sie eine Nummer ein. :" << endl;
		std::cin >> i;

		c.printAll(c.index[i]);


		std::cout << "Welche Funktionen moechten Sie nutzen?" << endl;
		std::cout << "1. Sehen Datei   2.Speichern Datei   3.ende" << endl;
		std::cin >> switch1;

		switch (switch1) {
			//1.Sehen Datei 
		case 1: {
			std::cout << "Welche Datei moechten Sie lesen?" << endl;
			std::cout << "1.Allem Datei   2.Personal Data   3.Wohnort Adresse   4.Arbeitplatz Adresse" << endl;
			std::cin >> switch2;
			switch (switch2) {
			case 1:
				c.readAll(c.index[i]);
				break;

			case 2:
				c.readPA(c.index[i]);
				break;

			case 3:
				c.readWAA(c.index[i]);
				break;

			case 4:
				c.readAAA(c.index[i]);
				break;



			}
			break;




		}

				//2.Speichern Datei
		case 2: {
			std::cout << "Welche Datei moechten Sie speichern?" << endl;
			std::cout << "1.Allem Datei   2.Personal Data   3.Wohnort Adresse   4.Arbeitplatz Adresse" << endl;
			std::cin >> switch3;
			switch (switch3) {

			case 1:
				c.getPA(c.index[i]);
				c.getWAA(c.index[i]);
				c.getAAA(c.index[i]);
				break;

			case 2:
				c.getPA(c.index[i]);
				break;

			case 3:
				c.getWAA(c.index[i]);
				break;

			case 4:
				c.getAAA(c.index[i]);
				break;

			}
		}break;
		}
		std::cout << "Wollen Sie fortfahren? (1.fortfahren 2.ende)";
		std::cin >> whileI;
	}
	return 0;
}
