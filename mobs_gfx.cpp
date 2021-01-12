#include "mobs_gfx.h"
#include <io.h>
#include <fcntl.h>


void ShowGfx_Mobs(int id)
{
	TakeGfx_Mobs(id);
}

void TakeGfx_Mobs(int id)
{










	wstring mob_gfx[30];

	switch (id)
	{
	case 999:
		mob_gfx[0] = L"          ▒░        ";
		mob_gfx[1] = L"         ███░       ";
		mob_gfx[2] = L"       ▒██▓░▓       ";
		mob_gfx[3] = L"▒█▒   ▒▓█░  ▒░    ░░";
		mob_gfx[4] = L" ▒██░██▒█    ██░ ███";
		mob_gfx[5] = L"   ███▒ ██   ▒▓██▓░ ";
		mob_gfx[6] = L"      ▓███▓▒█       ";
		mob_gfx[7] = L"      ▓░ ████  ░    ";
		mob_gfx[8] = L"     ▓█▒░   ██▓▓    ";
		mob_gfx[9] = L"    ▒█▒     ██▓     ";
		break;
	case 998:
		mob_gfx[0] = L"                               ░░                           ";
		mob_gfx[1] = L"                             ▓████▓                         ";
		mob_gfx[2] = L"                           ░████▒░█▒                        ";
		mob_gfx[3] = L"                          ░████░  ░█                        ";
		mob_gfx[4] = L"                        ▒▓▓██▒ ▒██▒▓▓                       ";
		mob_gfx[5] = L"                    ░▓███▓███▓██▓▒██▓                       ";
		mob_gfx[6] = L"                   ░▓▓█████████▒   ▓▓                       ";
		mob_gfx[7] = L"░▒                    ▒███████░    ▒█▒                      ";
		mob_gfx[8] = L"▒█░▒█                 ▓█████░▓      ██▒░                    ";
		mob_gfx[9] = L"░███▓▓░░          ▓██████▒▒█        ▒█▒ ▒▒              ░   ";
		mob_gfx[10] = L" ▒███▓░██       ░███░ ▒█▓     ▓▒   ░▓░ ░░ █░        ▓  ██░░▓";
		mob_gfx[11] = L"  ░███▓▓█▒     ▒██▓   ▓███             ██  █      ░▓▓██████▒";
		mob_gfx[12] = L"    ▒████▓░  ███▓██▓██████░            ██  ▒▒     ▒████████▓";
		mob_gfx[13] = L"      ░██▒ ░██ ▒▓████▓ ▓████▒▒ ░    ▒█████▒░█▒▒░░░▒██████▓▒░";
		mob_gfx[14] = L"        ███▒  █████▒   ▓███████░    ███▒▓██████ ░ ░███▓     ";
		mob_gfx[15] = L"         ████▓███░     ██████         █░ ▒█████████▓        ";
		mob_gfx[16] = L"                ██▒░▒███████▒    ░  ░█░                     ";
		mob_gfx[17] = L"                 ██████████████ ░░▒████░                    ";
		mob_gfx[18] = L"                  ▓██████████████████▓░░▓░                  ";
		mob_gfx[19] = L"                   ███░  ▓███████████░   ▒▓▒                ";
		mob_gfx[20] = L"                  ██▓      ███████████     ▒█               ";
		mob_gfx[21] = L"                 ██▒     ░███████▓▓███▓      █▒             ";
		mob_gfx[22] = L"                ▓██▓░  ▓██▓▒  ▒█░  ░███▒     ██             ";
		mob_gfx[23] = L"               ▒██▒ ▓███▒         ░███████████░             ";
		mob_gfx[24] = L"               ███████░           ▒█████████▓               ";
		mob_gfx[25] = L"              █████▒░               ▓█████▒                 ";
		mob_gfx[26] = L"             ████▓                  ░███▓                   ";
		mob_gfx[27] = L"           ▒██████▒                ▒████▓▓█▒░░              ";
		mob_gfx[28] = L"          ██ ▒▓ ▓░░               ███████░███▒█             ";
		mob_gfx[29] = L"";
		break;
	}



	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	_setmode(_fileno(stdout), _O_U16TEXT);

	for (short i = 0; i < 30; i++)
	{
		SetConsoleCursorPosition(handle, { 1,1 + i });
		wcout << mob_gfx[i];
	}

	_setmode(_fileno(stdout), _O_TEXT);

}