#include "player.h"
#include "gfx.h"

Player::Player()
{
}

Player::~Player()
{
//	delete quest;
}

void Player::Select_profession()
{
	vector<string> s;
	s.push_back("Wojownik");
	s.push_back("Mag");
	s.push_back("£owca");

	switch (DrawMenu(s, {124,5}))
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
		profession_name = "£owca";
		break;
	}
}

void Player::CreateCharacter()
{
	//system("cls");
	//cout << "Podaj imiê" << endl;
	CDrawText("Podaj imiê ", { 124,1 }, 0x0003);
	cin >> name;

	do
	{
		//cout << "Podaj p³eæ(m/k)" << endl;
		CDrawText("Podaj p³eæ(m/k)", { 124,3 }, 0x0003);
		cin >> sex;
	} while ((sex != 'k') && (sex != 'm'));

	Select_profession();

	ClearInfoPlace();
	ShowGfx_Hero(-1);
	
	//char pom;
	vector<string> s;
	s.push_back("Si³a");	
	s.push_back("Zrêcznoœæ");	
	s.push_back("Inteligencja");	
	s.push_back("Celnoœæ");	
	s.push_back("Uniki");
	s.push_back("Uderzenia krytyczne");

	CDrawText("Si³a - (Wp³ywa na obra¿enia zadawne wrogom.", { 124,17+5}, 0x0004);
	CDrawText("Dobre dla wojownika)", { 124,18 + 5 }, 0x0004);
	CDrawText("Zrêcznoœæ - (Wp³ywa na obra¿enia zadawne wrogom.", { 124,19 + 5 }, 0x0004);
	CDrawText("Dobre dla ³owcy)", { 124,20+5}, 0x0004);
	CDrawText("Inteligencja - (Wp³ywa na obra¿enia zadawne wrogom.", { 124,21 + 5 }, 0x0004);
	CDrawText("Dobre dla maga)", { 124,22 + 5 }, 0x0004);
	CDrawText("Celnoœæ - (Zwiêksza szanse na trafienie)", {124,23 + 5 }, 0x0004);
	CDrawText("Uniki - (Wp³ywa na czêstoœæ unikania ciosów)", { 124,24 + 5 }, 0x0004);
	CDrawText("Uderzenia krytyczne -", { 124,25 + 5 }, 0x0004);
	CDrawText("(Zwiêksza szanse na silniejszy cios))", { 124,26 + 5 }, 0x0004);

	for (int i = 15; i > 0; i--)
	{
		ShowStats();
		CDrawText("Pozosta³e punkty: "+to_string(i)+" do rozdania.", { 124,20 }, 0x0002);
		switch (DrawMenu(s,{124,13}))
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
}

void Player::Bonus_stats_per_lvl()
{
	
	//cout << "Wbi³eœ nastêpny poziom! Mo¿esz dodaæ 2 punkty umiejêtnoœci." << endl;

	//X(1, 0x0002, "Wbi³eœ nastêpny poziom! Mo¿esz dodaæ 2 punkty umiejêtnoœci.");
	CDrawText("Wbi³eœ nastêpny poziom! Mo¿esz dodaæ 2 punkty umiejêtnoœci.", { 107,1 }, 0x0002);
	GetKey();

	ClearMapPlace();

	vector<string> s;
	s.push_back("Si³a");
	s.push_back("Zrêcznoœæ");
	s.push_back("Inteligencja");
	s.push_back("Celnoœæ");
	s.push_back("Uniki");
	s.push_back("Uderzenia krytyczne");

	for (int i = 2; i > 0; i--)
	{
		ShowStats();
		CDrawText("Pozosta³e punkty: "+to_string(i)+" do rozdania.", { 107,10 }, 0x0002);

		switch (DrawMenu(s, { 107,3 }))
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
	ShowStats();

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
	
	CDrawText("Ekwipunek", { 107,1 }, 0x000a);
	CDrawText("Posiadasz" + to_string(money) + "G", { 107, 2 }, 0x0003);

	if (inventory.size() > 0)
	{
		//cout << "Ekwipunek\t Pieni¹dze: " << money << endl;
		for (int i = 0; i < inventory.size(); i++)
		{
			s.push_back(inventory[i]->name);
		}
		s.push_back("Powrot");
		buf = DrawMenu(s, {107,4});
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
	else
	{
		CDrawText("Twók plecak jest pusty!", { 107, 4 }, 0x000c);
		_getch();
	}
	delete food;
}

void Player::ShowStats()	
{
	//ClearInfoPlace();
	CDrawText(name, { 124, 1 }, 0x0003);
	sex == 'm' ? CDrawText(L"\u2642", {(short) name.length() + 125, 1 }, 0x0003) : CDrawText(L"\u2640", { (short)name.length() + 108, 1 }, 0x0003);
	CDrawText("Poziom: " +to_string( level), {124, 2}, 0x0003);
	CDrawText("PD: " + to_string(xp), { 124,3 }, 0x0003);
	CDrawText("¯ycie: " + to_string(life) + '/' + to_string(lifeMax), { 124,4 }, 0x0003);
	CDrawText("Si³a: " + to_string(strength), { 124,5 }, 0x0003);
	CDrawText("Inteligencja: " + to_string(inteligence), { 124,6 }, 0x0003);
	CDrawText("Celnoœæ: " + to_string(accuracy), { 124,7 }, 0x0003);
	CDrawText("Zrêcznoœæ: " + to_string(agility), { 124,8 }, 0x0003);
	CDrawText("Uniki: "+ to_string(dodging), { 124,9 }, 0x0003);

	if (equipedWeapon != NULL)
		CDrawText("Broñ: " + equipedWeapon->name + " atak:" + to_string( equipedWeapon->strength), { 107, 10 }, 0x0003);
	else
		CDrawText("Brak broni", { 124, 10 }, 0x0001);


	if (equipedArmor != NULL)
		CDrawText("Pancerz: " + equipedArmor->name + " pancerz:" + to_string(equipedArmor->armor), { 107, 11 }, 0x0003);
	else
		CDrawText("Brak pancerza", { 124, 11 }, 0x0001);

	//_getch();
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
	else if (profession == 2)  //mag - leczenie
	{
	
		int healing;
		healing = 10 + (level * 3);
		if (life == lifeMax)
		{
			return 0;
		}

		if (life < lifeMax)
		{
			if ((life + healing) > lifeMax)
			{
				life = lifeMax;
				//cout << "Zosta³eœ uzdrowiony!" << endl;
				CDrawText("Zosta³eœ uzdrowiony!", { 107,12 },0x009 );
			}

			if ((life + healing) <= lifeMax)
			{
				life = life + healing;
				//cout << "Zosta³eœ uzdrowiony!" << endl;
				CDrawText("Zosta³eœ uzdrowiony!", { 107,12 },0x009 );
			}
		}
		return 0;
	}
	else if (profession == 3) // ³owca - losowe obrazenia z danego zakresu, roœnie z levelem
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
	if((crit_strike*3)>help) 
		return true;
}

bool Player::DodgeIs()
{
	int help = 1 + rand() % (100-1+1);
	if((dodging*3)>help) return true;
}

bool Player::AccIs()
{
	int help = 1 + rand() % (100 - 1 + 1);
	if (((dodging*2) +80) > help) return true;
}
