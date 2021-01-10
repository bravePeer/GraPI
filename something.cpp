#include "something.h"


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
		//	cout << pos << endl;

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

	return pos;
}

int DrawMenu(vector<string>& option, COORD c)
{
	int pos = 0;
	int key = 0;
	HANDLE handlee = GetStdHandle(STD_OUTPUT_HANDLE);


	do
	{
		system("cls");
		//	cout << pos << endl;
	

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
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}