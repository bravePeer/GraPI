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
	cout << "Wybierz klas� postaci:" << endl;
	cout << "1 - Wojownik (Umiej�tno�� specjalna: Aura Pancerza)" << endl;
	cout << "2 - Mag (Umiej�tno�� specjalna: Leczenie Ran)" << endl;
	cout << "3 - �owca (Umiej�tno�� specjalna: Deszcz Strza�)" << endl;
	cin >> pom;*/
	vector<string> s;
	s.push_back("Wojownik (Umiej�tno�� specjalna: Aura Pancerza)");
	s.push_back("Mag (Umiej�tno�� specjalna: Leczenie Ran)");
	s.push_back("�owca (Umiej�tno�� specjalna: Deszcz Strza�)");

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
		profession_name = "�owca";
		break;
	}
}

void Player::CreateCharacter()
{
	//cout << "Podaj imi�" << endl;
	CDrawText("Podaj imi� ", { 1,1 }, 0x0003);
	cin >> name;

	do
	{
		cout << "Podaj p�e�(m/k)" << endl;
		CDrawText("Podaj p�e�(m/k)", { 2,2 }, 0x0003);
		cin >> sex;
	} while ((sex != 'k') && (sex != 'm'));

	Select_profession();
	
	//char pom;
	vector<string> s;
	s.push_back("Si�a (Wp�ywa na obra�enia zadawne wrogom. Dobre dla wojownika)");
	s.push_back("Zr�czno�� (Wp�ywa na obra�enia zadawne wrogom. Dobre dla �owcy)");
	s.push_back("Inteligencja (Wp�ywa na obra�enia zadawne wrogom. Dobre dla maga)");
	s.push_back("Celno�� (Wp�ywa na to jak cz�sto twoje ataki trafiaj� w przeciwnika)");
	s.push_back("Uniki (Wp�ywa na to jak cz�sto unikniesz uderzenia przeciwnika)");
	s.push_back("Uderzenia krytyczne (Wp�ywa na to jak cz�sto b�dziesz atakowa� uderzeniem krytyczym)");

	for (int i = 15; i > 0; i--)
	{

		/*cout << "Rozdaj punkty umiej�tno�ci:" << endl;
		cout << "1 - Si�a (Wp�ywa na obra�enia zadawne wrogom. Dobre dla wojownika)" << endl;
		cout << "2 - Zr�czno�� (Wp�ywa na obra�enia zadawne wrogom. Dobre dla �owcy)" << endl;
		cout << "3 - Inteligencja (Wp�ywa na obra�enia zadawne wrogom. Dobre dla maga)" << endl;
		cout << "4 - Celno�� (Wp�ywa na to jak cz�sto twoje ataki trafiaj� w przeciwnika)" << endl;
		cout << "5 - Uniki (Wp�ywa na to jak cz�sto unikniesz uderzenia przeciwnika)" << endl;
		cout << "6 - Uderzenia krytyczne (Wp�ywa na to jak cz�sto b�dziesz atakowa� uderzeniem krytyczym)" << endl;
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
	cout << "Wbi�e� nast�pny poziom! Mo�esz doda� 2 punkty umiej�tno�ci." << endl;
	for (int i = 2; i > 0; i--)
	{
		system("cls");
		cout << "Rozdaj punkty umiej�tno�ci:" << endl;
		cout << "1 - Si�a (Wp�ywa na obra�enia zadawne wrogom. Dobre dla wojownika)" << endl;
		cout << "2 - Zr�czno�� (Wp�ywa na obra�enia zadawne wrogom. Dobre dla �owcy)" << endl;
		cout << "3 - Inteligencja (Wp�ywa na obra�enia zadawne wrogom. Dobre dla maga)" << endl;
		cout << "4 - Celno�� (Wp�ywa na to jak cz�sto twoje ataki trafiaj� w przeciwnika)" << endl;
		cout << "5 - Uniki (Wp�ywa na to jak cz�sto unikniesz uderzenia przeciwnika)" << endl;
		cout << "6 - Uderzenia krytyczne (Wp�ywa na to jak cz�sto b�dziesz atakowa� uderzeniem krytyczym)" << endl;
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
		cout << "Ekwipunek\t Pieni�dze: " << money << endl;
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
	cout << "�ycie: " << life << "/" << lifeMax << endl;
	cout << "Si�a: " << strength << endl;
	cout << "Inteligencja" << inteligence << endl;
	cout << "Celno��" << accuracy << endl;
	cout << "Zr�czno��" << agility << endl;
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
				cout << "Zosta�e� uzdrowiony!" << endl;
			}

			if ((life + healing) <= lifeMax)
			{
				life = life + healing;
				cout << "Zosta�e� uzdrowiony!" << endl;
			}
		}
		return 0;
	}
	else if (profession == 3) // �owca - losowe obrazenia z danego zakresu, ro�nie z levelem
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
