#include "player.h"

Player::Player()
{
}

Player::~Player()
{
	delete quest;
}

void Player::Select_profession()
{
	/*int pom;
	cout << "Wybierz klasê postaci:" << endl;
	cout << "1 - Wojownik (Umiejêtnoœæ specjalna: Aura Pancerza)" << endl;
	cout << "2 - Mag (Umiejêtnoœæ specjalna: Leczenie Ran)" << endl;
	cout << "3 - £owca (Umiejêtnoœæ specjalna: Deszcz Strza³)" << endl;
	cin >> pom;*/
	vector<string> s;
	s.push_back("Wojownik (Umiejêtnoœæ specjalna: Aura Pancerza)");
	s.push_back("Mag (Umiejêtnoœæ specjalna: Leczenie Ran)");
	s.push_back("£owca (Umiejêtnoœæ specjalna: Deszcz Strza³)");

	switch (DrawMenu(s, {0,1}))
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
	//cout << "Podaj imiê" << endl;
	CDrawText("Podaj imiê ", { 1,1 }, 0x0003);
	cin >> name;

	do
	{
		cout << "Podaj p³eæ(m/k)" << endl;
		CDrawText("Podaj p³eæ(m/k)", { 1,1 }, 0x0003);
		cin >> sex;
	} while ((sex != 'k') && (sex != 'm'));

	Select_profession();
	
	//char pom;
	vector<string> s;
	s.push_back("Si³a (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla wojownika)");
	s.push_back("Zrêcznoœæ (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla ³owcy)");
	s.push_back("Inteligencja (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla maga)");
	s.push_back("Celnoœæ (Wp³ywa na to jak czêsto twoje ataki trafiaj¹ w przeciwnika)");
	s.push_back("Uniki (Wp³ywa na to jak czêsto unikniesz uderzenia przeciwnika)");
	s.push_back("Uderzenia krytyczne (Wp³ywa na to jak czêsto bêdziesz atakowa³ uderzeniem krytyczym)");

	for (int i = 15; i > 0; i--)
	{
		ShowStats();
		/*cout << "Rozdaj punkty umiejêtnoœci:" << endl;
		cout << "1 - Si³a (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla wojownika)" << endl;
		cout << "2 - Zrêcznoœæ (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla ³owcy)" << endl;
		cout << "3 - Inteligencja (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla maga)" << endl;
		cout << "4 - Celnoœæ (Wp³ywa na to jak czêsto twoje ataki trafiaj¹ w przeciwnika)" << endl;
		cout << "5 - Uniki (Wp³ywa na to jak czêsto unikniesz uderzenia przeciwnika)" << endl;
		cout << "6 - Uderzenia krytyczne (Wp³ywa na to jak czêsto bêdziesz atakowa³ uderzeniem krytyczym)" << endl;
		cout << "Pozostalo ci " << i << " pkt do rozdania" << endl;*/

		//cin >> pom;
		switch (DrawMenu(s))
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
		//pom = '0';
	}
}

void Player::Bonus_stats_per_lvl()
{
	
	//cout << "Wbi³eœ nastêpny poziom! Mo¿esz dodaæ 2 punkty umiejêtnoœci." << endl;

	X(1, 0x0002, "Wbi³eœ nastêpny poziom! Mo¿esz dodaæ 2 punkty umiejêtnoœci.");
	GetKey();

	ClearMapPlace();

	vector<string> s;
	s.push_back("Si³a (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla wojownika)");
	s.push_back("Zrêcznoœæ (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla ³owcy)");
	s.push_back("Inteligencja (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla maga)");
	s.push_back("Celnoœæ (Wp³ywa na to jak czêsto twoje ataki trafiaj¹ w przeciwnika)");
	s.push_back("Uniki (Wp³ywa na to jak czêsto unikniesz uderzenia przeciwnika)");
	s.push_back("Uderzenia krytyczne (Wp³ywa na to jak czêsto bêdziesz atakowa³ uderzeniem krytyczym)");

	for (int i = 2; i > 0; i--)
	{
		X(-1, 0x0002, "Pozosta³e punkty:   do wydania.");
		CDrawText(to_string(i), { 55,28 }, 0x0002);
		ShowStats();
		
		/*cout << "Rozdaj punkty umiejêtnoœci:" << endl;
		cout << "1 - Si³a (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla wojownika)" << endl;
		cout << "2 - Zrêcznoœæ (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla ³owcy)" << endl;
		cout << "3 - Inteligencja (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla maga)" << endl;
		cout << "4 - Celnoœæ (Wp³ywa na to jak czêsto twoje ataki trafiaj¹ w przeciwnika)" << endl;
		cout << "5 - Uniki (Wp³ywa na to jak czêsto unikniesz uderzenia przeciwnika)" << endl;
		cout << "6 - Uderzenia krytyczne (Wp³ywa na to jak czêsto bêdziesz atakowa³ uderzeniem krytyczym)" << endl;
		cout << "Pozostalo ci " << i << " pkt do rozdania" << endl;*/

		//cin >> pom;
		switch (DrawMenu(s, { 20, 3 }))
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
	ClearInfoPlace();
	CDrawText(name, { 107, 1 }, 0x0003);
	sex == 'm' ? CDrawText(L"\u2642", {(short) name.length() + 108, 1 }, 0x0003) : CDrawText(L"\u2640", { (short)name.length() + 108, 1 }, 0x0003);
	CDrawText("Poziom: " +to_string( level), {107, 2}, 0x0003);
	CDrawText("PD: " + to_string(xp), { 107,3 }, 0x0003);
	CDrawText("¯ycie: " + to_string(life) + '/' + to_string(lifeMax), { 107,4 }, 0x0003);
	CDrawText("Si³a: " + to_string(strength), { 107,5 }, 0x0003);
	CDrawText("Inteligencja: " + to_string(inteligence), { 107,6 }, 0x0003);
	CDrawText("Celnoœæ: " + to_string(accuracy), { 107,7 }, 0x0003);
	CDrawText("Zrêcznoœæ: " + to_string(agility), { 107,8 }, 0x0003);
	CDrawText("Uniki: "+ to_string(dodging), { 107,9 }, 0x0003);
/*	cout << name << " poziom:" << level << " punkty doswiadczenia: " << xp << endl << endl;
	cout << "¯ycie: " << life << "/" << lifeMax << endl;
	cout << "Si³a: " << strength << endl;
	cout << "Inteligencja" << inteligence << endl;
	cout << "Celnoœæ" << accuracy << endl;
	cout << "Zrêcznoœæ" << agility << endl;
	cout << "Uniki" << dodging << endl;*/

	if (equipedWeapon != NULL)
		CDrawText("Broñ: " + equipedWeapon->name + " atak:" + to_string( equipedWeapon->strength), { 107, 10 }, 0x0003);
	else
		CDrawText("Brak broni", { 107, 10 }, 0x0001);


	if (equipedArmor != NULL)
		CDrawText("Pancerz: " + equipedArmor->name + " pancerz:" + to_string(equipedArmor->armor), { 107, 11 }, 0x0003);
	else
		CDrawText("Brak pancerza", { 107, 11 }, 0x0001);

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
	if (quest != NULL)
	{
		cout << quest->name << endl;
	}
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
