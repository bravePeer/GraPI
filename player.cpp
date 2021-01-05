#include "player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::CreateCharacter()
{
	cout << "Podaj imiê" << endl;
	cin >> name;

	do
	{
		cout << "Podaj p³eæ(m/k)" << endl;
		cin >> sex;
	} while ((sex != 'k') && (sex != 'm'));

	cout << "1 - Wojownik" << endl;
	cout << "2 - Mag" << endl;
	cout << "3 - £owca" << endl;
	cin >> profession;
	/*if (profession == 1) profession_name = "Wojownik";
	if (profession == 2) profession_name = "Mag";
	if (profession == 3) profession_name = "£owca";*/
	
	char pom;
	
	for (int i = 10; i > 0; i--)
	{
		system("cls");
		cout << "Rozdaj punkty umiejêtnoœci:" << endl;
		cout << "1 - Si³a" << endl;
		cout << "2 - Zrêcznoœæ" << endl;
		cout << "3 - Inteligencja" << endl;
		cout << "4 - Celnoœæ" << endl;
		cout << "5 - Uniki" << endl;
		cout << "6 - Uderzenia krytyczne" << endl;
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
}

void Player::ShowInventory()
{
	int buf = -1;
	Food *food = NULL;

	vector<string> s;

	if (inventory.size() > 0)
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			//cout << " " << inventory[i]->name << endl;
			s.push_back(inventory[i]->name);
		}
		s.push_back("Powrot");
		buf = DrawMenu(s);
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
				food = (Food*)inventory[buf];
				inventory[buf] = (Item*)equipedWeapon;
				equipedWeapon = (Weapon*)food;
			}
			else
			{
				equipedWeapon = (Weapon*)inventory[buf];
				inventory.erase(inventory.begin() + buf);
			}
			break;
		case 3://ubierz ubranko xd
			if (equipedWeapon != NULL)
			{
				food = (Food*)inventory[buf];
				inventory[buf] = (Item*)equipedArmor;
				equipedArmor = (Armor*)food;
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
		cout << "Nic nie masz w ekwipunku" << endl;
	}
	delete food;
}

void Player::Use(FunnyStruct& funnyStruct)
{
	


}
