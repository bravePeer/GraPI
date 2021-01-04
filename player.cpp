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

void Player::ShowInventory()
{
	for (auto a = inventory.begin(); a < inventory.size(); a++)
	{

	}
}
