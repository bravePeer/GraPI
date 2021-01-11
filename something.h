#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>

using namespace std;

void GenerateWindow();
int DrawMenu(vector<string>& option);
int DrawMenu(vector<string>& option, COORD c);

/*Wypisuje napis w odpowiednim miejscu i z atrybutem (0x1234)
1- nwm 2- chyba podkreslenie 3-tlo 4-tekst*/
void CDrawText(string s, COORD c, short textAtribute);
void Font();
/*Rysuje obramówke*/
void DrawBorder();
void ShowGfx(int id);
void TakeGfx(int id);
