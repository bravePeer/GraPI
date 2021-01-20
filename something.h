#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <iomanip>   
#include <fstream>
#include <sstream>
#include "player.h"
#include "item.h"
#include "map.h"
/*szerokoœæ okna*/
#define WIDTHCONSOLE 174
/*gdzie zaczyna sie prawa strona*/
#define WHEREINFO 107

using namespace std;

void GenerateWindow();
int DrawMenu(vector<string>& option);
int DrawMenu(vector<string>& option, COORD c);
int DrawMenu(vector<string>& option, COORD c, vector<string>& additionalText, COORD c2, short adTextAttribute);

/*Wypisuje napis w odpowiednim miejscu i z atrybutem (0x1234)
1- nwm 2- chyba podkreslenie 3-tlo 4-tekst*/
void CDrawText(string s, COORD c, short textAtribute);
void CDrawText(wstring s, COORD c, short textAtribute);

/*Rysuje obramówke*/
void DrawBorder();
void DrawOnlyBorder();

void ClearPlace(COORD pos, COORD size);
void ClearMapPlace();
void ClearInfoPlace();
void ClearEqPlace();
/*wypisuje dialog*/
//void X(short n, ...);
/*n > liczba linijek, textAtt.. > kolor, tyle ile |n| tyle argumentow ""
gdy n < 0 to nie czeka na przycisk*/
void X(short n, short textAtribute, ...);

//ramki z tekstem dla klas postaci
void W(short n, short textAtribute, ...); 
void L(short n, short teztAtribute, ...);
void M(short n, short teztAtribute, ...);

int GetKey();