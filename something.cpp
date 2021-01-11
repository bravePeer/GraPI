#include "something.h"
#include <io.h>
#include <fcntl.h>

void GenerateWindow()
{
	HANDLE handlee = GetStdHandle(STD_OUTPUT_HANDLE);
	/*generowanie okna*/
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_SHOWMAXIMIZED);

	COORD c2 = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
	SetConsoleScreenBufferSize(handlee, c2);
	
	SMALL_RECT sr;
	sr.Left = 0;
	sr.Top = 0;
	sr.Right = c2.X - 1;
	sr.Bottom = c2.Y - 1;
	SetConsoleWindowInfo(handlee, true, &sr);
	//------
	setlocale(LC_CTYPE, "Polish");	//<- polskie litraki

}

int DrawMenu(vector<string>& option)
{
	int pos = 0;
	int key = 0;
	HANDLE handlee = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		system("cls");

		for (int i = 0; i < option.size(); i++)
		{
			SetConsoleTextAttribute(handlee, 0x0003);
			if (i == pos)
			{
				SetConsoleTextAttribute(handlee, FOREGROUND_RED);
				cout << option[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(handlee, FOREGROUND_BLUE);
				cout << option[i] << endl;
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
		if (pos > option.size() - 1)
			pos = option.size() - 1;

	} while (key != 13);
	SetConsoleTextAttribute(handlee, 0x0003);

	return pos;
}

int DrawMenu(vector<string>& option, COORD c)
{
	int pos = 0;
	int key = 0;
	HANDLE handlee = GetStdHandle(STD_OUTPUT_HANDLE);

	int lenght = option[0].length();

	for (int i = 1; i < option.size(); i++)
	{
		if (option[i].length() > lenght)
			lenght = option[i].length();
	}

	do
	{
		//lepsze czyszczenie bo czysci tylko fragment nie calosc
		for (int i = 0; i < option.size(); i++)
		{
			SetConsoleCursorPosition(handlee, { c.X, short(c.Y + i) });
			for (int j = 0; j < lenght; j++)
			{
				cout << " ";
			}
			cout << endl;
		}
		
		//system("cls");

		for (int i = 0; i < option.size(); i++)
		{
			SetConsoleCursorPosition(handlee, {c.X, short(c.Y + i)});

			SetConsoleTextAttribute(handlee, 0x0003);
			if (i == pos)
			{
				SetConsoleTextAttribute(handlee, FOREGROUND_RED);
				cout << option[i];
			}
			else
			{
				SetConsoleTextAttribute(handlee, FOREGROUND_BLUE);
				cout << option[i] ;
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
		if (pos > option.size() - 1)
			pos = option.size() - 1;

	} while (key != 13);
	SetConsoleTextAttribute(handlee, 0x0003);

	return pos;
}

void CDrawText(string s, COORD c,short textAtribute)
{
	HANDLE handlee = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	
	GetConsoleScreenBufferInfo(handlee, &info);
	short buf = info.wAttributes;

	SetConsoleCursorPosition(handlee, c);
	SetConsoleTextAttribute(handlee, textAtribute);
	cout << s;
	SetConsoleTextAttribute(handlee,buf);
}

void Font()
{
     CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 30;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    //SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
/*Jakaś obramówka*/
void DrawBorder()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &bufInfo);
	COORD wSize = bufInfo.dwSize;
	
	_setmode(_fileno(stdout), _O_U16TEXT);

	SetConsoleCursorPosition(handle, {0,0});
	for (short i = 0; i < wSize.X - 1; i++)
	{
		wcout << L"\u2501";
	}

	SetConsoleCursorPosition(handle, { 0, wSize.Y-1 });

	for (short i = 0; i < wSize.X - 1; i++)
	{
		wcout << L"\u2501";
	}
	SetConsoleCursorPosition(handle, { 0, 0 });

	for (short i = 0; i < wSize.Y-1; i++)
	{
		wcout << L"\u2503" << endl;
	}

	for (short i = 0; i < wSize.Y - 1; i++)
	{
		SetConsoleCursorPosition(handle, { wSize.X - 1, i });
		wcout << L"\u2503";
	}

	SetConsoleCursorPosition(handle, { 0,0 });
	wcout << L"\u250f";
	SetConsoleCursorPosition(handle, { 0,wSize.Y - 1 });
	wcout << L"\u2517";
	SetConsoleCursorPosition(handle, { wSize.X-1,0 });
	wcout << L"\u2513";
	SetConsoleCursorPosition(handle, { wSize.X - 1,wSize.Y-1 });
	wcout << L"\u251b";

	_setmode(_fileno(stdout), _O_TEXT);
}