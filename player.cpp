#include "player.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::Select_profession()
{
	CDrawText("Wybierz klas�:", { WHEREINFO + (WIDTHCONSOLE - WHEREINFO- 15)/2  ,8 }, 0x000b);
	vector<string> s;
	s.push_back("Wojownik");
	s.push_back("  Mag");
	s.push_back(" �owca");

	switch (DrawMenu(s, { WHEREINFO + (WIDTHCONSOLE - WHEREINFO - 8) / 2 ,10}))
	{
	case 0:
		profession = 1;
		profession_name = "Wojownik";
		break;
	case 1:
		profession = 2;
		profession_name = "Mag";
		break;
	case 2:
		profession = 3;
		profession_name = "�owca";
		break;
	}
}

void Player::CreateCharacter()
{
	DrawOnlyBorder();
	DrawMenuCharacters();
	vector<string> s;
	s.push_back(" Kobieta ");
	s.push_back("M�czyzna");
	//system("cls");
	//cout << "Podaj imi�" << endl;

	CDrawText("Podaj imi�:", { (WIDTHCONSOLE-12)/2,5 }, 0x0003);
	//cin >> name;
	char a = 'a';
	do
	{
		a = _getch();
		if (a == 8)
		{
			if (name.size() > 0)
				name.erase(name.size() - 1);
		}
		else
		{
			if (name.size() <= 20)
				name += a;
			else
				X(1, 0x000c, "Nazwa nie moze przekraczac 20 znak�w.");
		}
		CDrawText("                      ", { (short)(WIDTHCONSOLE - 21) / 2,7 }, 0x000a);
		CDrawText(name, { (short)(WIDTHCONSOLE - name.size()) / 2,7 }, 0x000a);
	}while (a != 13);

	//system("cls");
	CDrawText("           ", { (WIDTHCONSOLE - 12) / 2,5 }, 0x0003);
	CDrawText("                        ", { (WIDTHCONSOLE - 24) / 2,7 }, 0x0003);

	CDrawText("Wybierz p�e�", { (WIDTHCONSOLE - 12)/2,5 }, 0x0003);
	switch (DrawMenu(s, { (WIDTHCONSOLE - 9)/2,7 }))
	{
		case 0:
			system("cls");
			sex = 2;
			ShowGfx_Hero(-2, {0,0});
			break;
		case 1:
			system("cls");
			sex = 1;
			ShowGfx_Hero(-1, {0,0});
			break;
	}

	DrawOnlyBorder();
	Select_profession();

	system("cls");

	//ClearInfoPlace();
	DrawBorder();
	ShowGfx_Hero(sex * 10 + (short)profession, {(WHEREINFO - 40)/2,2});

	//char pom;
	s.clear();
	s.push_back("Si�a");	
	s.push_back("Inteligencja");
	s.push_back("Zr�czno��");	
	s.push_back("Celno��");	
	s.push_back("Uniki");
	s.push_back("Uderzenia krytyczne");


	vector<string> ad;
	ad.push_back("Si�a - Wp�ywa na obra�enia zadawne wrogom.\nDobre dla wojownika.");
	ad.push_back("Inteligencja - (Wp�ywa na obra�enia zadawne wrogom.\nDobre dla maga");
	ad.push_back("Zr�czno�� - (Wp�ywa na obra�enia zadawne wrogom.\nDobre dla �owcy");
	ad.push_back("Celno�� - (Zwi�ksza szanse na trafienie)");
	ad.push_back("Uniki - (Wp�ywa na cz�sto�� unikania cios�w)");
	ad.push_back("Uderzenia krytyczne -(Zwi�ksza szanse na silniejszy cios)");

	/*CDrawText("Si�a - (", { 124,17+5}, 0x0004);
	CDrawText("Dobre dla wojownika)", { 124,18 + 5 }, 0x0004);
	CDrawText("Zr�czno�� - (Wp�ywa na obra�enia zadawne wrogom.", { 124,19 + 5 }, 0x0004);
	CDrawText("Dobre dla �owcy)", { 124,20+5}, 0x0004);
	CDrawText("Inteligencja - (Wp�ywa na obra�enia zadawne wrogom.", { 124,21 + 5 }, 0x0004);
	CDrawText("Dobre dla maga)", { 124,22 + 5 }, 0x0004);
	CDrawText("Celno�� - (Zwi�ksza szanse na trafienie)", {124,23 + 5 }, 0x0004);
	CDrawText("Uniki - (Wp�ywa na cz�sto�� unikania cios�w)", { 124,24 + 5 }, 0x0004);
	CDrawText("Uderzenia krytyczne -", { 124,25 + 5 }, 0x0004);
	CDrawText("(Zwi�ksza szanse na silniejszy cios))", { 124,26 + 5 }, 0x0004);*/

	for (int i = 15; i > 0; i--)
	{
		ShowStats();
		CDrawText("Przydziel punkty umiej�tno�ci", { WHEREINFO,12 }, 0x0002);
		CDrawText("Pozosta�e punkty: "+to_string(i)+" do rozdania.", { WHEREINFO,20 }, 0x0002);
		switch (DrawMenu(s, { WHEREINFO,13 }, ad, { WHEREINFO, 23 },0x0004))
		{
		case 0:
			strength++;
			break;
		
		case 1:
			inteligence++;
			break;
		
		case 2:
			agility++;
			break;
		
		case 3:
			accuracy++;
			break;
		
		case  4:
			dodging++;
			break;
		
		case  5:
			crit_strike++;
			break;

		default:
			i++;
			break;
		}
		
	}
	ClearInfoPlace();
}

void Player::Bonus_stats_per_lvl()
{
	
	//cout << "Wbi�e� nast�pny poziom! Mo�esz doda� 2 punkty umiej�tno�ci." << endl;
	ClearInfoPlace();
	//X(1, 0x0002, "Wbi�e� nast�pny poziom! Mo�esz doda� 2 punkty umiej�tno�ci.");
	CDrawText("Wbi�e� nast�pny poziom! Mo�esz doda� 2 punkty umiej�tno�ci.", { 107,13 }, 0x0002);
	GetKey();
	DrawBorder();
	//ClearMapPlace();

	vector<string> s;
	s.push_back("Si�a");
	s.push_back("Inteligencja");
	s.push_back("Zr�czno��");
	s.push_back("Celno��");
	s.push_back("Uniki");
	s.push_back("Uderzenia krytyczne");

	for (int i = 2; i > 0; i--)
	{
		ShowStats();
		CDrawText("Pozosta�e punkty: "+to_string(i)+" do rozdania.", { 107,15 }, 0x0002);

		switch (DrawMenu(s, { 107,17 }))
		{
		case 0:
			strength++;
			break;
		
		case 1:
			inteligence++;
			break;
		
		case 2:
			agility++;
			break;
		
		case 3:
			accuracy++;
			break;
		
		case  4:
			dodging++;
			break;
		
		case  5:
			crit_strike++;
			break;

		default:
			i++;
			break;
		}
	}
	//ClearInfoPlace();
	lifeMax *= 1.2;
	life = lifeMax;
	ClearEqPlace();
	ShowStats();
	DrawBorder();
}

void Player::UsePreset()
{
	name = "Alicja Zalewska";
	sex = 'k';
	lifeMax = 100;
	life = lifeMax;
	profession = 2;
	money = 1000;
	
	accuracy = 2;
	strength = 7;
	inteligence = 6;
	agility = 3;
	dodging = 4;
	//xp= 101;
}

void Player::ShowInventory()
{
	int buf = -1;
	Food *food = NULL;
	Weapon* weapon = NULL;
	Armor* armor = NULL;

	vector<string> s;
	vector<string> ad;

	if (inventory.size() > 0)
	{
		while (1)
		{
			ClearEqPlace();
			CDrawText("Ekwipunek", { WHEREINFO, 12 }, 0x000a);
			ShowStats();
			s.clear();
			ad.clear();
			for (int i = 0; i < inventory.size(); i++)
			{
				s.push_back(inventory[i]->name);
				ad.push_back(inventory[i]->desc);
			}
			s.push_back("Powrot");
			ad.push_back(" ");

			buf = DrawMenu(s, { WHEREINFO,14 }, ad, { WHEREINFO,38 }, 0x000c);
			if (buf == inventory.size())
				return;
		switch (inventory[buf]->UseItem())
		{
		case 1://zjedz
			food = (Food*)inventory[buf];
			if (life + food->healthModifier < lifeMax)
				life += food->healthModifier;
			else
				life = lifeMax;
			inventory.erase(inventory.begin() + buf);

			break;
		case 2://zaloz bron
			if (equipedWeapon != NULL)
			{
				weapon = (Weapon*)inventory[buf];
				inventory[buf] = (Item*)equipedWeapon;
				equipedWeapon = weapon;
			}
			else
			{
				equipedWeapon = (Weapon*)inventory[buf];
				inventory.erase(inventory.begin() + buf);
			}
			break;
		case 3://ubierz ubranko xd
			if (equipedArmor != NULL)
			{
				armor = (Armor*)inventory[buf];
				inventory[buf] = equipedArmor;
				equipedArmor = armor;
			}
			else
			{
				equipedArmor = (Armor*)inventory[buf];
				inventory.erase(inventory.begin() + buf);
			}
			break;
		}
		}
		 
	}
	else
	{
		CDrawText("Tw�k plecak jest pusty!", { 107, 4 }, 0x000c);
		_getch();
	}
	delete food;
}

void Player::ShowStandardStats()	//do testowania bylo usunac
{
	
}

void Player::ShowStats()	
{
	CDrawText(name, { WHEREINFO  , 1 }, 0x0003);

	if (sex == 1)
		CDrawText(L"\u2642", { (short)name.length() + WHEREINFO + 1, 1 }, 0x0003);
	else
		CDrawText(L"\u2640", { (short)name.length() + WHEREINFO + 1, 1 }, 0x0003);

	CDrawText("Poziom: " + to_string(level), { WIDTHCONSOLE - 22, 1 }, 0x0003);
	CDrawText("PD:           " + to_string(xp), { WIDTHCONSOLE - 22,3 }, 0x0003);
	CDrawText("�ycie:        " + to_string(life) + '/' + to_string(lifeMax), { WIDTHCONSOLE - 22,4 }, 0x0003);
	CDrawText("Si�a:         " + to_string(strength), { WIDTHCONSOLE - 22,5 }, 0x0003);
	CDrawText("Inteligencja: " + to_string(inteligence), { WIDTHCONSOLE - 22,6 }, 0x0003);
	CDrawText("Celno��:      " + to_string(accuracy), { WIDTHCONSOLE - 22,7 }, 0x0003);
	CDrawText("Zr�czno��:    " + to_string(agility), { WIDTHCONSOLE - 22,8 }, 0x0003);
	CDrawText("Uniki:        " + to_string(dodging), { WIDTHCONSOLE - 22,9 }, 0x0003);
	CDrawText("UK:           " + to_string(crit_strike), { WIDTHCONSOLE - 22,10 }, 0x0003);
	CDrawText("Posiadasz" + to_string(money) + "G", { WHEREINFO  ,  10 }, 0x0003);

	CDrawText(profession_name, { WHEREINFO,3 }, 0x0006);

	if (equipedWeapon != NULL)
	{
		CDrawText("Bro�: " + equipedWeapon->name  , { WHEREINFO, 5}, 0x0003);
		CDrawText( "Atak: " + to_string(equipedWeapon->strength), { WHEREINFO, 6 }, 0x0003);
	}
	else
		CDrawText("Brak broni", { WHEREINFO, 5 }, 0x0001);


	if (equipedArmor != NULL)
	{
		CDrawText("Pancerz: " + equipedArmor->name, { WHEREINFO, 7 }, 0x0003);
		CDrawText(  "Obrona: " + to_string(equipedArmor->armor), { WHEREINFO, 8 }, 0x0003);
	}
	else
		CDrawText("Brak pancerza", { WHEREINFO, 7 }, 0x0001);
}

void Player::AddItem(Item* item)
{

}

int Player::Spell(int atak_moba)
{
	if (profession == 1) // wojownik 
	{
		atak_moba =atak_moba* 0.5;
		return atak_moba;
	}

	if (profession == 2)  //mag - leczenie
	{
	
		int healing;
		healing = 30 + (level * 3);
		if (life == lifeMax)
		{
			return 0;
		}

		if (life < lifeMax)
		{
			if ((life + healing) > lifeMax)
			{
				life = lifeMax;
				//cout << "Zosta�e� uzdrowiony!" << endl;
				CDrawText("Zosta�e� uzdrowiony!", { 107,12 },0x009 );
			}

			if ((life + healing) <= lifeMax)
			{
				life = life + healing;
				//cout << "Zosta�e� uzdrowiony!" << endl;
				CDrawText("Zosta�e� uzdrowiony!", { 107,12 },0x009 );
			}
		}
		return 0;
	}

	if (profession == 3) // �owca - losowe obrazenia z danego zakresu, ro�nie z levelem
	{
		int pom;
		pom = (25 + (level * 2)) + rand() % ((50 + (level * 2)) - (25 + (level * 2)) + 1);
		return pom;
	}
}

int Player::Dmg_formula()
{
	if (profession == 1)
	{
		dmg_output = ( strength * 4)  + ( agility * 3) + ( inteligence ) + (level * 3);
		return dmg_output;
	}
	if (profession == 2)
	{
		dmg_output = ( inteligence * 4) + ( agility * 3) + ( strength ) + (level * 3);
		return dmg_output;
	}
	if (profession == 3)
	{
		dmg_output = ( agility * 4) + ( strength * 3) + ( inteligence ) + (level * 3);
		return dmg_output;
	}
}

void Player::ShowQuests()
{
	 
}

bool Player::CritIs()
{
	int help = 1 + rand() % (100-1+1);
	if((crit_strike*3)>help) return true;
	else return false;
}

bool Player::DodgeIs()
{
	int help = 1 + rand() % (100-1+1);
	if ((dodging * 3) > help) return true;
	else return false;
}

bool Player::AccIs()
{
	int help = 1 + rand() % (100 - 1 + 1);
	if (((accuracy * 2) + 80) > help) return true;
	else return false;
}

 