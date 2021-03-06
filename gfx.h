#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "something.h"

using namespace std;

void ShowGfx_NPC(int id, COORD c);
void TakeGfx_NPC(int id, wstring npc_gfx[]);

void ShowGfx_Mobs(int id );
void TakeGfx_Mobs(int id, wstring mob_gfx[], int& lenght);

void ShowGfx_Envi(int id, COORD c);
void TakeGfx_Envi(int id, wstring envi_gfx[], int& lenght);

void ShowGfx_Hero(int id, COORD c);
void TakeGfx_Hero(int id, wstring hero_gfx[]);

void ShowGfx_GameName();
void TakeGfx_GameName(wstring buf[]);
void DrawMenuCharacters();
