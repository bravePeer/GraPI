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
	int pom;
	cout << "Wybierz klas� postaci:" << endl;
	cout << "1 - Wojownik" << endl;
	cout << "2 - Mag" << endl;
	cout << "3 - �owca" << endl;
	cin >> pom;
	if (pom == 1)
	{
		profession = 1;
		profession_name = "Wojownik";
	}
	else if (pom == 2)
	{
		profession = 2;
		profession_name = "Mag";
	}
	else if (pom == 3)
	{
		profession = 3;
		profession_name = "�owca";
	}

}

void Player::CreateCharacter()
{
	cout << "Podaj imi�" << endl;
	cin >> name;

	do
	{
		cout << "Podaj p�e�(m/k)" << endl;
		cin >> sex;
	} while ((sex != 'k') && (sex != 'm'));

	Select_profession();
	
	char pom;
	
	for (int i = 15; i > 0; i--)
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

int Player::Spell()
{
	if (profession == 1) // wojownik - wzmocnienie miecza i armora na ile� tam tur !!!!!!!!!!! do poprawy
	{
		/*int i = tura + 2;
		armor = armor + (5 * level);
		dmg_output = dmg_output + (6 * level);
		cout << "Twoje statystyki zosta�y zwi�kszonedo ko�ca walki!" << endl;
		
		return 0;*/
	}
	else if (profession == 2)  //mag - leczenie
	{
		int healing;
		healing = 30 + (level * 5);
		if (life == lifeMax) cout << "Jeste� w pe�ni zdrowy!" << endl;
		else if (life < lifeMax)
		{
			if ((life + healing) > lifeMax)
			{
				life = lifeMax;
				cout << "Zosta�e� uzdrowiony!" << endl;
			}
			else if ((life + healing) <= lifeMax)
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
		pom = (10 + (level * 5)) + rand() % ((40 + (level * 5)) - (10 + (level * 5)) + 1);
		return pom;
	}
}

int Player::Dmg_formula()
{
	if (profession == 1)
	{
		dmg_output = (0.6 * strength * 7)  + (0.4 * agility * 5) + (0.2 * inteligence * 3) + (level * 5);
		return dmg_output;
	}
	if (profession == 2)
	{
		dmg_output = (0.6 * inteligence * 7) + (0.4 * agility * 5) + (0.2 * strength * 3) + (level * 5);
		return dmg_output;
	}
	if (profession == 3)
	{
		dmg_output = (0.6 * agility * 7) + (0.4 * strength * 5) + (0.2 * inteligence * 3) + (level * 5);
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
