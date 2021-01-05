#include <iostream>
#include <windows.h>
#include <time.h>

#include "person.h"
#include "player.h"
#include "item.h"
using namespace std;

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);


int DrawMenu(vector<string>& option)
{
	int pos = 0;
	int key = 0;

	do
	{

		system("cls");
		cout << pos << endl;

		for (int i = 0; i < option.size(); i++)
		{
			SetConsoleTextAttribute(handle, 0x0003);
			if (i == pos)
			{
				SetConsoleTextAttribute(handle, FOREGROUND_RED);
				cout << i <<" "<<option[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
				cout << i<<" "<<option[i] << endl;
			}
			
		}

		key = _getch();

		if (key == 224)
		{
			key = _getch();
			if (key == 80)
				pos++;
			if (key == 72)
				pos--;
		}

		if (pos < 0)
			pos = 0;
		if (pos > option.size()-1)
			pos = option.size()-1;
		
	} while (key != 13);

	return pos;
}

int main()
{
	/*generowanie okna*/
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);

	COORD c2 = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
	SetConsoleScreenBufferSize(handle, c2);

	SMALL_RECT sr;
	sr.Left = 0;
	sr.Top = 0;
	sr.Right = c2.X - 1;
	sr.Bottom = c2.Y - 1;
	SetConsoleWindowInfo(handle, true, &sr);
	//------
	setlocale(LC_CTYPE, "Polish");	//<- polskie litraki

	Player pl;
	//pl.CreateCharacter();
	pl.UsePreset();
	pl.inventory.push_back(new Item("cos"));
	pl.inventory.push_back(new Item("ddd"));
	pl.inventory.push_back(new Item("cos"));
	pl.inventory.push_back(new Food("zycie", 10));
	//pl.ShowInventory();

	int a;

	/*while (1)
	{
		a = _getch();
		cout << (int)a << endl;
	}*/

	vector<string> s;
	s.push_back("1opcja");
	s.push_back("2opcja");
	s.push_back("3opcja");
	
	cout<<DrawMenu(s);
	return 0;
}