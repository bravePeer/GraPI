#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "map.h"

using namespace std;

void ShowGfx_NPC(int id);
void TakeGfx_NPC(int id);

void ShowGfx_Mobs(int id);
void TakeGfx_Mobs(int id);

void ShowGfx_MiniBoss(int id);
void TakeGfx_MiniBoss(int id);

void ShowGfx_Boss(int id);
void TakeGfx_Boss(int id);

void ShowGfx_Envi(int id);
void TakeGfx_Envi(int id);

void ShowGfx_Hero(int id);
void TakeGfx_Hero(int id, wstring hero_gfx[]);

void ShowGfx_GameName();
void TakeGfx_GameName(wstring buf[]);