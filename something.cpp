#include "something.h"
    

void GenerateWindow()
{
	/*generowanie okna*/
	HANDLE handlee = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hwnd = GetConsoleWindow();
	//ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	COORD c2 = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
	CONSOLE_FONT_INFOEX cfi;

	/*czcionka*/
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;    
	cfi.dwFontSize.Y = 12;// Width of each character in the font
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	/*Ustalenie rozmiaru okna*/
	for (short i = 0; i < 12; i++)
	{
		cfi.dwFontSize.Y = 24-i;
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		c2 = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
		if (c2.X >= 174 && c2.Y >= 43)
			break;
	}
 
	c2.X = 174;
	c2.Y = 42;
	
	SetConsoleScreenBufferSize(handlee, c2);
	
	SMALL_RECT sr;
	sr.Left = 0;
	sr.Top = 0;
	sr.Right = c2.X - 1;
	sr.Bottom = c2.Y - 1;
	SetConsoleWindowInfo(handlee, true, &sr);

	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(handlee, &cur);
	cur.bVisible = false;
	SetConsoleCursorInfo(handlee, &cur);

	//------
	setlocale(LC_CTYPE, "Polish");	//<- polskie literki
}

 
/*Rysuje Menu wyboru*/
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

		key = GetKey();

		if (key == 304)
			pos++;
		if (key == 296)
			pos--;

		if (pos < 0)
			pos = 0;
		if (pos > option.size() - 1)
			pos = option.size() - 1;

	} while (key != 13);
	SetConsoleTextAttribute(handlee, 0x0003);

	return pos;
}
/*Rysuje Menu wyboru */
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

		key = GetKey();
		
		if (key == 304)
			pos++;
		if (key == 296)
			pos--;
		
		if (pos < 0)
			pos = 0;
		if (pos > option.size() - 1)
			pos = option.size() - 1;

	} while (key != 13);
	SetConsoleTextAttribute(handlee, 0x0003);

	return pos;
}

int DrawMenu(vector<string>& option, COORD c, vector<string>& additionalText)
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

		for (int i = 0; i < option.size(); i++)
		{
			SetConsoleCursorPosition(handlee, { c.X, short(c.Y + i) });

			SetConsoleTextAttribute(handlee, 0x0003);
			if (i == pos)
			{
				SetConsoleTextAttribute(handlee, FOREGROUND_RED);
				cout << option[i];
			}
			else
			{
				SetConsoleTextAttribute(handlee, FOREGROUND_BLUE);
				cout << option[i];
			}

		}

		key = GetKey();

		if (key == 304)
			pos++;
		if (key == 296)
			pos--;

		if (pos < 0)
			pos = 0;
		if (pos > option.size() - 1)
			pos = option.size() - 1;

	} while (key != 13);
	SetConsoleTextAttribute(handlee, 0x0003);

	return pos;
}

void CDrawText(string s, COORD c, short textAtribute)
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

void CDrawText(wstring s, COORD c, short textAtribute)
{
	HANDLE handlee = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(handlee, &info);
	short buf = info.wAttributes;
	_setmode(_fileno(stdout), _O_U16TEXT);

	SetConsoleCursorPosition(handlee, c);
	SetConsoleTextAttribute(handlee, textAtribute);
	wcout << s;
	SetConsoleTextAttribute(handlee, buf);
	_setmode(_fileno(stdout), _O_TEXT);
}

/*Jakaś obramówka*/
void DrawBorder()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &bufInfo);
	COORD wSize = bufInfo.dwSize;
	
	DrawOnlyBorder();

	_setmode(_fileno(stdout), _O_U16TEXT);

	for (short i = 0; i < wSize.Y; i++)
	{
		SetConsoleCursorPosition(handle, { 106, i });
		wcout << L"\u2503";
	}

	SetConsoleCursorPosition(handle, { 106, 0 });
	wcout << L"\u2533";
	SetConsoleCursorPosition(handle, { 106, wSize.Y - 1 });
	wcout << L"\u253b";
	_setmode(_fileno(stdout), _O_TEXT);

}

void DrawOnlyBorder()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &bufInfo);
	COORD wSize = bufInfo.dwSize;

	_setmode(_fileno(stdout), _O_U16TEXT);

	SetConsoleCursorPosition(handle, { 0,0 });
	for (short i = 0; i < wSize.X - 1; i++)
	{
		wcout << L"\u2501";
	}

	SetConsoleCursorPosition(handle, { 0, wSize.Y - 1 });

	for (short i = 0; i < wSize.X - 1; i++)
	{
		wcout << L"\u2501";
	}
	SetConsoleCursorPosition(handle, { 0, 0 });

	for (short i = 0; i < wSize.Y - 1; i++)
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
	SetConsoleCursorPosition(handle, { wSize.X - 1,0 });
	wcout << L"\u2513";
	SetConsoleCursorPosition(handle, { wSize.X - 1,wSize.Y - 1 });
	wcout << L"\u251b";

	_setmode(_fileno(stdout), _O_TEXT);
}

void ClearPlace(COORD pos, COORD size)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short i = 0; i < size.Y; i++)
	{
		for (short j = 0; j < size.X; j++)
		{
			SetConsoleCursorPosition(handle, { pos.X + j,pos.Y + i });
			cout << " ";
		}
	}
}

void ClearMapPlace()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &bufInfo);
	COORD wSize = bufInfo.dwSize;

	for (short i = 0; i < wSize.Y - 2; i++)
	{
		SetConsoleCursorPosition(handle, { 1, i + 1 });
		for  (short i= 0; i < 105; i++)
		{
			cout << " ";
		}
	}
 }

void ClearInfoPlace()
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &bufInfo);
	COORD wSize = bufInfo.dwSize;

	for (short i = 0; i < wSize.Y - 2; i++)
	{
		SetConsoleCursorPosition(handle, { 107, i + 1 });
		for (short i = 0; i < wSize.X-108; i++)
		{
			cout << " ";
		}
	}
}

void X(short n, ...)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	va_list arg;
	va_start(arg, n);
	
	string *text = new string[n];
	short lenghtT = 0;
	short x = 52, y = 29;

	for (short i = 0; i < n; i++)
	{
		text[i] = va_arg(arg, char*);
		lenghtT > text[i].length() ? lenghtT : lenghtT = text[i].length();
	}
	lenghtT;
	ClearPlace({ x - lenghtT / 2,y - n }, { lenghtT, n });
	for (short i = 0; i < n; i++)
	{
		SetConsoleCursorPosition(handle, { x - lenghtT / 2 , y - n + i });
		cout << text[i];
	}
	
	//Rysowanie ramki
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleCursorPosition(handle, { x - lenghtT / 2 , y - n -1});
	for (short i = 0; i < lenghtT; i++)
	{
		wcout << L"\u2550";
	}
	SetConsoleCursorPosition(handle, { x - lenghtT / 2 , y });
	for (short i = 0; i < lenghtT; i++)
	{
		wcout << L"\u2550";
	}
	for (short i = 0; i < n; i++)
	{
		SetConsoleCursorPosition(handle, { x - lenghtT / 2 -1 , y - n + i });
		wcout << L"\u2551";
		SetConsoleCursorPosition(handle, { x + lenghtT / 2 + 1 , y - n + i });
		wcout << L"\u2551";
	}

	SetConsoleCursorPosition(handle, { x - lenghtT / 2 - 1, y - n - 1});
	wcout << L"\u2554";
	SetConsoleCursorPosition(handle, { x + lenghtT / 2 + 1, y - n - 1});
	wcout << L"\u2557";
	SetConsoleCursorPosition(handle, { x - lenghtT / 2 - 1, y });
	wcout << L"\u255a";
	SetConsoleCursorPosition(handle, { x + lenghtT / 2 + 1, y });
	wcout << L"\u255d";
	_setmode(_fileno(stdout), _O_TEXT);

	GetKey();
	//sprzatanie
	ClearPlace({ x - lenghtT / 2 -1,y - n-1 }, { lenghtT+3, n+2 });
	//delete text;
	va_end(arg);
}

void X(short n, short textAtribute, ...)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	short buf = info.wAttributes;

	SetConsoleTextAttribute(handle, textAtribute);
	va_list arg;
	va_start(arg, textAtribute);

	bool wait = true;
	if (n < 0)
	{
		wait = !wait;
		n *= -1;
	}

	string* text = new string[n];
	short lenghtT = 0;
	short x = 52, y = 29;
	
	for (short i = 0; i < n; i++)
	{
		text[i] = va_arg(arg, char*);
		lenghtT > text[i].length() ? lenghtT : lenghtT = text[i].length();
	}
	lenghtT;
	ClearPlace({ x - lenghtT / 2,y - n }, { lenghtT, n });
	for (short i = 0; i < n; i++)
	{
		SetConsoleCursorPosition(handle, { x - lenghtT / 2 , y - n + i });
		cout << text[i];
	}

	//Rysowanie ramki
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleCursorPosition(handle, { x - lenghtT / 2 , y - n - 1 });
	for (short i = 0; i < lenghtT; i++)
	{
		wcout << L"\u2550";
	}
	SetConsoleCursorPosition(handle, { x - lenghtT / 2 , y });
	for (short i = 0; i < lenghtT; i++)
	{
		wcout << L"\u2550";
	}
	for (short i = 0; i < n; i++)
	{
		SetConsoleCursorPosition(handle, { x - lenghtT / 2 - 1 , y - n + i });
		wcout << L"\u2551";
		SetConsoleCursorPosition(handle, { x + lenghtT / 2 + 1 , y - n + i });
		wcout << L"\u2551";
	}

	SetConsoleCursorPosition(handle, { x - lenghtT / 2 - 1, y - n - 1 });
	wcout << L"\u2554";
	SetConsoleCursorPosition(handle, { x + lenghtT / 2 + 1, y - n - 1 });
	wcout << L"\u2557";
	SetConsoleCursorPosition(handle, { x - lenghtT / 2 - 1, y });
	wcout << L"\u255a";
	SetConsoleCursorPosition(handle, { x + lenghtT / 2 + 1, y });
	wcout << L"\u255d";
	_setmode(_fileno(stdout), _O_TEXT);

	if (wait)
	{
		GetKey();
		ClearPlace({ x - lenghtT / 2 - 1,y - n - 1 }, { lenghtT + 3, n + 2 });
	}
	//sprzatanie
	SetConsoleTextAttribute(handle, buf);
	va_end(arg);
}

int GetKey()
{
	int a = 0;
	a = _getch();
	if (_kbhit())
		a += _getch();
	return a;
}

/*-----------------------------*/
/*Ładowanie i zapisywanie plikó*/
/*-----------------------------*/
 