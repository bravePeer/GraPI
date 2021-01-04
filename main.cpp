#include <iostream>
#include <windows.h>
#include <time.h>

#include "person.h"
#include "player.h"
using namespace std;

int main()
{
	/*generowanie okna*/
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
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
	pl.CreateCharacter();

	cout << "hello¹¹¹¹³³³³" << endl;

	return 0;
}