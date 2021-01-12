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

	switch (DrawMenu(s))
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
		CDrawText("Podaj p³eæ(m/k)", { 2,2 }, 0x0003);
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
	int pom;
	cout << "Wbi³eœ nastêpny poziom! Mo¿esz dodaæ 2 punkty umiejêtnoœci." << endl;
	for (int i = 2; i > 0; i--)
	{
		system("cls");
		cout << "Rozdaj punkty umiejêtnoœci:" << endl;
		cout << "1 - Si³a (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla wojownika)" << endl;
		cout << "2 - Zrêcznoœæ (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla ³owcy)" << endl;
		cout << "3 - Inteligencja (Wp³ywa na obra¿enia zadawne wrogom. Dobre dla maga)" << endl;
		cout << "4 - Celnoœæ (Wp³ywa na to jak czêsto twoje ataki trafiaj¹ w przeciwnika)" << endl;
		cout << "5 - Uniki (Wp³ywa na to jak czêsto unikniesz uderzenia przeciwnika)" << endl;
		cout << "6 - Uderzenia krytyczne (Wp³ywa na to jak czêsto bêdziesz atakowa³ uderzeniem krytyczym)" << endl;
		cout << "Pozostalo ci " << i << " pkt do rozdania" << endl;
		cin >> pom;
		switch (pom)
		{
		case'1':
			strength++;
			break;

		case'2':
			inteligence++;
			break;

		case'3':
			agility++;
			break;

		case'4':
			accuracy++;
			break;

		case'5':
			dodging++;
			break;

		case'6':
			crit_strike++;
			break;

		default:
			i++;
			break;
		}
		pom = '0';
	}
}

void Player::UsePreset()
{
	name = "Prefab Testwy";
	lifeMax = 100;
	life = lifeMax;
	profession = 1;
}

void Player::ShowInventory()
{
	int buf = -1;
	Food *food = NULL;
	Weapon* weapon = NULL;
	Armor* armor = NULL;

	vector<string> s;

	if (inventory.size() > 0)
	{
		cout << "Ekwipunek\t Pieni¹dze: " << money << endl;
		for (int i = 0; i < inventory.size(); i++)
		{
			s.push_back(inventory[i]->name);
		}
		s.push_back("Powrot");
		buf = DrawMenu(s, {5,5});
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
		cout << "Nic nie masz w ekwipunku!" << endl;
		_getch();
	}
	delete food;
}

void Player::ShowStats()	
{
	cout << name << " poziom:" << level << " punkty doswiadczenia: " << xp << endl << endl;
	cout << "¯ycie: " << life << "/" << lifeMax << endl;
	cout << "Si³a: " << strength << endl;
	cout << "Inteligencja" << inteligence << endl;
	cout << "Celnoœæ" << accuracy << endl;
	cout << "Zrêcznoœæ" << agility << endl;
	cout << "Uniki" << dodging << endl;

	if (equipedWeapon != NULL)
		cout << "Bron: " << equipedWeapon->name <<" atak:"<< equipedWeapon->strength<< endl;
	else
		cout << "Brak broni" << endl;

	if (equipedArmor != NULL)
		cout << "Pancerz: " << equipedArmor->name <<" pancerz: " << equipedArmor->armor<< endl;
	else
		cout << "Brak pancerza" << endl;
	_getch();
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
				cout << "Zosta³eœ uzdrowiony!" << endl;
			}

			if ((life + healing) <= lifeMax)
			{
				life = life + healing;
				cout << "Zosta³eœ uzdrowiony!" << endl;
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
